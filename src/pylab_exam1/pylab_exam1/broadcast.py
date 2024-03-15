#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
import numpy as np
from math import pi, sin, cos
from geometry_msgs.msg import TransformStamped

class broadcastNode(Node):
    def __init__(self):
        super().__init__("broadcast")
        self.tf_broadcaster1_ = tf2_ros.TransformBroadcaster(self)
        self.get_logger().info("tf_broadcaster1 is ready")
        self.tf_broadcaster2_ = tf2_ros.TransformBroadcaster(self)
        self.step = 0.0
        self.yaw = 0.0
        self.theta = 0
        self.theta2 = 0
        self.get_logger().info("tf_broadcaster2 is ready")
        self.timer = self.create_timer(0.05, self.broadcast_tf_message1)
        self.timer2 = self.create_timer(0.05, self.broadcast_tf_message2)

    def broadcast_tf_message1(self):
        transform_stamped = TransformStamped()
        transform_stamped.header.frame_id = "world"
        transform_stamped.child_frame_id = "tf1"
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        testx = cos(self.theta)
        testy = sin(self.theta)
        transform_stamped.transform.translation.x = testx
        transform_stamped.transform.translation.y = testy
        q = euler_to_quaternion(0,0,self.theta)
        transform_stamped.transform.rotation.x = q[0]
        transform_stamped.transform.rotation.y = q[1]
        transform_stamped.transform.rotation.z = q[2]
        transform_stamped.transform.rotation.w = q[3]
        self.theta -= 1.0*pi/180
        if self.theta < 0:
            self.theta = 360.0*pi/180
        self.get_logger().info('theta: ' + str(self.theta2))
        self.tf_broadcaster1_.sendTransform(transform_stamped)
        
    def broadcast_tf_message2(self):
        transform_stamped1 = TransformStamped()
        transform_stamped1.header.frame_id = "tf1"
        transform_stamped1.child_frame_id = "tf2"
        transform_stamped1.header.stamp = self.get_clock().now().to_msg()
        transform_stamped1.transform.translation.y = 2.0
        test2x = 0.5*sin(self.theta2)
        test2y = 0.5*cos(self.theta2)
        transform_stamped1.transform.translation.x = -test2x
        transform_stamped1.transform.translation.y = -test2y
        q = euler_to_quaternion(0, 0, -self.theta2)
        transform_stamped1.transform.rotation.x = q[0]
        transform_stamped1.transform.rotation.y = q[1]
        transform_stamped1.transform.rotation.z = q[2]
        transform_stamped1.transform.rotation.w = q[3]
        self.theta2 += 1.0*pi/180
        if self.theta2 > 360.0*pi/180:
            self.theta2 = 0
        self.tf_broadcaster2_.sendTransform(transform_stamped1)
        
def euler_to_quaternion(roll, pitch, yaw):
    q = np.empty((4, ))
    q[0] = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2)
    q[1] = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2)
    q[2] = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2)
    q[3] = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2)
    return q

def main(args=None):
    rclpy.init(args=args)
    node = broadcastNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
if __name__ == '__main__':
    main()