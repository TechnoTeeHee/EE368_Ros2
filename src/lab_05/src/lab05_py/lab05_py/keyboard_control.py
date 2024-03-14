#!/usr/bin/env python3

#**********************************************************************
# Example Python Program for concurrent ROS node and keyboard input
#----------------------------------------------------------------------

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
import time
from select import select
import sys
import termios
import tty

from geometry_msgs.msg import Twist




#**********************************************************************
# Keyboard routines
#----------------------------------------------------------------------
def getKey(settings, timeout):
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select([sys.stdin], [], [], timeout)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def saveTerminalSettings():
    return termios.tcgetattr(sys.stdin)

#**********************************************************************
# ROS2 Node
#----------------------------------------------------------------------
class ControlNode(Node):
    def __init__(self):
        super().__init__("control")
        self.get_logger().info('Control has started.')
        self.create_subscription(Imu, "/imu", self.callback, 10)

    def callback(self,msg):
        self.get_logger().info('Callback.')
        self.msg = msg
        return
    
    def velocity(self, velocity):
        x_acceleration = self.msg.linear_acceleration.x
        self.get_logger().info(f'x_acceleration: {x_acceleration}')
        self.get_logger().info(f'velocity: {velocity}') 
        if x_acceleration > 0.5:
            return velocity 
        else:
            return velocity + 0.2

#**********************************************************************
# Main
#----------------------------------------------------------------------
def main(args=None):
    try:
        settings = saveTerminalSettings()
        key_timeout = 0.5
        
        rclpy.init(args=args)
        node = ControlNode()

        node1 = rclpy.create_node('node1')
        cmd_vel_publisher = node1.create_publisher(Twist, "/cmd_vel", 10)
        vel_msg = Twist()
        vel_msg.linear.x = 0.0
        vel_msg.angular.z = 0.0


        while True:
            rclpy.spin_once(node, timeout_sec=0)
            key = getKey(settings, key_timeout)
            
            # Check for empty key (i.e., timeout)
            if key == '':
                continue


            if key == '\x09':
                print("Decelerating...")
                velocity = -3.0
                vel_msg.linear.x = velocity
                vel_msg.angular.z = 0.0
                cmd_vel_publisher.publish(vel_msg)
                time.sleep(0.2) 

                while velocity < 0:
                    velocity = node.velocity(velocity)
                    vel_msg.linear.x = velocity
                    cmd_vel_publisher.publish(vel_msg)
                    time.sleep(0.1)

            if key == 'w':
                vel_msg.linear.x = 3.0
                vel_msg.angular.z = 0.0
            
            if key == 's':
                vel_msg.linear.x = -3.0
                vel_msg.angular.z = 0.0
            
            if key == 'a':
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = 1.0
            
            if key == 'd':
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = -1.0


            # Exit Control-C
            if key == '\x03' or key == 'x':
                print("Exiting...")
                break

            # Check if printable key
            hexCode = key.encode('utf-8').hex()
            if key.isprintable():
                print(f"key='{key}' (0x{hexCode})")
            else:
                print(f"key=(0x{hexCode})")

            cmd_vel_publisher.publish(vel_msg)
            rclpy.spin_once(node1, timeout_sec=0)
            
    except:
        print("\nException...")
    finally:
        node.destroy_node()
        
if __name__ == "__main__":
    main()