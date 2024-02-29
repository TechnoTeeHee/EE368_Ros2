#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np
class listenerNode(Node):
    def __init__(self):
        super().__init__('listener')
        self.tf_buffer_ = Buffer()
        self.tf_listener_ = TransformListener(self.tf_buffer_, self)
        self.timer = self.create_timer(1.0, self.listen_tf_message)

    def listen_tf_message(self):
        origin_frame = "world"
        dest_frame_tf1 = "tf1"
        dest_frame_tf2 = "tf2"
        try:
            tf1 = self.tf_buffer_.lookup_transform(origin_frame, dest_frame_tf1 ,rclpy.time.Time())
            q = [tf1.transform.rotation.x, tf1.transform.rotation.y,
            tf1.transform.rotation.z, tf1.transform.rotation.w]
            e = quaternion_to_euler_degrees(q)        
            self.get_logger().info(f"{origin_frame} to {dest_frame_tf1}: y = {round(tf1.transform.translation.y,1)}, x = {tf1.transform.translation.x}")
            tf2 = self.tf_buffer_.lookup_transform(origin_frame, dest_frame_tf2, rclpy.time.Time())
            q = [tf2.transform.rotation.x, tf2.transform.rotation.y,
            tf2.transform.rotation.z, tf2.transform.rotation.w]
            e = quaternion_to_euler_degrees(q)
            self.get_logger().info(f"{origin_frame} to {dest_frame_tf2}: y = {round(tf2.transform.translation.y,1)}, x = {tf2.transform.translation.x}")
            if round(tf1.transform.translation.x,1) > round(tf2.transform.translation.x,1):
                self.get_logger().info("TF1 has greater x")
            else:
                self.get_logger().info("TF2 has greater x")
            if round(tf1.transform.translation.y,1) > round(tf2.transform.translation.y,1):
                self.get_logger().info("TF1 has greater y")
            else:
                self.get_logger().info("TF2 has greater y")
        except tf2_ros.TransformException as ex:
            self.get_logger().info(f'Could not transform {origin_frame} to {dest_frame_tf1}: {ex}')

            
            
def quaternion_to_euler_degrees(q):
    e = np.empty((3, ))
    t0 = 2.0 * (q[3]*q[0] + q[1]*q[2])
    t1 = 1.0 - 2.0 * (q[0]*q[0] + q[1]*q[1])
    e[0] = np.degrees(np.arctan2(t0,t1))
    t2 = 2.0 * (q[3]*q[1] - q[2]*q[0])
    t2 = 1.0 if t2 > 1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    e[1] = np.degrees(np.arcsin(t2))
    t3 = 2.0 * (q[3]*q[2] + q[0]*q[1])
    t4 = 1.0 - 2.0 * (q[1]*q[1] + q[2]*q[2])
    e[2] = np.degrees(np.arctan2(t3,t4))
    return e

def main():
    rclpy.init()
    node = listenerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()
if __name__ == '__main__':
    main()