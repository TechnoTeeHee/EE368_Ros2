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
        self.spinning = False
        self.distance_to_goal = 0

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
        self.move()

    def move(self):
        twist = Twist()
        twist.linear.x = 0.0

        # Handle 90-degree turns
        if self.spinning:
            self.turn_turtle_90_degrees()
            return

        # Move to the next goal if the current goal is reached
        if self.has_reached_goal():
            self.spinning = True
            self.get_rotation_goal()
            self.goal_index = (self.goal_index + 1) % 4
            self.counter = 1
            self.has_reached_goal()
        else:
            #if not turning and not at goal go forward
            twist.linear.x = self.linear_speed * self.distance_to_goal
        self.publisher_.publish(twist)

    def turn_turtle_90_degrees(self):
        twist = Twist()
        if abs(self.theta - self.rotation_goal) < 0.00001:
            twist.angular.z = 0.0
            self.spinning = False
        else:
            angle_error = self.rotation_goal - self.theta
            angle_error = math.atan2(math.sin(angle_error), math.cos(angle_error))
            twist.angular.z = self.angular_speed * angle_error       
        self.publisher_.publish(twist)

    def get_rotation_goal(self):
        # Set the goal angle to 90-degrees from the turtles orientation
        self.rotation_goal = (self.theta + math.radians(90)) % math.radians(360)

    def has_reached_goal(self):
        # set goal positions depending on the turtles starting orientation
        true_goal = self.rotate_point(self.ref_goals_[self.goal_index])
        self.goal_position_absolute = np.array([
            true_goal[0] + self.starting_x,
            true_goal[1] + self.starting_y
        ])
        # Calculate the distance to the goal
        self.distance_to_goal = np.linalg.norm(
            np.array([self.current_pose.position.x, self.current_pose.position.y]) - self.goal_position_absolute
        )
        return self.distance_to_goal < 0.01

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
