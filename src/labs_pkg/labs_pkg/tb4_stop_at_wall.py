#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

class Tb4StopAtWallNode(Node):
    def __init__(self):
        super().__init__("tb4_stop_at_wall")
        self.scan_subscriber_ = self.create_subscription(LaserScan, "scan", self.get_scan, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.1, self.move)
        self.scan_ = 0.0

    def get_scan(self, msg):
        self.scan_ = msg.ranges[270]
        
    def move(self):
        if self.scan_ == None:
            return
        vel_msg = Twist()
        vel_msg.angular.z = 0.0
        if (self.scan_ > 1.0):
            vel_msg.linear.x = 0.3
        elif (self.scan_ <= 1.0 and self.scan_ > 0.5):
            vel_msg.linear.x = (self.scan_-0.5)/3
        elif (self.scan_ <= 0.5):
            vel_msg.linear.x = 0.0
        self.cmd_vel_publisher_.publish(vel_msg)

        
def main(args=None):
    rclpy.init(args=args)
    node = Tb4StopAtWallNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()