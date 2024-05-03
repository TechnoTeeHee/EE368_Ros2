#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

import time
import random
import subprocess

gStartTime = time.time_ns()
def MyPrint(str):
    deltaTime = time.time_ns() - gStartTime
    secs = int(deltaTime / 1000000000.0)
    msecs = int((deltaTime - secs * 1000000000.0) / 1000000)
    print(f"{secs:03d}.{msecs:03d} {str}")
    
LINEAR_X = 2.0
MIN_ANGULAR = -3.0
MAX_ANGULAR = 3.0

class ControlNode(Node):
    def __init__(self):
        super().__init__("rabbits")
        self.cmd_vel_red = self.create_publisher(Twist, "/cmd_vel_red", 10)
        self.cmd_vel_green = self.create_publisher(Twist, "/cmd_vel_green", 10)
        self.cmd_vel_blue = self.create_publisher(Twist, "/cmd_vel_blue", 10)
        self.red_linear_x = LINEAR_X
        self.red_angular_z = 0
        self.green_linear_x = LINEAR_X
        self.green_angular_z = 0
        self.blue_linear_x = LINEAR_X
        self.blue_angular_z = 0
        self.timer = self.create_timer(1.0, self.process_timeout)
        self.timer = self.create_timer(10.0, self.do_teleport)
        #self.do_teleport()
        
    def process_timeout(self):
        # Randomly change direction
        new_angle = self.red_angular_z + (float(random.randint(-10, 10)) / 10.0)
        if new_angle < MIN_ANGULAR:
            new_angle = MIN_ANGULAR
        elif new_angle > MAX_ANGULAR:
            new_angle = MAX_ANGULAR
        #MyPrint(f"New angular = {new_angle:.2f}");
        self.red_angular_z = new_angle

        # Publish new velocity
        vel_msg = Twist()
        vel_msg.linear.x = self.red_linear_x
        vel_msg.angular.z = self.red_angular_z
        self.cmd_vel_red.publish(vel_msg)
        
        # Randomly change direction
        new_angle = self.green_angular_z + (float(random.randint(-10, 10)) / 10.0)
        if new_angle < MIN_ANGULAR:
            new_angle = MIN_ANGULAR
        elif new_angle > MAX_ANGULAR:
            new_angle = MAX_ANGULAR
        #MyPrint(f"New angular = {new_angle:.2f}");
        self.green_angular_z = new_angle

        # Publish new velocity
        vel_msg = Twist()
        vel_msg.linear.x = self.green_linear_x
        vel_msg.angular.z = self.green_angular_z
        self.cmd_vel_green.publish(vel_msg)
        
        # Randomly change direction
        new_angle = self.blue_angular_z + (float(random.randint(-10, 10)) / 10.0)
        if new_angle < MIN_ANGULAR:
            new_angle = MIN_ANGULAR
        elif new_angle > MAX_ANGULAR:
            new_angle = MAX_ANGULAR
        #MyPrint(f"New angular = {new_angle:.2f}");
        self.blue_angular_z = new_angle

        # Publish new velocity
        vel_msg = Twist()
        vel_msg.linear.x = self.blue_linear_x
        vel_msg.angular.z = self.blue_angular_z
        self.cmd_vel_blue.publish(vel_msg)
        
    def do_teleport(self):
        # Teleport 
        #x = random.randint(-10, 10)
        #y = random.randint(-10, 10)
        x = 0
        y = 8
        subprocess.run([
            "ign", 
            "service",
            "-s",
            "/world/followTheLeader/set_pose",
            "--reqtype",
            "ignition.msgs.Pose",
            "--reptype",
            "ignition.msgs.Boolean",
            "--timeout",
            "300",
            "--req",
            "name:\"rabbitRed\",position:{x:" + str(x) + ",y:" + str(y) + ",z:0.05}"
        ], capture_output=True)
        
        # Teleport 
        #x = random.randint(-10, 10)
        #y = random.randint(-10, 10)
        x = 0
        y = 0
        subprocess.run([
            "ign", 
            "service",
            "-s",
            "/world/followTheLeader/set_pose",
            "--reqtype",
            "ignition.msgs.Pose",
            "--reptype",
            "ignition.msgs.Boolean",
            "--timeout",
            "300",
            "--req",
            "name:\"rabbitGreen\",position:{x:" + str(x) + ",y:" + str(y) + ",z:0.05}"
        ], capture_output=True)
        
        # Teleport 
        #x = random.randint(-10, 10)
        #y = random.randint(-10, 10)
        x = 0
        y = -8
        subprocess.run([
            "ign", 
            "service",
            "-s",
            "/world/followTheLeader/set_pose",
            "--reqtype",
            "ignition.msgs.Pose",
            "--reptype",
            "ignition.msgs.Boolean",
            "--timeout",
            "300",
            "--req",
            "name:\"rabbitBlue\",position:{x:" + str(x) + ",y:" + str(y) + ",z:0.05}"
        ], capture_output=True)

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