#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from lab_interfaces.msg import TurtleArray
from lab_interfaces.srv import CaptureTurtle
from functools import partial
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np
import time

Kv = 2.0
Ka = 6.0

class TurtlesimMoveNode(Node):
    def __init__(self):
        super().__init__("control_turtle")
        self.declare_parameter("kv", Kv)
        self.declare_parameter("ka", Ka)
        self.kv = self.get_parameter("kv").value
        self.ka = self.get_parameter("ka").value
        self.goal_x = None
        self.goal_y = None
        self.index = 0
        self.alive_turtles = None
        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtles", self.get_alive_turtles, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.01, self.turtle_move)
        #self.get_logger().info('The control monitor has started.')
        self.tf_buffer_ = Buffer()
        self.tf_listener_ = TransformListener(self.tf_buffer_, self)
        time.sleep(1.0)
        self.timer = self.create_timer(0.01, self.listen_tf_message)
        
        
    def listen_tf_message(self):
        if self.alive_turtles == None or len(self.alive_turtles.turtles) == 0:
            return
        origin_frame = "world"
        dest_frame = "turtle1"
        try:
            t = self.tf_buffer_.lookup_transform(origin_frame, dest_frame, rclpy.time.Time())
            q = [t.transform.rotation.x, t.transform.rotation.y,
            t.transform.rotation.z, t.transform.rotation.w]     
            self.x = round(t.transform.translation.x,1)
            self.y = round(t.transform.translation.y,1)
            self.theta = t.transform.rotation.z*math.pi
        except tf2_ros.TransformException as ex:
            self.get_logger().info(f'Could not transform {origin_frame} to {dest_frame}: {ex}')
        
        self.index = 0
        closest = -1
        try:
            for i in range(len(self.alive_turtles.turtles)):
                n = self.tf_buffer_.lookup_transform("turtle1", str(self.alive_turtles.turtles[i].name), rclpy.time.Time())
                x = n.transform.translation.x
                y = n.transform.translation.y
                distance = math.sqrt(x**2 + y**2)
                if closest == -1 or distance < closest:
                    self.index = i
                    closest = distance
            g = self.tf_buffer_.lookup_transform("world", self.alive_turtles.turtles[self.index].name, rclpy.time.Time())       
            self.goal_x = g.transform.translation.x 
            self.goal_y = g.transform.translation.y
        except tf2_ros.TransformException as ex:
            return

    def get_alive_turtles(self, msg):
        self.alive_turtles = msg

    def turtle_move(self):
        if self.alive_turtles == None or len(self.alive_turtles.turtles) == 0 or self.goal_x == None:
            return

        xdist_to_goal = self.goal_x - self.x
        ydist_to_goal = self.goal_y - self.y
        dist_to_goal = math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
        vel_msg = Twist()
        
        if dist_to_goal > 0.5:
            vel_msg.linear.x = self.kv * (dist_to_goal)
            goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
            angle_error = goal_angle - self.theta
            angle_error = math.atan2(math.sin(angle_error),math.cos(angle_error))
            vel_msg.angular.z = self.ka * angle_error
        else:
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
            self.capture_turtle(str(self.alive_turtles.turtles[self.index].name))
            self.alive_turtles = None
            self.goal_x = None

        self.cmd_vel_publisher_.publish(vel_msg)

        #self.get_logger().info('Angular velocity published: ' + str(vel_msg.angular.z))
        #self.get_logger().info('Linear velocity published: ' + str(vel_msg.linear.x))

    def capture_turtle(self, turtle_name):
        client = self.create_client(CaptureTurtle, "capture_turtle")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for turtlesim Server")
        request = CaptureTurtle.Request()
        request.name = turtle_name
        #self.get_logger().info("Sending request to capture turtle '" + str(turtle_name) + "'.")
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_capture_turtle, name=turtle_name))

    def callback_capture_turtle(self, future, name):
        try:
            response = future.result()
            #self.get_logger().info("Service completed: " + str(response.message))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
            

def main(args=None):
    rclpy.init(args=args)
    node = TurtlesimMoveNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        print("\nKeyboardInterrupt...")
        node.destroy_node()

if __name__ == "__main__":
    main()