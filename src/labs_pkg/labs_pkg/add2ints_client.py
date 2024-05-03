#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial
from example_interfaces.srv import AddTwoInts

class Add2IntsClientNode(Node):
    def __init__(self):
        super().__init__("add2ints_client")
        self.call_add2ints_server(11, 7)
        self.call_add2ints_server(5, 5)
        
    def call_add2ints_server(self, a, b):
        client = self.create_client(AddTwoInts, "add2ints")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Add2Ints Server")
        request = AddTwoInts.Request()
        request.a = a
        request.b = b
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_add2ints, a=a, b=b))
            
    def callback_call_add2ints(self, future, a, b):
        try:
            response = future.result()
            self.get_logger().info(str(a) + " + " +str(b) + " = " + str(response.sum))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
            
def main(args=None):
    rclpy.init(args=args)
    node = Add2IntsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()