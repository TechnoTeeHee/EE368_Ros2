#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class ExampleNode(Node):
	def __init__(self):
		super().__init__("ex_test")
		self.counter = 0
		self.get_logger().info("Hello ROS2")
		self.create_timer(0.5, self.count_callback)

	def count_callback(self):
		self.counter += 1
		self.get_logger().info("Count " + str(self.counter))

def main(args=None):
	rclpy.init(args=args)
	node = ExampleNode()
	rclpy.spin(node)
	rclpy.shutdown()

if __name__ == "__main__":
	main()
