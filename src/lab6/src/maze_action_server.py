import time
import rclpy
import math
from math import floor
import numpy as np
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import Maze
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from rosgraph_msgs.msg import Clock

class MazeActionServer(Node):
    def __init__(self):
        super().__init__('maze_action_server')
        self._action_server = ActionServer(
            self,
            Maze,
            'maze',
            self.execute_callback)
        self.get_logger().info('MazeActionServer ready... ')
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "/cmd_vel", 10)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        feedback_msg = Maze.Feedback()

        for i in range(0,floor(len(goal_handle.request.goal_positions)/2)):
            j = 2*i+1
            v = 2*i
            self.goal_x = goal_handle.request.goal_positions[v]
            self.goal_y = goal_handle.request.goal_positions[j]

            while info.have_goal == False or info.time_offset == 0.0:
                time.sleep(0.01)
            info.goal_reached = 0
            feedback_msg.goal_num = info.goal_num
            feedback_msg.goal_reached = info.goal_reached
            feedback_msg.current_goal = [self.goal_x, self.goal_y]
            goal_handle.publish_feedback(feedback_msg)


            xdist_to_goal = self.goal_x - info.current_x
            ydist_to_goal = self.goal_y - info.current_y
            dist_to_goal =  math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
            vel_msg = Twist()
            while dist_to_goal > 0.5:
                if (info.time - info.old_time) > 1:
                    info.goal_reached = 1
                    feedback_msg.current_x = info.current_x
                    feedback_msg.current_y = info.current_y
                    feedback_msg.yaw = info.yaw
                    feedback_msg.time = info.time
                    feedback_msg.goal_reached = info.goal_reached
                    goal_handle.publish_feedback(feedback_msg)
                    info.old_time = info.time


                xdist_to_goal = self.goal_x - info.current_x
                ydist_to_goal = self.goal_y - info.current_y
                dist_to_goal =  math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)


                vel_msg.linear.x = info.kv * dist_to_goal
                goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
                angle_error = (goal_angle - info.yaw)
                angle_error = info.ka * math.atan2(math.sin(angle_error),math.cos(angle_error))
                vel_msg.angular.z = angle_error

                if angle_error > 0.2:
                    vel_msg.angular.z = 1.5
                    vel_msg.linear.x = 0.0

                if angle_error < -0.2:
                    vel_msg.angular.z = -1.5
                    vel_msg.linear.x = 0.0

                self.cmd_vel_publisher_.publish(vel_msg)

            
            info.goal_num = info.goal_num + 1


        goal_handle.succeed()
        info.complete = 1.0
        result = Maze.Result()
        result.final_time = feedback_msg.time
        return result
    
class info:
    kv = 1.5
    ka = 1.0
    current_x = 0.0
    current_y = 0.0
    yaw = 0.0
    goal_num = 0
    time = 0.0
    old_time = -1.0
    goal_reached = -1
    time_offset = 0.0
    complete = 0.0
    have_goal = False


class Odometrysubscriber(Node):
    def __init__(self):
        super().__init__('Odometry')
        self.odom_subscriber_ = self.create_subscription(Odometry, "/odom", self.get_position, 10)
        self.get_logger().info('Odometry ready... ')

    def get_position(self,msg):
        info.current_x = msg.pose.pose.position.x
        info.current_y = msg.pose.pose.position.y
        q = np.empty((4, ))
        q[0] = msg.pose.pose.orientation.x
        q[1] = msg.pose.pose.orientation.y
        q[2] = msg.pose.pose.orientation.z
        q[3] = msg.pose.pose.orientation.w
        v = self.Quarternion_to_euler(q)
        info.yaw = v[2] * math.pi/180
        info.have_goal = True


    def Quarternion_to_euler(self, q):
        e = np.empty((3, ))
        t0 = 2.0 * (q[3]*q[0] + q[1]*q[2])
        t1 = 1.0 - 2.0 * (q[0]*q[0] + q[1]*q[1])
        e[0] = np.degrees(np.arctan2(t0,t1))
        t2 = 2.0 * (q[3]*q[1] - q[2]*q[0])
        t2 = 1.0 if t2 > 1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        e[1] = np.degrees(np.arcsin(t2))
        t3 = 2.0 * (q[3]*q[2] + q[0]*q[1])
        t4 = 1.0 - 2.0 * (q[1]*q[1] + q[2]*q[2])
        e[2] = np.degrees(np.arctan2(t3,t4))
        return e
    
class Clocksubscriber(Node):
    def __init__(self):
        super().__init__('Clock')
        self.odom_subscriber_ = self.create_subscription(Clock, "/clock", self.get_time, 10)
        self.get_logger().info('Clock ready... ')
        self.seconds = -1

    def get_time(self, msg):
        gazebo_time = float(msg.clock.sec) + float(msg.clock.nanosec/1000000000)

        if info.time_offset == 0.0:
            info.time_offset = gazebo_time

        if msg.clock.sec != self.seconds or info.complete == 1:
            info.time = gazebo_time - info.time_offset
            self.seconds = msg.clock.sec
        


def main(args=None):
    rclpy.init(args=args)
    maze_action_server = MazeActionServer()
    odom_subscriber = Odometrysubscriber()
    clock_subscriber = Clocksubscriber()
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(maze_action_server)
    executor.add_node(odom_subscriber)
    executor.add_node(clock_subscriber)
    try:
        executor.spin()
    except KeyboardInterrupt:
        print("\nKeyboardInterrupt...")

if __name__ == '__main__':
    main()