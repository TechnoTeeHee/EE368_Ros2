#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
from geometry_msgs.msg import TransformStamped

class TFBroadcaster1(Node):
    def __init__(self):
        super().__init__("tf_broadcaster1")
        self.tf_broadcaster_ = tf2_ros.StaticTransformBroadcaster(self)
        self.get_logger().info("tf_broadcaster1 is ready")
        self.broadcast_tf_message()
        
    def broadcast_tf_message(self):
        self.transform_stamped = TransformStamped()
        self.transform_stamped.header.frame_id = "world"
        self.transform_stamped.child_frame_id = "center"
        self.transform_stamped.header.stamp = self.get_clock().now().to_msg()
        self.transform_stamped.transform.translation.z = 1.0
        self.tf_broadcaster_.sendTransform(self.transform_stamped)
        
def main(args=None):
    rclpy.init(args=args)
    node = TFBroadcaster1()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == '__main__':
    main()