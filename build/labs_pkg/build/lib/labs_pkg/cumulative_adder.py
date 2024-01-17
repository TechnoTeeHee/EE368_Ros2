#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

class CumulativeAdderNode(Node):
    def __init__(self):
        super().__init__("cumulative_adder")
        self.sum = Int64()
        self.sum.data = 0
        self.publisher_ = self.create_publisher(Int64, "integer_sum", 10)
        self.subscriber_ = self.create_subscription(Int64, "integer", self.callback_integer, 10)
        
    def callback_integer(self, msg):
        self.sum.data += msg.data
        self.publisher_.publish(self.sum)
        self.get_logger().info('data: [' + str(self.sum.data) + ']')
        

def main(args=None):
    rclpy.init(args=args)
    node = CumulativeAdderNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()