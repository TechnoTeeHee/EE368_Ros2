#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import random
import time
from lab_interfaces.msg import WallDistanceMeasurement
from lab_interfaces.msg import WallDistanceArray
from lab_interfaces.srv import MeasureWallDist

class WallDistanceMeasurementServerNode(Node):
    def __init__(self):
        super().__init__("wall_dist_measurement_server")
        self.dist_array_ = []
        self.count_ = 0
        self.measure_dist_server_ = self.create_service(MeasureWallDist, "meas_wall_dist", self.generate_wall_distance)
        self.get_logger().info("The wall distance server has started.")
    
    def generate_wall_distance(self, request, response):
        for i in range(1,6):
            self.count_ += 1
            new_dist_meas = WallDistanceMeasurement()
            new_dist_meas.name = "Measurement" + str(self.count_)
            new_dist_meas.dist = random.normalvariate(10, 2)
            self.dist_array_.append(new_dist_meas)
            time.sleep(0.2)
        msg = WallDistanceArray()
        msg.dist_array = self.dist_array_
        response.wall_dist_array = msg
        self.dist_array_ = []
        self.count_ = 0
        return response
    
def main(args=None):
    rclpy.init(args=args)
    node = WallDistanceMeasurementServerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()