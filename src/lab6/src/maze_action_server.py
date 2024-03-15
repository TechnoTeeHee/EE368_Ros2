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

class sInfo:
    have_goal = False
    goal_x = 0.0
    goal_y = 0.0
    time = 0.0
    stored_time = -1.0
    kv = 1.5
    ka = 1.5
    x = 0.0
    y = 0.0
    z = 0.0
    goal_update = False
    time_offset = 0.0
    n_goal = 0
    complete = False

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

        for i in range(0,len(goal_handle.request.goal_coordinates),2):
            j = i+1
            sInfo.goal_x = goal_handle.request.goal_coordinates[i]
            sInfo.goal_y = goal_handle.request.goal_coordinates[j]

            while sInfo.have_goal == False or sInfo.time_offset == 0.0:
                time.sleep(0.01)
            sInfo.goal_update = True
            feedback_msg.n_goal = sInfo.n_goal
            feedback_msg.goal_update = sInfo.goal_update
            feedback_msg.current_goal = [sInfo.goal_x, sInfo.goal_y]
            goal_handle.publish_feedback(feedback_msg)


            xdist_to_goal = sInfo.goal_x - sInfo.x
            ydist_to_goal = sInfo.goal_y - sInfo.y
            dist_to_goal =  math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
            vel_msg = Twist()
            while dist_to_goal > 0.5:
                xdist_to_goal = sInfo.goal_x - sInfo.x
                ydist_to_goal = sInfo.goal_y - sInfo.y
                dist_to_goal =  math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)


                vel_msg.linear.x = sInfo.kv * (dist_to_goal + 1.0)
                goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
                angle_error = sInfo.ka * math.atan2(math.sin((goal_angle - sInfo.z)),math.cos((goal_angle - sInfo.z)))
                vel_msg.angular.z = angle_error

                if angle_error > 0.2:
                    vel_msg.angular.z = sInfo.ka
                    vel_msg.linear.x = 0.0

                if angle_error < -0.2:
                    vel_msg.angular.z = -sInfo.ka
                    vel_msg.linear.x = 0.0

                self.cmd_vel_publisher_.publish(vel_msg)
                
                if (sInfo.time - sInfo.stored_time) > 1:
                    feedback_msg.x = sInfo.x
                    feedback_msg.y = sInfo.y
                    feedback_msg.z = sInfo.z
                    feedback_msg.time = sInfo.time
                    sInfo.goal_update = False
                    feedback_msg.goal_update = sInfo.goal_update
                    goal_handle.publish_feedback(feedback_msg)
                    sInfo.stored_time = sInfo.time
                    
            sInfo.n_goal = sInfo.n_goal + 1


        goal_handle.succeed()
        sInfo.complete = True
        result = Maze.Result()
        result.goal_time = feedback_msg.time
        return result

class Odometrysubscriber(Node):
    def __init__(self):
        super().__init__('Odometry')
        self.odom_subscriber_ = self.create_subscription(Odometry, "/odom", self.get_position, 10)

    def get_position(self,msg):
        sInfo.x = msg.pose.pose.position.x
        sInfo.y = msg.pose.pose.position.y
        q = np.empty((4, ))
        q[0] = msg.pose.pose.orientation.x
        q[1] = msg.pose.pose.orientation.y
        q[2] = msg.pose.pose.orientation.z
        q[3] = msg.pose.pose.orientation.w
        v = self.Quarternion_to_euler(q)
        sInfo.z = v[2] * math.pi/180
        sInfo.have_goal = True


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
        self.seconds = 0

    def get_time(self, msg):
        gazebo_time = float(msg.clock.sec) + float(msg.clock.nanosec/1000000000)

        if sInfo.time_offset == 0.0:
            sInfo.time_offset = gazebo_time

        if msg.clock.sec != self.seconds or sInfo.complete:
            sInfo.time = gazebo_time - sInfo.time_offset
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