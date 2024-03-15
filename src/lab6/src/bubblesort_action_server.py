import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import Bubblesort

class BubblesortActionServer(Node):
    def __init__(self):
        super().__init__('bubblesort_action_server')
        self.bubblesort_action_server = ActionServer(
            self,
            Bubblesort,
            'bubblesort',
            self.execute_callback)
        self.get_logger().info('BubblesortActionServer ready... ')

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        feedback_msg = Bubblesort.Feedback()

        feedback_msg.partial_sequence = goal_handle.request.order

        
        for i in range(len(feedback_msg.partial_sequence) - 1):
            for j in range(len(feedback_msg.partial_sequence) - 1 - i):
                feedback_msg.i = i
                feedback_msg.j = j
                if (feedback_msg.partial_sequence[j] > feedback_msg.partial_sequence[j + 1]):
                    temp = feedback_msg.partial_sequence[j]
                    feedback_msg.partial_sequence[j] = feedback_msg.partial_sequence[j + 1]
                    feedback_msg.partial_sequence[j + 1] = temp
                
                goal_handle.publish_feedback(feedback_msg)
                time.sleep(0.1)

        goal_handle.succeed()
        result = Bubblesort.Result()
        result.sequence = feedback_msg.partial_sequence
        result.i = feedback_msg.i
        result.j = feedback_msg.j
        return result

def main(args=None):
    rclpy.init(args=args)
    bubblesort_action_server = BubblesortActionServer()
    rclpy.spin(bubblesort_action_server)
if __name__ == '__main__':
    main()