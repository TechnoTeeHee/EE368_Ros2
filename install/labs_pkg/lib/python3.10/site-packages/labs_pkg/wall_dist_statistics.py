#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import statistics
from lab_interfaces.msg import WallDistanceStatistics
from lab_interfaces.msg import WallDistanceArray
class WallDistanceStatisticsNode(Node):
    def __init__(self):
        super().__init__("wall_dist_measurement")
        super().__init__("wall_dist_statistics")
        self.dist_array_ = []
        self.dist_statistics_publisher_ = self.create_publisher(WallDistanceStatistics, "dist_statistics", 10)
        self.wall_dist_array_subscriber_ = self.create_subscription(WallDistanceArray, "wall_distance", self.callback_dist_statistics, 10)
        self.get_logger().info("The distance statistics calculation has started.")
        
    def callback_dist_statistics(self, msg):
        if len(msg.dist_array) > 2:
            for i in range(len(msg.dist_array)):
                self.dist_array_.append(msg.dist_array[i].dist)
            new_msg = WallDistanceStatistics()
            new_msg.mean = statistics.mean(self.dist_array_)
            new_msg.std = statistics.stdev(self.dist_array_)
            self.dist_statistics_publisher_.publish(new_msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = WallDistanceStatisticsNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()