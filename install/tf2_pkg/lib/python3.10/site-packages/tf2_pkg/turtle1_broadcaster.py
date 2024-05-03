#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
import numpy as np
from turtlesim.msg import Pose
from math import pi, sin, cos
from geometry_msgs.msg import TransformStamped

class Turtle1Broadcaster(Node):
    def __init__(self):
        super().__init__("turtle1_broadcaster")
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        self.turtle1_broadcaster = tf2_ros.TransformBroadcaster(self)
        self.pose = None
        self.broadcast_tf_message()
        self.timer = self.create_timer(0.1, self.broadcast_tf_message)
        self.get_logger().info("turtle1_broadcaster is ready")
        
    def get_turtle_pose(self, msg):
        self.pose = msg
        
    def broadcast_tf_message(self):
        if self.pose == None:
            return
        self.transform_stamped = TransformStamped()
        self.transform_stamped.header.frame_id = "world"
        self.transform_stamped.child_frame_id = "turtle1"
        self.transform_stamped.header.stamp = self.get_clock().now().to_msg()
        self.transform_stamped.transform.translation.x = self.pose.x
        self.transform_stamped.transform.translation.y = self.pose.y
        q = euler_to_quaternion(0, 0, self.pose.theta)
        self.transform_stamped.transform.rotation.x = q[0]
        self.transform_stamped.transform.rotation.y = q[1]
        self.transform_stamped.transform.rotation.z = q[2]
        self.transform_stamped.transform.rotation.w = q[3]
        self.turtle1_broadcaster.sendTransform(self.transform_stamped)
        
        
def euler_to_quaternion(roll, pitch, yaw):
    q = np.empty((4, ))
    q[0] = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2)
    q[1] = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2)
    q[2] = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2)
    q[3] = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2)
    return q

def main(args=None):
    rclpy.init(args=args)
    node = Turtle1Broadcaster()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
if __name__ == '__main__':
    main()