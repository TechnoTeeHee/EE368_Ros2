#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class MyListenerNode(Node):
    def __init__(self):
        super().__init__("my_listener")
        self.subscriber_ = self.create_subscription(String, "my_chatter", self.callback_my_chatter, 10)

    def callback_my_chatter(self, msg):
        self.get_logger().info('I heard: [' + msg.data + ']')

def main(args=None):
    rclpy.init(args=args)
    node = MyListenerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()