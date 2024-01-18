import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import numpy as np
import math

class TB4DriveSquare(Node):
    def __init__(self):
        super().__init__('tb4_drivesquare')
        self.publisher_ = self.create_publisher(Twist, "cmd_vel", 10)
        self.subscriber_odom_ = self.create_subscription(Odometry, 'odom', self.odom_callback, QoSProfile(depth=10, reliability=QoSReliabilityPolicy.BEST_EFFORT))
        self.linear_speed = 0.3
        self.angular_speed = 0.3
        self.current_pose = None
        self.goal_index = 1
        self.ref_goals_ = [(0.0, 0.0), (1.0, 0.0), (1.0, 1.0), (0.0, 1.0)]  # Reference goals for creating a square
        self.ref_goals_ = np.asarray(self.ref_goals_)
        self.counter = 0
        self.rotation_goal = 0
        self.spinning = False  # Flag to indicate if the robot is currently spinning
        self.distance_to_goal = 0

    def odom_callback(self, msg):
        # Callback function to update the current pose based on Odometry messages
        self.current_pose = msg.pose.pose
        # Extract the theta from the quaternion representation
        self.theta = 2 * math.atan2(self.current_pose.orientation.z, self.current_pose.orientation.w)
        # Ensure theta is rempped to a new range (0, 2*pi)
        if self.theta < 0:
            self.theta = abs((abs(self.theta)) - math.pi) + math.pi
        else:
            self.theta = self.theta
        if self.counter == 0:
            # Initialize starting position and angle on the first callback (has to be here since it needs the odometry)
            self.starting_x = self.current_pose.position.x
            self.starting_y = self.current_pose.position.y
            self.starting_theta = self.theta
            self.counter += 1
            self.set_goal()
        self.move()  # Call the move after you get new values

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
        # Function to set goal position
        true_goal = self.rotate_point(self.ref_goals_[self.goal_index])
        # Calculate the absolute goal position in the world frame
        self.goal_position_absolute = np.array([
            true_goal[0] + self.starting_x,
            true_goal[1] + self.starting_y
        ])

    def rotate_point(self, point):
        # Function to rotate a point based on the starting angle of the robot
        rotation_matrix = np.array([[np.cos(self.starting_theta), -np.sin(self.starting_theta)],
                                    [np.sin(self.starting_theta), np.cos(self.starting_theta)]])
        rotated_point = np.dot(rotation_matrix, np.array(point))
        return rotated_point

def main(args=None):
    rclpy.init(args=args)
    node = TB4DriveSquare()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
