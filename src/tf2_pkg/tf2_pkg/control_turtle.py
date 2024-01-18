#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from lab_interfaces.msg import TurtleArray
from lab_interfaces.srv import CaptureTurtle
from functools import partial

Kv = 2.0
Ka = 6.0

class TurtlesimMoveNode(Node):
    def __init__(self):
        super().__init__("control_turtle")
        self.declare_parameter("kv", Kv)
        self.declare_parameter("ka", Ka)
        self.kv = self.get_parameter("kv").value
        self.ka = self.get_parameter("ka").value
        self.goal_x = 0
        self.goal_y = 0
        self.pose_ = None
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        self.alive_turtles = None
        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtles", self.get_alive_turtles, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.01, self.turtle_move)
        self.get_logger().info('The control monitor has started.')

    def get_alive_turtles(self, msg):
        self.alive_turtles = msg

    def get_turtle_pose(self, msg):
        self.pose_ = msg

    def turtle_move(self):
        if self.pose_ == None:
            return
        if self.alive_turtles == None or len(self.alive_turtles.turtles) == 0:
            return
        
        # Determine closest turtle
        index = 0
        closest = -1
        for i in range(len(self.alive_turtles.turtles)):
            x = self.alive_turtles.turtles[i].x - self.pose_.x
            y = self.alive_turtles.turtles[i].y - self.pose_.y
            distance = math.sqrt(x**2 + y**2)
            if closest == -1 or distance < closest:
                index = i
                closest = distance
        self.goal_x = self.alive_turtles.turtles[index].x
        self.goal_y = self.alive_turtles.turtles[index].y
        xdist_to_goal = self.goal_x - self.pose_.x
        ydist_to_goal = self.goal_y - self.pose_.y
        dist_to_goal = math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
        vel_msg = Twist()
        
        if dist_to_goal > 0.2:
            vel_msg.linear.x = self.kv * (dist_to_goal)
            goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
            angle_error = goal_angle - self.pose_.theta
            angle_error = math.atan2(math.sin(angle_error),math.cos(angle_error))
            vel_msg.angular.z = self.ka * angle_error
        else:
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
            self.capture_turtle(self.alive_turtles.turtles[index].name)
            self.alive_turtles = None

        self.cmd_vel_publisher_.publish(vel_msg)

        #self.get_logger().info('Angular velocity published: ' + str(vel_msg.angular.z))
        #self.get_logger().info('Linear velocity published: ' + str(vel_msg.linear.x))

    def capture_turtle(self, turtle_name):
        client = self.create_client(CaptureTurtle, "capture_turtle")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for turtlesim Server")
        request = CaptureTurtle.Request()
        request.name = turtle_name
        self.get_logger().info("Sending request to capture turtle '" + str(turtle_name) + "'.")
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_capture_turtle, name=turtle_name))

    def callback_capture_turtle(self, future, name):
        try:
            response = future.result()
            self.get_logger().info("Service completed: " + str(response.message))
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