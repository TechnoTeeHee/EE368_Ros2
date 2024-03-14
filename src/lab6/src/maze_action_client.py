import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import Maze

class MazeActionClient(Node):
    def __init__(self):
        super().__init__('maze_action_client')
        self._action_client = ActionClient(self, Maze, 'maze')
        self.get_logger().info('MazeActionClient ready... ')

    def send_goal(self, goal_positions):
        goal_msg = Maze.Goal()
        goal_msg.goal_positions = goal_positions
        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)
    
    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected :(')
            return
        self.get_logger().info('Goal accepted :)')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)
    
    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Result: {0}'.format(round(result.final_time, 2)))
        rclpy.shutdown()
    
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        if feedback.goal_reached == 0:
            self.get_logger().info('########################################################')
            self.get_logger().info('Goal #{0}:         [{1}, {2}]'.format(feedback.goal_num, feedback.current_goal[0], feedback.current_goal[1]))
        else:
            self.get_logger().info('Received feedback: {0} {1} {2}'.format(round(feedback.time,1), round(feedback.current_x,1), round(feedback.current_y,1), round(feedback.yaw,1)))

def main(args=None):
    rclpy.init(args=args)
    maze_action_client = MazeActionClient()
    maze_action_client.send_goal([5.0,0.0, 5.0,-4.0, 0.0,-4.0, 0.0,-8.0, 7.0,-8.0, 7.0,2.0, -2.0,2.0])
    rclpy.spin(maze_action_client)

if __name__ == '__main__':
    main()