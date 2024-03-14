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
        self.lidar_subscriber = self.create_subscription(PointCloud2, "/camera/depth/points", self.process_depth, 10)
        self.get_logger().info('Control has started.')
        self.camera_height = 0.45
    
    def process_depth(self, msg):
        gen = read_points(msg, skip_nans=True)
        data = list(gen)
        width = msg.width
        height = msg.height

        top_point = data[int(width/2)][0]

        if (top_point == np.inf):
            opening_at_top = 1
            flag = 0
        else:
            opening_at_top = 0
            flag = 1

        list1 = []

        for i in range(1,height-1):
            x = data[i*width + int(width/2)][0] 
            z = data[i*width + int(width/2)][2] + self.camera_height

            if (round(z, 4) != 0):
                if (flag == 0 and x != np.inf):
                    flag = 1
                    list1.append(z)
                elif(flag == 1 and x == np.inf):
                    flag = 0
                    list1.append(data[(i-1)*width + int(width/2)][2] + self.camera_height)


        
        if (len(list1) == 0):
            if (opening_at_top == 1):
                self.get_logger().info('All Clear')
            else:
                self.get_logger().info("Object directly ahead distance: " + str(top_point))
        
        elif (len(list1) == 1):
            if(opening_at_top == 1):
                self.get_logger().info('Bottom blocked height: ' + str(list1[0]))
            else:
                self.get_logger().info('Door height: ' + str(list1[0]))

        elif (len(list1) == 2):
            self.get_logger().info('Open in between top height: ' + str(list1[0]) + 'bottom height: ' + str(list1[1]))

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
