#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

class TurtlesimCirclesNode(Node):
    def __init__(self):
        super().__init__("turtlesim_circles")
        self.goal_x = 0.0
        self.goal_y = 0.0
        self.pose_ = None
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        if self.pose_ != None:
            self.goal_x = self.pose_.x
            self.goal_y = self.pose_.y
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.9, self.turtle_move)
    
    def get_turtle_pose(self,msg):
        self.pose_ = msg
        
    def turtle_move(self):
        if self.pose_ == None:
            return
        vel_msg = Twist()
        vel_msg.angular.z = (2*math.pi)/5
        vel_msg.linear.x = math.pi
        self.cmd_vel_publisher_.publish(vel_msg)
        self.get_logger().info('Angular velocity published: ' + str(vel_msg.angular.z))
        self.get_logger().info('Linear velocity published: ' + str(vel_msg.linear.x))
        
def main(args=None):
    rclpy.init(args=args)
    node = TurtlesimCirclesNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()