#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

def main(args=None):
    rclpy.init(args=args)
    node = Node("add2ints_client_no_oop")
    client = node.create_client(AddTwoInts, "add2ints")
    while not client.wait_for_service(1.0):
        node.get_logger().warn("Waiting for Add2Ints Server")
    request = AddTwoInts.Request()
    request.a = 5
    request.b = 10
    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future)
    try:
        response = future.result()
        node.get_logger().info(str(request.a) + " + " + str(request.b) + " = " + str(response.sum))
    except Exception as e:
        node.get_logger().error("Service call failed %r" % (e,))
    
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()