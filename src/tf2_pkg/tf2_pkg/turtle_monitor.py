#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64
from lab_interfaces.msg import Turtle
from lab_interfaces.msg import TurtleArray
from lab_interfaces.srv import CaptureTurtle
from turtlesim.srv import Kill
import time

class MyListenerNode(Node):
    def __init__(self):
        super().__init__("turtle_monitor")
        self.subscriber_ = self.create_subscription(Turtle, "new_turtle", self.callback, 10)
        time.sleep(0.1)
        self.publisher_ = self.create_publisher(TurtleArray, "alive_turtles", 10)
        self.turtle_array = []
        self.server_ = self.create_service(CaptureTurtle, "capture_turtle", self.callback_capture_turtle)
        self.get_logger().info('The turtle monitor has started.')

    def callback(self, msg):
        turtle = Turtle()
        turtle.name = msg.name
        turtle.x = msg.x
        turtle.y = msg.y
        turtle.theta = msg.theta
        self.turtle_array.append(turtle)
        msg = TurtleArray()
        msg.turtles = self.turtle_array
        self.publisher_.publish(msg)

    def callback_capture_turtle(self, request, response):
        # Search for name in current list
        #self.get_logger().info("Received request to capture '" + str(request.name) + "'.")
        found = False
        for i in range(len(self.turtle_array)):
            if self.turtle_array[i].name == request.name:
                found = True
                self.turtle_array.pop(i)
                                
                # Reissue new alive turtles
                msg = TurtleArray()
                msg.turtles = self.turtle_array
                self.publisher_.publish(msg)

                self.kill_a_turtle(request.name)
                break
        if found:
            response.status = True
            response.message = 'Okay'
        else:
            response.status = False
            response.message = "ERROR: Could not find turtle '" + str(request.name) + "'."

        return response
    
    def kill_a_turtle(self, turtle_name):
        client = self.create_client(Kill, "kill")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for turtlesim Server")
        request = Kill.Request()
        request.name = turtle_name
        #self.get_logger().info("Killing " + str(turtle_name))
        client.call_async(request)

def main(args=None):
    rclpy.init(args=args)
    node = MyListenerNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()

if __name__ == "__main__":
    main()