#! /usr/bin/env python3
import rclpy
from rclpy.node import Node
import tf2_ros
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

class TFListener(Node):
    def __init__(self):
        super().__init__('tf_listener')
        self.tf_buffer_ = Buffer()
        self.tf_listener_ = TransformListener(self.tf_buffer_, self)
        self.timer = self.create_timer(1.0, self.listen_tf_message)
        
    def listen_tf_message(self):
        origin_frame = "world"
        dest_frame = "center_y"
        try:
            t = self.tf_buffer_.lookup_transform(origin_frame, dest_frame, rclpy.time.Time())
            self.get_logger().info(f"The transform {origin_frame} to {dest_frame}:{t}")
        except tf2_ros.TransformException as ex:
            self.get_logger().info(f'Could not transform {origin_frame} to {dest_frame}: {ex}')
    
def main():
    rclpy.init()
    node = TFListener()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
            
if __name__ == '__main__':
    main()