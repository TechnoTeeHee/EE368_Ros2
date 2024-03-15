#!/usr/bin/env python3

#**********************************************************************
# Example Python Program for concurrent ROS node and keyboard input
#----------------------------------------------------------------------

import rclpy
from rclpy.node import Node

from select import select
import sys
import termios
import tty

from geometry_msgs.msg import Twist
from sensor_msgs.msg import Imu
import time

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
class KeyboardControlNode(Node):
    def __init__(self):
        super().__init__("keyboard_control")
        self.create_subscription(Imu, "/imu", self.callback, 10)
        self.get_logger().info('Keyboard_Control has started.')

    def callback(self, msg):
        self.imu = msg
    
    def slow_down(self, velocity):
        acceleration = self.imu.linear_acceleration.x
        self.get_logger().info('Acceleration: ' + str(acceleration) + 'Velocity: ' + str(velocity))
        if acceleration < 0.5:
            return velocity + 0.25
        else:
            return velocity
            
            

#**********************************************************************
# Main
#----------------------------------------------------------------------
def main(args=None):
    try:
        settings = saveTerminalSettings()
        key_timeout = 0.01
        
        rclpy.init(args=args)
        node = KeyboardControlNode()

        node1 = rclpy.create_node('node1')
        cmd_vel_publisher = node1.create_publisher(Twist, "/cmd_vel", 10)
        vel_msg = Twist()
        
        while True:
            
            rclpy.spin_once(node, timeout_sec=0)
            key = getKey(settings, key_timeout)
                
            # Check for empty key (i.e., timeout)
            if key == '':
                try:
                    if flag == True:
                        velocity = vel_msg.linear.x
                        vel_msg.angular.z = 0.0
                        cmd_vel_publisher.publish(vel_msg)
                        if velocity < 0:
                            velocity2 = node.slow_down(velocity)
                            cmd_vel_publisher.publish(vel_msg)
                            if velocity2 != velocity:
                                time.sleep(0.5)
                                rclpy.spin_once(node1, timeout_sec=0)
                                velocity = velocity2
                            vel_msg.linear.x = velocity
                        else:
                            flag = False
                except:
                    continue
                continue
            
            if key == 'w':
                vel_msg.linear.x = 3.0
                vel_msg.angular.z = 0.0
            
            if key == 'a':
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = 1.0
                
            if key == 's':
                vel_msg.linear.x = -3.0
                vel_msg.angular.z = 0.0
            
            if key == 'd':
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = -1.0
            
            if key == '\x20':
                vel_msg.linear.x = 0.0
                vel_msg.angular.z = 0.0
            
            if key == '\x09':
                flag = True
                
            
                 
            if key == 'x':
                print("Exiting...")
                break
            
            # Exit Control-C
            if key == '\x03':
                print("Exiting...")
                break

            # Check if printable key
            hexCode = key.encode('utf-8').hex()
            if key.isprintable():
                print(f"key='{key}' (0x{hexCode})")
            else:
                print(f"key=(0x{hexCode})")

            #vel_msg = Twist()
            #vel_msg.linear.x = 3.0
            cmd_vel_publisher.publish(vel_msg)
            
    except:
        print("\nException...")
    finally:
        node.destroy_node()
        
if __name__ == "__main__":
    main()
