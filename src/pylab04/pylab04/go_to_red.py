import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np
from sensor_msgs.msg import Image, LaserScan
from geometry_msgs.msg import Twist

class MoveTowardsRedCube(Node):
    def __init__(self):
        super().__init__('move_towards_red_cube')
        self.br = CvBridge()
        self.cX = -1
        self.cY = -1
        self.isOnCamera = False
        self.publisher_ = self.create_publisher(Twist, '/cmd_vel', 10)
        self.subscription_camera = self.create_subscription(Image, '/camera/image_raw', self.process_camera, 10)
        self.subscription_lidar = self.create_subscription(LaserScan, '/scan', self.lidar_callback, 10)

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
            self.isOnCamera = abs(self.cX - 320) < 64
        else:
            self.cX = -1
            self.cY = -1
        self.get_logger().info(f"cX={self.cX} cY={self.cY}")


    def lidar_callback(self, msg):
        twist = Twist()
        if any(distance < 0.5 for distance in msg.ranges):
            twist.angular.z = 0.0
        elif self.isOnCamera:
            if self.isOnCamera:
                twist.linear.x = 0.5
                error = self.cX - 320  
                twist.angular.z = -error * 0.01
        else:
            twist = Twist()
            twist.angular.z = -0.5
        self.publisher_.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    move_towards_red_cube = MoveTowardsRedCube()
    rclpy.spin(move_towards_red_cube)
    move_towards_red_cube.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
