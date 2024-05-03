#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose


class TurtlesimMoveNode(Node):
    def __init__(self):
        super().__init__("turtlesim_move")
        self.goal_x = 2.0
        self.goal_y = 4.0
        self.pose_ = None
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(1.1, self.turtle_move)
    
    def get_turtle_pose(self,msg):
        self.pose_ = msg
        
    def turtle_move(self):
        if self.pose_ == None:
            return
        xdist_to_goal = self.goal_x - self.pose_.x
        ydist_to_goal = self.goal_y - self.pose_.y
        dist_to_goal = math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
        vel_msg = Twist()
        if dist_to_goal > 0.2:
            vel_msg.linear.x = dist_to_goal
            goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
            angle_error = goal_angle - self.pose_.theta
            angle_error = math.atan2(math.sin(angle_error),math.cos(angle_error))
            vel_msg.angular.z = angle_error
        else:
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
        
        self.cmd_vel_publisher_.publish(vel_msg)
        self.get_logger().info('Angular velocity published: ' + str(vel_msg.angular.z))
        self.get_logger().info('Linear velocity published: ' + str(vel_msg.linear.x))
        
def main(args=None):
    rclpy.init(args=args)
    node = TurtlesimMoveNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()