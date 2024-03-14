#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import PointCloud2
import numpy as np
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
        arr = []
        top = data[int(width/2)][0]
        
        if (top == np.inf):
            top_clear = 1
            reset = 0
        else:
            top_clear = 0
            reset = 1

        for i in range(1,height-1):
            x = data[int(width*i + width/2)][0] 
            z = (data[int(width*i + width/2)][2]) + 0.45

            if (round(z, 2) != 0):
                if (reset == 1 and x == np.inf):
                    reset = 0
                    arr.append(data[(i-1)*width + int(width/2)][2] + 0.45)
                elif(reset == 0 and x != np.inf):
                    reset = 1
                    arr.append(z)

        if (len(arr) == 0):
            if (top_clear == 1):
                self.get_logger().info('All clear')
            else:
                self.get_logger().info("Object dead ahead, distance = " + str(top))
        elif (len(arr) == 1):
            if(top_clear == 1):
                self.get_logger().info('Bottom blocked ' + str(arr[0]))
            else:
                self.get_logger().info('Door height ' + str(arr[0]))
        elif (len(arr) == 2):
            self.get_logger().info('Opening z ' + str(arr[0]) + ' to ' + str(arr[1]))
        
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
