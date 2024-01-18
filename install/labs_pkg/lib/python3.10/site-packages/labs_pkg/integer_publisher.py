#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class IntegerPublisherNode(Node):
    def __init__(self):
        super().__init__("integer_publisher")
        self.declare_parameter("int_to_publish", 5)
        self.declare_parameter("publish_rate", 2.0)
        self.int_ = self.get_parameter("int_to_publish").value
        self.publish_rate_ = self.get_parameter("publish_rate").value
        self.publisher_ = self.create_publisher(Int64, "integer", 10)
        self.timer_ = self.create_timer(1/self.publish_rate_, self.publish_integerpublisher)

    def publish_integerpublisher(self):
        x = self.int_
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