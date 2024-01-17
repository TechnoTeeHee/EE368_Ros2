#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from lab_interfaces.msg import Turtle
from lab_interfaces.msg import TurtleArray
from turtlesim.srv import Kill
from std_srvs.srv import Empty
from lab_interfaces.srv import CaptureTurtle


class ControlTurtleNode(Node):
    def __init__(self):
        super().__init__("control_turtle")
        self.declare_parameter("angular_gain", 7.0)
        self.declare_parameter("linear_gain", 2.0)
        self.angular_ = self.get_parameter("angular_gain").value
        self.linear_ = self.get_parameter("linear_gain").value
        self.goal_x = None
        self.goal_y = None
        self.pose_ = None
        self.alive_turtles_array = TurtleArray()
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.get_turtle_pose, 10)
        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtles", self.get_turtle_array, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.move_timer_ = self.create_timer(0.01, self.turtle_move)
        self.kill = self.create_client(Kill, "kill")
        self.capture_turtle_client = self.create_client(CaptureTurtle, "capture_turtle")
    
    def get_turtle_pose(self,msg):
        self.pose_ = msg
        
    def get_turtle_array(self,msg):
        self.alive_turtles_array = msg.turtle_array
        if not len(self.alive_turtles_array) == 0:
            min_distance = float('inf')
            closest_turtle = None
            reference_x = self.pose_.x
            reference_y = self.pose_.y
            for turtle in self.alive_turtles_array:
                distance = math.sqrt((turtle.x - reference_x)**2 + (turtle.y - reference_y)**2)
                if distance < min_distance:
                    min_distance = distance
                    closest_turtle = turtle
            self.goal_x = closest_turtle.x
            self.goal_y = closest_turtle.y
        
    def turtle_move(self):
        if self.pose_ == None or self.goal_x == None or self.goal_y == None:
            return
        xdist_to_goal = self.goal_x - self.pose_.x
        ydist_to_goal = self.goal_y - self.pose_.y
        dist_to_goal = math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
        kv = self.linear_
        ka = self.angular_
        vel_msg = Twist()
        if dist_to_goal > 0.2:
            vel_msg.linear.x = kv*dist_to_goal
            goal_angle = math.atan2(ydist_to_goal, xdist_to_goal)
            angle_error = goal_angle - self.pose_.theta
            angle_error = math.atan2(math.sin(angle_error),math.cos(angle_error))
            vel_msg.angular.z = ka*angle_error
        else:
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
            if not len(self.alive_turtles_array) == 0:
                min_distance = float('inf')
                closest_turtle = None
                reference_x = self.pose_.x
                reference_y = self.pose_.y
                for turtle in self.alive_turtles_array:
                    distance = math.sqrt((turtle.x - reference_x)**2 + (turtle.y - reference_y)**2)
                    if distance < min_distance:
                        min_distance = distance
                        closest_turtle = turtle
                self.get_logger().info(str(closest_turtle.name))
                self.kill.call_async(Kill.Request(name=closest_turtle.name))
                request = CaptureTurtle.Request()
                request.name = closest_turtle.name
                self.capture_turtle_client.call_async(request)
                self.goal_x = None
                self.goal_y = None
        self.cmd_vel_publisher_.publish(vel_msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = ControlTurtleNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()