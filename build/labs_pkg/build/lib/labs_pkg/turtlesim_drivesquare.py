import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import numpy as np
import math
import time

class TurtleSquareDriver(Node):
    def __init__(self):
        super().__init__('turtle_square_driver')
        time.sleep(1.0)
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.subscription_odom_ = self.create_subscription(Odometry, 'odom', self.odom_callback, 10)
        self.linear_speed = 2.0
        self.angular_speed = 7.0
        self.current_pose = None
        self.goal_index = 1
        self.ref_goals_ = [(0.0, 0.0), (4.0, 0.0), (4.0, 4.0), (0.0, 4.0)]
        self.ref_goals_ = np.asarray(self.ref_goals_)
        self.counter = 0
        self.rotation_goal = 0

    def odom_callback(self, msg):
        # Update pose and angle from Odometry messages
        self.current_pose = msg.pose.pose
        # Quaternion Orientation to Theta (0, 2pi) 
        self.theta = 2 * math.atan2(self.current_pose.orientation.z, self.current_pose.orientation.w)
        if self.theta < 0:
            self.theta = abs((abs(self.theta)) - math.pi) + math.pi
        else:
            self.theta = self.theta
        
        # Initialization on the first callback
        if self.counter == 0:
            self.starting_x = self.current_pose.position.x
            self.starting_y = self.current_pose.position.y
            self.starting_theta = self.theta
            self.counter += 1
            self.set_goal()
        self.move()

    def move(self):
        tolerance = 0.001
        vel_msg = Twist()
        
        ydist_to_goal = self.goal_position_absolute[1] - self.current_pose.position.y
        xdist_to_goal = self.goal_position_absolute[0] - self.current_pose.position.x
        dist_to_goal = math.sqrt(xdist_to_goal**2 + ydist_to_goal**2)
        self.rotation_goal = math.atan2(ydist_to_goal, xdist_to_goal)
        angle_error = self.rotation_goal - self.theta
        angle_error = math.atan2(math.sin(angle_error), math.cos(angle_error))

        if abs(angle_error) > tolerance:
            vel_msg.angular.z = (self.angular_speed * angle_error)
            vel_msg.linear.x = 0.0
        elif dist_to_goal > tolerance:
            vel_msg.linear.x = self.linear_speed * dist_to_goal
            vel_msg.angular.z = 0.0
        else:
            vel_msg.linear.x = 0.0
            vel_msg.angular.z = 0.0
            self.vel = 0.0
            self.length = 0.0
            self.goal_index = (self.goal_index + 1) % len(self.ref_goals_)
            self.set_goal()
        self.publisher_.publish(vel_msg)

    def set_goal(self):
        # set goal positions depending on the turtles starting orientation
        true_goal = self.rotate_point(self.ref_goals_[self.goal_index])
        self.goal_position_absolute = np.array([
            true_goal[0] + self.starting_x,
            true_goal[1] + self.starting_y
        ])


    def rotate_point(self, point):
        # Rotate a point based on the starting orientation of the turtle
        rotation_matrix = np.array([[np.cos(self.starting_theta), -np.sin(self.starting_theta)],
                                    [np.sin(self.starting_theta), np.cos(self.starting_theta)]])
        rotated_point = np.dot(rotation_matrix, np.array(point))
        return rotated_point

def main(args=None):
    rclpy.init(args=args)
    turtle_square_driver = TurtleSquareDriver()
    rclpy.spin(turtle_square_driver)
    turtle_square_driver.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
