import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from geometry_msgs.msg import Twist

class MoveTowardsRedCube(Node):
    def __init__(self):
        super().__init__('move_towards_red_cube')
        self.br = CvBridge()
        self.image_subscription = self.create_subscription(Image, '/your_camera_topic', self.process_camera, 10)
        self.image_subscription

        self.cmd_vel_publisher = self.create_publisher(Twist, '/your_robot_cmd_vel_topic', 10)

        self.cX = -1
        self.cY = -1

    def process_camera(self, msg):
        # “msg” is ROS 2 Image message

        # Convert image from ROS to OpenCV
        # self.br previous set via self.br = CvBridge()
        rosImage = self.br.imgmsg_to_cv2(msg, "bgr8")

        # Convert to HSV
        hsvImage = cv2.cvtColor(rosImage, cv2.COLOR_BGR2HSV)

        # lower mask (0-10) for Red
        lower_red = np.array([0,50,50])
        upper_red = np.array([10,255,255])
        mask0 = cv2.inRange(hsvImage, lower_red, upper_red)

        # upper mask (170-180) for Red
        lower_red = np.array([170,50,50])
        upper_red = np.array([180,255,255])
        mask1 = cv2.inRange(hsvImage, lower_red, upper_red)

        # Join masks and display
        mask = mask0 + mask1
        cv2.imshow("Mask", mask)
        cv2.waitKey(1)

        # calculate moments of binary image
        M = cv2.moments(mask)
 
        # calculate x,y coordinate of center
        if M["m00"] != 0:
            self.cX = int(M["m10"] / M["m00"])
            self.cY = int(M["m01"] / M["m00"])
        else:
            self.cX = -1
            self.cY = -1
        self.get_logger().info(f"cX={self.cX} cY={self.cY}")
        self.move_towards_red_cube()


    def move_towards_red_cube(self):
        linear_speed = 0.5
        angular_speed = 0.1
        twist_msg = Twist()
        if self.cX != -1:
            if self.cX > 320:  # Assuming the image width is 640
                twist_msg.linear.x = linear_speed
            elif self.cX < 320:
                twist_msg.angular.z = angular_speed

        self.cmd_vel_publisher.publish(twist_msg)


def main(args=None):
    rclpy.init(args=args)
    move_towards_red_cube = MoveTowardsRedCube()
    rclpy.spin(move_towards_red_cube)
    move_towards_red_cube.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
