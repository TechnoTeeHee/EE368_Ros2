#! /usr/bin/env python3
from math import tan, cos, pi
import math
import rclpy
from rclpy.node import Node
import numpy as np
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

class testNode(Node):
    def __init__(self):
        super().__init__("test")
        self.distance = 12
        self.pose_subscriber_ = self.create_subscription(LaserScan, "scan", self.get_distance, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "cmd_vel", 10)
        self.move_timer_ = self.create_timer(.01, self.robot_move)
        self.state = 1

    def get_distance(self,msg):
        self.distance = min(msg.ranges)
        self.back_corner_dist = msg.ranges[45]
        self.front_corner_dist = msg.ranges[135]
        self.right_side = msg.ranges[90]

    def robot_move(self):
        vel_msg = Twist()
        if (self.distance > 0.7 and self.state == 1):
            vel_msg.linear.x = 0.4 * (self.distance - 0.65)
        elif (self.state == 1):
            self.state = 2

        if (self.state == 2):
            if (self.right_side > 0.7):
                vel_msg.angular.z = 1.0
            elif(self.right_side != self.distance and self.right_side < 0.72):
                vel_msg.angular.z = 0.8 * (self.right_side - 0.65)
            else:
                self.state = 3
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = 0.0

        if (self.state == 3):
            vel_msg.linear.x = 0.3
            if (0.699 > self.right_side or self.right_side > 0.701):
                vel_msg.angular.z = 0.6 * (0.7 - self.right_side)

            if(self.right_side == np.inf):
                self.state = 4
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = 0.0

        if (self.state == 4):
            if (self.distance < math.sqrt(0.7**2 + 0.7**2)):
                vel_msg.linear.x  = 0.3
                
            else:
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = -0.2
                if (self.front_corner_dist == self.distance):
                    self.state = 5

        if (self.state == 5):
            vel_msg.linear.x = 0.2
            vel_msg.angular.z = 0.0
            if (self.right_side < 1):
                self.state = 3

        self.cmd_vel_publisher_.publish(vel_msg)


def main(args=None):
    rclpy.init(args=args)
    node = testNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()