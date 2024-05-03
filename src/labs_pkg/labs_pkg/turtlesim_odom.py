#! /usr/bin/env python3
# turtlesim_odom.py
# created by Brian Daku
from math import cos, sin
import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from nav_msgs.msg import Odometry

class TurtlesimOdom(Node):
    def __init__(self):
        super().__init__("turtlesim_odom")
        self.pose_subscriber_ = self.create_subscription(
            Pose,
            "/turtle1/pose",
            self.publish_odom,
            10)
        self.odom_publisher_ = self.create_publisher(Odometry, "odom", 10)
        self.get_logger().info("Publisher is ready")

    def publish_odom(self, msg):
        odom_msg = Odometry()
        odom_msg.pose.pose.position.x = msg.x
        odom_msg.pose.pose.position.y = msg.y
        odom_msg.pose.pose.orientation.z = sin(msg.theta/2)
        odom_msg.pose.pose.orientation.w = cos(msg.theta/2)
        odom_msg.twist.twist.linear.x = msg.linear_velocity
        odom_msg.twist.twist.angular.z = msg.angular_velocity
        self.odom_publisher_.publish(odom_msg)

    
def main(args=None):
    rclpy.init(args=args)
    node = TurtlesimOdom()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()