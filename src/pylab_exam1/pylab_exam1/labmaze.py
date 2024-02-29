#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan

# My code doesnt work but the solution I was trying to implement was to move and turn left if it hits a wall, and if theres a gap to the right turn right and go forward into the gap.
# I also was able to get it to "jump" out of the maze by setting speed super high but didnt have enough time to record it
class labMazeNode(Node):
    def __init__(self):
        super().__init__("lab_maze")
        self.scan_subscriber_ = self.create_subscription(LaserScan, "scan", self.get_scan, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "cmd_vel", 10)
        self.scan = None
        self.isTurning = False
        self.Ka = -0.1
        self.Kv = 0.5
        self.counter = 0
        self.timeadder = 0
        self.timecounter = 0
        
    def get_scan(self, msg):
        self.scan = msg.ranges
        #self.get_logger().info('forward: ' + str(self.scan[180]))
        #self.get_logger().info('right: ' +str(self.scan[90]))
        #self.get_logger().info('backleft: ' +str(self.scan[45]))
        #self.get_logger().info('Counter: ' + str(self.timecounter))
        #self.get_logger().info('time: ' + str(self.timeadder))
        if self.scan != None and self.counter == 0:
            self.get_to_wall()
        if self.scan != None and self.counter == 1:
            self.primer_turn()
            self.timecounter += 1
        if self.isTurning:
            self.timeadder += 1
        
    def get_to_wall(self):
        vel_msg = Twist()
        vel_msg.angular.z = 0.0
        if (self.scan[180] > 1.0):
            vel_msg.linear.x = self.Kv
        elif (self.scan[180] <= 1.0 and self.scan[180] > 0.5):
            vel_msg.linear.x = 0.2
        elif (self.scan[180] <= 0.5):
            vel_msg.linear.x = 0.0
            self.counter += 1
        self.cmd_vel_publisher_.publish(vel_msg)
            
    def primer_turn(self):
        vel_msg = Twist()
        if min(self.scan) == self.scan[90]:
            vel_msg.angular.z = 0.0
            self.counter += 1
            self.move_timer_ = self.create_timer(0.1, self.move)
        elif min(self.scan) < self.scan[90]:
            vel_msg.angular.z = -self.Ka
            vel_msg.linear.x = 0.0
        self.cmd_vel_publisher_.publish(vel_msg)
        
    def move(self):
        vel_msg = Twist()
        if (abs(min(self.scan)-0.707106781)<=0.001) or self.isTurning == True:
            self.isTurning = True
            self.turn()
        elif abs(min(self.scan)-0.707106781) < 0.5:
            vel_msg.angular.z = 0.0
            vel_msg.linear.x = abs(min(self.scan)-0.707106781)
            self.cmd_vel_publisher_.publish(vel_msg)
        elif (self.scan[180] <= 0.3):
            vel_msg.linear.x = 0.0
            self.isTurning = True
            self.turn()
        else:
            vel_msg.linear.x = 0.5
            self.cmd_vel_publisher_.publish(vel_msg)
            
    def turn(self):
        vel_msg = Twist()
        if self.timeadder >= self.timecounter:
            vel_msg.linear.x = self.Kv
            self.timeadder = 0
            self.isTurning = False
        else:
            vel_msg.angular.z = self.Ka
            vel_msg.linear.x = 0.0
        self.cmd_vel_publisher_.publish(vel_msg)
    
def main(args=None):
    rclpy.init(args=args)
    node = labMazeNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()