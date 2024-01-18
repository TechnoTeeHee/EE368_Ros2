#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class MyTalkerNode(Node):
    def __init__(self):
        super().__init__("my_talker")
        self.counter_ = 0
        self.publisher_ = self.create_publisher(String, "my_chatter", 10)
        self.timer_ = self.create_timer(0.5, self.publish_talker)

    def publish_talker(self):
        self.counter_ += 1
        msg = String()
        msg.data = "Hello World: " + str(self.counter_)
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "Hello World: ' + str(self.counter_) + '"')

def main(args=None):
    rclpy.init(args=args)
    node = MyTalkerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()