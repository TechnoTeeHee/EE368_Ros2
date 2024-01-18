#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import random
from lab_interfaces.msg import WallDistanceMeasurement
from lab_interfaces.msg import WallDistanceArray
class WallDistanceMeasurementNode(Node):
    def __init__(self):
        super().__init__("wall_dist_measurement")
        self.dist_array_ = []
        self.count_ = 0
        self.wall_dist_array_publisher_ = self.create_publisher(WallDistanceArray, "wall_distance", 10)
        self.callback_timer_ = self.create_timer(0.2, self.generate_wall_distance)
        self.callback_timer_ = self.create_timer(1.0, self.publish_wall_distance)
        self.get_logger().info("The wall distance publisher has started.")
        
    def generate_wall_distance(self):
        self.count_ += 1
        new_dist_meas = WallDistanceMeasurement()
        new_dist_meas.name = "Measurement" + str(self.count_)
        new_dist_meas.dist = random.normalvariate(10, 2)
        self.dist_array_.append(new_dist_meas)
        
    def publish_wall_distance(self):
        msg = WallDistanceArray()
        msg.dist_array = self.dist_array_
        self.count_ = 0
        self.dist_array_ = []
        self.wall_dist_array_publisher_.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = WallDistanceMeasurementNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()