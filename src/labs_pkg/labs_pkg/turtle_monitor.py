#!/usr/bin/env python3
import random
import math
import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
from lab_interfaces.msg import Turtle
from lab_interfaces.msg import TurtleArray
from lab_interfaces.srv import CaptureTurtle

class TurtleMonitorNode(Node):
    def __init__(self):
        super().__init__("turtle_monitor")
        self.publisher_ = self.create_publisher(TurtleArray, "alive_turtles", 10)
        self.subscriber_ = self.create_subscription(Turtle, "new_turtle", self.callback_turtle_array, 10)
        self.TurtleArray = TurtleArray()
        self.capture_turtle_server = self.create_service(CaptureTurtle, "capture_turtle", self.callback_capture_turtle)
    
    def callback_capture_turtle(self, request, response):
        turtle_array = self.TurtleArray.turtle_array
        name_to_remove = request.name

        for i, turtle in enumerate(turtle_array):
            if turtle.name == name_to_remove:
                turtle_array.pop(i)
                break
        return response
    
    def callback_turtle_array(self, msg):
        self.TurtleArray.turtle_array.append(msg)
        self.publisher_.publish(self.TurtleArray)
        
def main(args=None):
    rclpy.init(args=args)
    node = TurtleMonitorNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()