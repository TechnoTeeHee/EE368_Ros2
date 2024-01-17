#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import statistics
from lab_interfaces.msg import WallDistanceStatistics
from lab_interfaces.srv import MeasureWallDist

class WallDistanceStatisticsClientNode(Node):
    def __init__(self):
        super().__init__("wall_dist_statistics_client")
        self.call_dist_statistics_server()
        self.dist_statistics_publisher_ = self.create_publisher(WallDistanceStatistics, "dist_statistics", 10)
        self.get_logger().info("The distance statistics calculation has started.")
    
    def call_dist_statistics_server(self):
        client = self.create_client(MeasureWallDist, "meas_wall_dist")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for MeasureWallDist Server")
        request = MeasureWallDist.Request()
        future = client.call_async(request)
        future.add_done_callback(self.callback_call_meas_wall_dist)
        
    def callback_call_meas_wall_dist(self, future):
        try:
            response = future.result()
            self.callback_dist_statistics(response.wall_dist_array)
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
    
    def callback_dist_statistics(self,msg):
        dist_array_ = []
        if len(msg.dist_array) > 2:
            for i in range(len(msg.dist_array)):
                dist_array_.append(msg.dist_array[i].dist)
            new_msg = WallDistanceStatistics()
            new_msg.mean = statistics.mean(dist_array_)
            new_msg.std = statistics.stdev(dist_array_)
            self.dist_statistics_publisher_.publish(new_msg)
            self.get_logger().info("Distance statistics has been published")
            
def main(args=None):
    rclpy.init(args=args)
    node = WallDistanceStatisticsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()