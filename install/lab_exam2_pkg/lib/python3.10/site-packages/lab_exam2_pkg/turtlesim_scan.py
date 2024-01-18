#!/usr/bin/env python3
# turtlesim_scan.py
# created by Brian Daku
from math import tan, cos, pi
import rclpy
from rclpy.node import Node
import numpy as np
from turtlesim.msg import Pose
from sensor_msgs.msg import LaserScan

class TurtlesimScan(Node):
    def __init__(self):
        super().__init__("turtlesim_scan")
        self.pose_subscriber_ = self.create_subscription(
            Pose,
            "/turtle1/pose",
            self.publish_scan,
            10)
        self.scan_publisher_ = self.create_publisher(LaserScan, "scan", 10)
        self.get_logger().info("Publisher is ready")

    def publish_scan(self, msg):
        scan_msg = LaserScan()
        dist_to_wall = self.generate_scan(msg.x,msg.y,msg.theta)
        scan_msg.ranges = dist_to_wall.tolist()  # convert to list
        self.scan_publisher_.publish(scan_msg)

    def generate_scan(self,xp,yp,theta):
        # xp is the turtle1 x-axis pose value
        # yp is the turtle1 y-axis pose value
        # theta is the turtle1 orientation pose value
        d = np.zeros(360)  # create distance array d
        xs = 11.0  # x-axis size of Turtlesim window 
        ys = 11.0  # y-axis size of Turtlesim window
        if theta < 0:  # theta range is -pi to pi
            theta = 2*pi + theta  # convert range to 0 to 2pi
        theta_round = round(theta*180/pi)  # convert to degrees
        for i in range(0,360):  # calculate distance to wall for each angle
            if i == 0:
                d[i] = xs - xp
            if i == 90:
                d[i] = ys - yp
            if i == 180:
                d[i] = xp
            if i == 270:
                d[i] = yp
            angle = i*pi/180  # convert to radians
            if i > 0 and i < 90:
                if (xs-xp)*tan(angle) < ys-yp:
                    d[i] = (xs-xp)/cos(angle)
                else:
                    d[i] = (ys-yp)/cos(pi/2-angle)
            if i > 90 and i < 180:
                if (ys-yp)*tan(angle-pi/2) < xp:
                    d[i] = (ys-yp)/cos(angle-pi/2)
                else:
                    d[i] = xp/cos(pi-angle)
            if i > 180 and i < 270:
                if xp*tan(angle-pi) < yp:
                    d[i] = xp/cos(angle-pi)
                else:
                    d[i] = yp/cos(3*pi/2-angle)
            if i > 270 and i < 360:
                if yp*tan(angle-3*pi/2) < xs-xp:
                    d[i] = yp/cos(angle-3*pi/2)
                else:
                    d[i] = (xs-xp)/cos(2*pi-angle)
        d1 = np.roll(d,-int(theta_round))  # cyclic shift to align turtle1 heading with d[0]
        return d1

def main(args=None):
    rclpy.init(args=args)
    node = TurtlesimScan()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()