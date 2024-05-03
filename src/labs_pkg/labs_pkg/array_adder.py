#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64
from lab_interfaces.msg import Num
from lab_interfaces.msg import NumArray

class ArrayAdderNode(Node):
    def __init__(self):
        super().__init__("array_adder")
        self.sum = Int64()
        self.sum.data = 0
        self.publisher_ = self.create_publisher(Int64, "array_sum", 10)
        self.subscriber_ = self.create_subscription(NumArray, "integer_array", self.callback_array, 10)
        
    def callback_array(self, msg):
        self.sum.data = 0
        for i in msg.num_array:
            self.sum.data += i.num
        self.publisher_.publish(self.sum)
        self.get_logger().info('data: [' + str(self.sum.data) + ']')
        

def main(args=None):
    rclpy.init(args=args)
    node = ArrayAdderNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()