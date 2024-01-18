#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64
from example_interfaces.srv import SetBool

class CumulativeAdderNode(Node):
    def __init__(self):
        super().__init__("cumulative_adder")
        self.sum = Int64()
        self.sum.data = 0
        self.publisher_ = self.create_publisher(Int64, "integer_sum", 10)
        self.subscriber_ = self.create_subscription(Int64, "integer", self.callback_integer, 10)
        self.server_ = self.create_service(SetBool, "reset_sum", self.callback_resetsum)
        self.get_logger().info("The reset sum server has started.")
        
    def callback_integer(self, msg):
        self.sum.data += msg.data
        self.publisher_.publish(self.sum)
        self.get_logger().info('data: [' + str(self.sum.data) + ']')
        
    def callback_resetsum(self, request, response):
        if request.data:
            self.sum.data = 0
        return response
    

def main(args=None):
    rclpy.init(args=args)
    node = CumulativeAdderNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()