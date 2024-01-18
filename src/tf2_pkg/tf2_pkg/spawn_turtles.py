#!/usr/bin/env python3
import random
import math
import rclpy
from rclpy.node import Node
from lab_interfaces.msg import Turtle
from turtlesim.srv import Spawn
from functools import partial

class SpawnTurtlesNode(Node):
    def __init__(self):
        super().__init__("spawn_turtles")
        self.declare_parameter("name_prefix", "turtle")
        self.declare_parameter("spawn_rate", 1.0)
        self.name_prefix = self.get_parameter("name_prefix").value
        self.spawn_rate = self.get_parameter("spawn_rate").value
        self.count_ = 1
        self.publisher_ = self.create_publisher(Turtle, "new_turtle", 10)
        self.spawn_timer_ = self.create_timer((1.0 / self.spawn_rate), self.spawn_a_turtle)
        self.get_logger().info('The spawn turtles has started.')

    def spawn_a_turtle(self):
        self.count_ += 1
        name = self.name_prefix + str(self.count_)
        x = random.uniform(1, 10)
        y = random.uniform(1, 10)
        theta = random.uniform(0.0, 2*math.pi)
        self.call_turtlesim_spawn_server(name, x, y, theta)

    def call_turtlesim_spawn_server(self, turtle_name, x, y, theta):
        client = self.create_client(Spawn, "spawn")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for turtlesim Server")
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = turtle_name
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_add2ints, name=turtle_name, x=x, y=y, theta=theta))

    def callback_call_add2ints(self, future, name, x, y, theta):
        try:
            response = future.result()
            #self.get_logger().info("Spawned " + str(response.name))
            msg = Turtle()
            msg.name = name
            msg.x = x
            msg.y = y
            msg.theta = theta
            self.publisher_.publish(msg)
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))

def main(args=None):
    rclpy.init(args=args)
    node = SpawnTurtlesNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\nKeyboardInterrupt...")
        node.destroy_node()

if __name__ == "__main__":
    main()