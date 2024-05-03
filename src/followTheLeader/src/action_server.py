import time

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import Maze

from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
import numpy as np
import math

gStartTime = time.time_ns()

def MyPrint(str):
    deltaTime = time.time_ns() - gStartTime
    secs = int(deltaTime / 1000000000.0)
    msecs = int((deltaTime - secs * 1000000000.0) / 1000000)
    print(f"{secs:03d}.{msecs:03d} {str}\r")
    
def quaternion_to_euler_degrees(q):
    e = np.empty((3, ))

    t0 = 2.0 * (q[3]*q[0] + q[1]*q[2])
    t1 = 1.0 - 2.0 * (q[0]*q[0] + q[1]*q[1])
    e[0] = np.degrees(np.arctan2(t0, t1))
    
    t2 = 2.0 * (q[3]*q[1] - q[2]*q[0])
    t2 = 1.0 if t2 > 1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    e[1] = np.degrees(np.arcsin(t2))
    
    t3 = 2.0 * (q[3]*q[2] + q[0]*q[1])
    t4 = 1.0 - 2.0 * (q[1]*q[1] + q[2]*q[2])
    e[2] = np.degrees(np.arctan2(t3, t4))
    
    return e

class RabbitOdom(Node):
    def __init__(self):
        super().__init__('rabbit_odom')
        self.odom_red = self.create_subscription(Odometry, "/odom_rabbit_red", self.process_odom_red, 10)
        self.odom_green = self.create_subscription(Odometry, "/odom_rabbit_green", self.process_odom_green, 10)
        self.odom_blue = self.create_subscription(Odometry, "/odom_rabbit_blue", self.process_odom_blue, 10)
        MyPrint('Rabbit Odometry Subscriber ready... ')

    def process_odom_red(self, message):
        # Track red rabbit position...
        self.red_pose = message.pose.pose.position
        if sInfo.index == 0:
            sInfo.goal_x = self.red_pose.x
            sInfo.goal_y = self.red_pose.y
        return
        
    def process_odom_green(self, message):
        # Track green rabbit position...
        self.green_pose = message.pose.pose.position
        if sInfo.index == 1:
            sInfo.goal_x = self.green_pose.x
            sInfo.goal_y = self.green_pose.y
        return
        
    def process_odom_blue(self, message):
        # Track blue rabbit position...
        self.blue_pose = message.pose.pose.position
        if sInfo.index == 2:
            sInfo.goal_x = self.blue_pose.x
            sInfo.goal_y = self.blue_pose.y
        return
        
class ChaseOdom(Node):
    def __init__(self):
        super().__init__('chase_odom')
        self.odom_subscriber = self.create_subscription(Odometry, "/odom_chase", self.process_odom, 10)
        self.cmd_vel_publisher = self.create_publisher(Twist, "/cmd_vel_chase", 10)
        MyPrint('Chase Odometry Subscriber ready... ')

    def process_odom(self, message):
        vel_msg = Twist()
        q = np.empty((4, ))
        while sInfo.distance > 0.5:
                self.current_pose = message.pose.pose
                xdist_to_goal = sInfo.goal_x - self.current_pose.position.x
                ydist_to_goal = sInfo.goal_y - self.current_pose.position.y
                q[0] = message.pose.pose.orientation.x
                q[1] = message.pose.pose.orientation.y
                q[2] = message.pose.pose.orientation.z
                q[3] = message.pose.pose.orientation.w
                v = quaternion_to_euler_degrees(q)
                sInfo.direction = v[2] * math.pi/180
                xdist_to_goal = sInfo.goal_x - self.current_pose.position.x
                ydist_to_goal = sInfo.goal_y - self.current_pose.position.y
                
                sInfo.distance =  math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
                goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
                angle_error = sInfo.ka * math.atan2(math.sin((goal_angle - sInfo.direction)),math.cos((goal_angle - sInfo.direction)))
                vel_msg.angular.z = angle_error
                if angle_error > 0.2:
                    vel_msg.angular.z = sInfo.ka
                    vel_msg.linear.x = sInfo.kv * (sInfo.distance + 1.0)

                if angle_error < -0.2:
                    vel_msg.angular.z = -sInfo.ka
                    vel_msg.linear.x = sInfo.kv * (sInfo.distance + 1.0)

                self.cmd_vel_publisher.publish(vel_msg)
        sInfo.isGoal = True
        return

class MyActionServer(Node):
    def __init__(self):
        super().__init__('action_server')
        self._action_server = ActionServer( 
            self,
            Maze,
            'maze',
            self.execute_callback)
        MyPrint('ActionServer ready... ')

    def execute_callback(self, goal_handle):
        sInfo.index = goal_handle.request.index
        while sInfo.isGoal == False:
            # Provide feedback messages...
            feedback_msg = Maze.Feedback()
            feedback_msg.index = sInfo.index
            feedback_msg.distance = sInfo.distance
            feedback_msg.direction = int(sInfo.direction)
            goal_handle.publish_feedback(feedback_msg)
        
        
        # Provide result message...
        sInfo.isGoal = True
        goal_handle.succeed()
        result = Maze.Result()
        result.index = sInfo.index
        result.distance = sInfo.distance
        return result
    
class sInfo:
    index = 0
    distance = 1.0
    direction = 0.0
    kv = 1.5
    ka = 1.5
    goal_x = 0.0
    goal_y = 0.0
    isGoal = False

def main(args=None):
    rclpy.init(args=args)
    action_server = MyActionServer()
    rabbit_odom = RabbitOdom()
    chase_odom = ChaseOdom()
    
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(action_server)
    executor.add_node(rabbit_odom)
    executor.add_node(chase_odom)

    try:
        executor.spin()
    except KeyboardInterrupt:
        print("\nKeyboardInterrupt...")
        
if __name__ == '__main__':
    main()
