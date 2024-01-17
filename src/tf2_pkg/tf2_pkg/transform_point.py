#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
from tf2_ros import TransformException
from tf2_geometry_msgs import PointStamped

class TransformPoint(Node):
    def __init__(self):
        super().__init__('transform_point')
        self.tf_buffer_ = Buffer()
        self.tf_listener_ = TransformListener(self.tf_buffer_, self)
        self.timer = self.create_timer(1.0, self.listen_tf_message)

    def listen_tf_message(self):
        pt = PointStamped()
        pt.header.stamp = self.get_clock().now().to_msg()
        pt.header.frame_id = "base_laser"
        pt.point.x = 0.3
        pt.point.y = 0.0
        pt.point.z = 0.0
        dest_frame = "base_link"
        try:
            tf_pt = self.tf_buffer_.transform(pt, dest_frame)
            self.get_logger().info("Transformed point is (" + str(tf_pt.point.x) + ", " + str(tf_pt.point.y) + ", " + str(tf_pt.point.z)+")") 
        except TransformException as ex: 
            self.get_logger().info( f'Could not transform the point to {dest_frame}: {ex}')

def main():
    rclpy.init()
    node = TransformPoint()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == '__main__':
    main()