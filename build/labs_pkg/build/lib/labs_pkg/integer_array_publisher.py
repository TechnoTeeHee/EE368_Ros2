#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from lab_interfaces.msg import Num
from lab_interfaces.msg import NumArray
import random

class IntegerArrayPublisherNode(Node):
    def __init__(self):
        super().__init__("integer_array_publisher")
        self.publisher_ = self.create_publisher(NumArray, "integer_array", 10)
        self.timer_ = self.create_timer(2, self.publish_integerpublisher)
        self.array = NumArray()
        self.counter = 0

    def publish_integerpublisher(self):
        num_msg = Num()  # Create a Num message
        num_msg.name = "Integer"+str(self.counter+1)
        num_msg.num = random.randint(0, 10)
        self.array.num_array.append(num_msg)
        msg = NumArray()
        msg.num_array = self.array.num_array
        self.publisher_.publish(msg)
        self.get_logger().info('num_array:')
        for i in self.array.num_array:
            self.get_logger().info(f'- name: "{i.name}"')
            self.get_logger().info(f'num: "{i.num}"')
        self.get_logger().info('---')
        self.counter += 1



def main(args=None):
    rclpy.init(args=args)
    node = IntegerArrayPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()