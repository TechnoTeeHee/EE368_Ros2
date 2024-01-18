#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
from geometry_msgs.msg import TransformStamped

class TFBroadcaster2(Node):
    def __init__(self):
        super().__init__("tf_broadcaster2")
        self.tf_broadcaster_ = tf2_ros.StaticTransformBroadcaster(self)
        self.get_logger().info("tf_broadcaster2 is ready")
        self.broadcast_tf_message()

    def broadcast_tf_message(self):
        transform_stamped = TransformStamped()
        transform_stamped.header.frame_id = "center"
        transform_stamped.child_frame_id = "center_y"
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.transform.translation.y = 2.0
        self.tf_broadcaster_.sendTransform(transform_stamped)

        transform_stamped1 = TransformStamped()
        transform_stamped1.header.frame_id = "center"
        transform_stamped1.child_frame_id = "center_x"
        transform_stamped1.header.stamp = self.get_clock().now().to_msg()
        transform_stamped1.transform.translation.x = 2.0
        self.tf_broadcaster_.sendTransform(transform_stamped1)

def main(args=None):
    rclpy.init(args=args)
    node = TFBroadcaster2()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()