#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class Add2IntsServerNode(Node):
    def __init__(self):
        super().__init__("add2ints_server")
        self.server_ = self.create_service(AddTwoInts, "add2ints", self.callback_add2ints)
        self.get_logger().info("The add two integer server has started.")
        
    def callback_add2ints(self, request, response):
        response.sum = request.a + request.b
        self.get_logger().info(str(request.a) + " + " + str(request.b) + " = " + str(response.sum))
        return response
    
def main(args=None):
    rclpy.init(args=args)
    node = Add2IntsServerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.destroy_node()
        rclpy.shutdown()
        
if __name__ == "__main__":
    main()