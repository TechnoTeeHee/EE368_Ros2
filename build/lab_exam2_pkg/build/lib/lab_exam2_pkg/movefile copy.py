#!/usr/bin/env python3
import rclpy
import random
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from sensor_msgs.msg import LaserScan

class MoveFileNode(Node):
    def __init__(self):
        super().__init__("movefile")
        self.goal_x = random.uniform(1,10)
        self.goal_y = random.uniform(1,10)
        self.get_logger().info('x goal: ' + str(self.goal_x))
        self.get_logger().info('y goal: ' + str(self.goal_y))
        self.pose_ = None
        self.scan_ = None
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        self.scan_subscriber_ = self.create_subscription(LaserScan, "scan", self.get_scan, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.01, self.turtle_move)
        
    
    def get_scan(self, msg):
        self.scan_ = min(msg.ranges)

            
    def get_turtle_pose(self,msg):
        self.pose_ = msg
        
    def turtle_move(self):
        if self.pose_ == None or self.scan_ == None:
            return
        xdist_to_goal = self.goal_x - self.scan_
        ydist_to_goal = self.goal_y - self.pose_.y
        dist_to_goal = math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
        kv = 2
        ka = 7
        vel_msg = Twist()
        if dist_to_goal > 0.2:
            vel_msg.linear.x = kv*dist_to_goal
            goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
            angle_error = goal_angle - self.pose_.theta
            angle_error = math.atan2(math.sin(angle_error),math.cos(angle_error))
            vel_msg.angular.z = ka*angle_error
            self.get_logger().info('x dist to goal: ' + str(xdist_to_goal))
            self.get_logger().info('x: ' + str(self.pose_.x))
            self.get_logger().info('x scan: ' + str(self.scan_))
            self.cmd_vel_publisher_.publish(vel_msg)
        else:
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
        
def main(args=None):
    rclpy.init(args=args)
    node = MoveFileNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()