#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist

class Tb4CirclesNode(Node):
    def __init__(self):
        super().__init__("tb4_circles")
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.02, self.move)
        
    def move(self):
        vel_msg = Twist()
        vel_msg.angular.z = (2*math.pi)/5
        vel_msg.linear.x = ((2*math.pi)/5)*0.5
        self.cmd_vel_publisher_.publish(vel_msg)

        
def main(args=None):
    rclpy.init(args=args)
    node = Tb4CirclesNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()