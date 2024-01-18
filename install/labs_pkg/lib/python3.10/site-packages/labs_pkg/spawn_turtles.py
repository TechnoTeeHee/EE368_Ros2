#!/usr/bin/env python3
import random
import math
import rclpy
from rclpy.node import Node
from turtlesim.srv import Spawn
from lab_interfaces.msg import Turtle
from lab_interfaces.msg import TurtleArray

class SpawnTurtlesNode(Node):
    def __init__(self):
        super().__init__("spawn_turtles")
        self.declare_parameter("turtle_name_prefix", "turtle")
        self.declare_parameter("publish_rate", 1)
        self.name_ = self.get_parameter("turtle_name_prefix").value
        self.publish_rate_ = self.get_parameter("publish_rate").value
        self.count_ = 1
        self.spawn_timer_ = self.create_timer(1/self.publish_rate_, self.spawn_a_turtle)
        self.spawner = self.create_client(Spawn, 'spawn')
        self.publisher_ = self.create_publisher(Turtle, "new_turtle", 10)
        
    def spawn_a_turtle(self):
        self.count_ += 1
        name = self.name_ + str(self.count_)
        x = random.uniform(1, 10)
        y = random.uniform(1, 10)
        theta = random.uniform(0.0, 2*math.pi)
        self.call_turtlesim_spawn_server(name, x, y, theta)
    
    def call_turtlesim_spawn_server(self, turtle_name, x, y, theta):
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = turtle_name
        info = Turtle()
        info.name = turtle_name
        info.x = x
        info.y = y
        info.theta = theta
        self.publisher_.publish(info)
        self.result = self.spawner.call_async(request)
        
def main(args=None):
    rclpy.init(args=args)
    node = SpawnTurtlesNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()