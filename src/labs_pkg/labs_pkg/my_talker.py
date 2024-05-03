#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class MyTalkerNode(Node):
    def __init__(self):
        super().__init__("my_talker")
        self.declare_parameter("string_to_publish", "Hello World")
        self.declare_parameter("publish_rate", 2.0)
        self.string_ = self.get_parameter("string_to_publish").value
        self.publish_rate_ = self.get_parameter("publish_rate").value
        self.counter_ = 0
        self.publisher_ = self.create_publisher(String, "my_chatter", 10)
        self.timer_ = self.create_timer(1/self.publish_rate_, self.publish_talker)

    def publish_talker(self):
        self.counter_ += 1
        msg = String()
        msg.data = self.string_ + ': ' + str(self.counter_)
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: ' + '"' + self.string_ + ': '+ str(self.counter_) + '"')
        
def main(args=None):
    rclpy.init(args=args)
    node = MyTalkerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()