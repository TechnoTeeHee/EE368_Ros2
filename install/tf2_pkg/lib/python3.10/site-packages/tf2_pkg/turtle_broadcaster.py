#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
import numpy as np
from turtlesim.msg import Pose
from math import pi, sin, cos
from geometry_msgs.msg import TransformStamped
from example_interfaces.msg import Int64
from lab_interfaces.msg import Turtle
from lab_interfaces.msg import TurtleArray
from lab_interfaces.srv import CaptureTurtle

class TurtleBroadcaster(Node):
    def __init__(self):
        super().__init__("turtle_broadcaster")
        self.alive_turtles = None
        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtles", self.get_alive_turtles, 10)
        self.turtle_broadcaster = tf2_ros.StaticTransformBroadcaster(self)
        self.broadcast_tf_message()
        self.timer = self.create_timer(0.1, self.broadcast_tf_message)
        self.get_logger().info("turtle_broadcaster is ready")
        
    def get_alive_turtles(self, msg):
        self.alive_turtles = msg
        
    def broadcast_tf_message(self):
        if self.alive_turtles == None or len(self.alive_turtles.turtles) == 0:
            return
        for i in range(len(self.alive_turtles.turtles)):
            self.transform_stamped = TransformStamped()
            self.transform_stamped.header.frame_id = "world"
            self.transform_stamped.child_frame_id = str(self.alive_turtles.turtles[int(i)].name)
            self.transform_stamped.header.stamp = self.get_clock().now().to_msg()
            self.transform_stamped.transform.translation.x = self.alive_turtles.turtles[int(i)].x
            self.transform_stamped.transform.translation.y = self.alive_turtles.turtles[int(i)].y
            q = euler_to_quaternion(0, 0, self.alive_turtles.turtles[int(i)].theta)
            self.transform_stamped.transform.rotation.x = q[0]
            self.transform_stamped.transform.rotation.y = q[1]
            self.transform_stamped.transform.rotation.z = q[2]
            self.transform_stamped.transform.rotation.w = q[3]
            self.turtle_broadcaster.sendTransform(self.transform_stamped)
        
        
def euler_to_quaternion(roll, pitch, yaw):
    q = np.empty((4, ))
    q[0] = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2)
    q[1] = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2)
    q[2] = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2)
    q[3] = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2)
    return q

def main(args=None):
    rclpy.init(args=args)
    node = TurtleBroadcaster()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
if __name__ == '__main__':
    main()