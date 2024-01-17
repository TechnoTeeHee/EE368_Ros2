#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from sensor_msgs.msg import LaserScan

class TurtlesimStopAtWallNode(Node):
    def __init__(self):
        super().__init__("turtlesim_stop_at_wall")
        self.goal_x = 0.0
        self.goal_y = 0.0
        self.pose_ = None
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        self.scan_subscriber_ = self.create_subscription(LaserScan, "scan", self.get_scan, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.1, self.turtle_move)

    def get_scan(self, msg):
        self.scan_ = msg.ranges[0]

    def get_turtle_pose(self, msg):
        self.pose_ = msg
        
    def turtle_move(self):
        if self.pose_ == None:
            return
        vel_msg = Twist()

        vel_msg.angular.z = 0.0
        if (self.scan_ > 1.0):
            vel_msg.linear.x = 1.0
        elif (self.scan_ <= 1.0 and self.scan_ > 0.5):
            vel_msg.linear.x = self.scan_-0.5
        elif (self.scan_ <= 0.5):
            vel_msg.linear.x = 0.0
        self.cmd_vel_publisher_.publish(vel_msg)
        self.get_logger().info('x: ' + str(self.pose_.x))
        self.get_logger().info('y: ' + str(self.pose_.y))

        
def main(args=None):
    rclpy.init(args=args)
    node = TurtlesimStopAtWallNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()