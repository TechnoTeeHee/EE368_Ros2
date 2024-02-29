#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2

from .point_cloud2 import *

class ControlNode(Node):
    def __init__(self):
        super().__init__("control")
        self.moving = False
        self.lidar_subscriber = self.create_subscription(PointCloud2, 
            "/camera/depth/points", self.process_depth, 10)
        self.get_logger().info('Control has started.')

    def process_depth(self, msg):
        gen = read_points(msg, skip_nans=True)
        data = list(gen)
        width = msg.width
        height = msg.height
        
        # "data" is a linear array of width x height "points"
        # For each point, x=point[0], y=point[1], z=point[2]
        # ...
        
def main(args=None):
    rclpy.init(args=args)
    node = ControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\nKeyboardInterrupt...")
        node.destroy_node()

if __name__ == "__main__":
    main()
