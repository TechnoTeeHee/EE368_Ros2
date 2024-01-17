#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class IntegerPublisherNode(Node):
    def __init__(self):
        super().__init__("integer_publisher")
        self.publisher_ = self.create_publisher(Int64, "integer", 10)
        self.timer_ = self.create_timer(2, self.publish_integerpublisher)

    def publish_integerpublisher(self):
        x = 5
        msg = Int64()
        msg.data = x
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "' + str(x) + '"')

def main(args=None):
    rclpy.init(args=args)
    node = IntegerPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()