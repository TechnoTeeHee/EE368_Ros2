#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener
import numpy as np

class TFListener1(Node):
    def __init__(self):
        super().__init__('tf_listener1')
        self.tf_buffer_ = Buffer()
        self.tf_listener_ = TransformListener(self.tf_buffer_, self)
        self.timer = self.create_timer(1.0, self.listen_tf_message)
        
    def listen_tf_message(self):
        origin_frame = "world"
        dest_frame = "center_y"
        try:
            t = self.tf_buffer_.lookup_transform(origin_frame, dest_frame, rclpy.time.Time())
            q = [t.transform.rotation.x, t.transform.rotation.y, t.transform.rotation.z, t.transform.rotation.w]
            e = quaternion_to_euler_degrees(q)
            self.get_logger().info(f"{origin_frame} to {dest_frame}: y = {round(t.transform.translation.y,1)}, z = {t.transform.translation.z}, yaw = {round(e[2],1)}")
        except tf2_ros.TransformException as ex:
            self.get_logger().info(f'Could not transform {origin_frame} to {dest_frame}: {ex}')
   
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
    node = TFListener1()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
            
if __name__ == '__main__':
    main()