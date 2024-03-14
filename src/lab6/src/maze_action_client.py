import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import Maze

class MazeActionClient(Node):
    def __init__(self):
        super().__init__('maze_action_client')
        self._action_client = ActionClient(self, Maze, 'maze')
        self.get_logger().info('MazeActionClient ready... ')

    def send_goal(self, goal_coordinates):
        goal_msg = Maze.Goal()
        goal_msg.goal_coordinates = goal_coordinates
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
        self.get_logger().info('Result: {0} seconds'.format(result.goal_time))
        rclpy.shutdown()
    
    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        if feedback.goal_update:
            self.get_logger().info('Goal = {0}'.format(feedback.n_goal))
            self.get_logger().info('x = {0}'.format(feedback.current_goal[0]))
            self.get_logger().info('y = {0}'.format(feedback.current_goal[1]))
        else:
            self.get_logger().info('Received feedback: sim time = {0}, x = {1}, y = {2} angle = {3}'.format(round(feedback.time,3), round(feedback.x,3), round(feedback.y,3), round(feedback.z,3)))

def main(args=None):
    rclpy.init(args=args)
    maze_action_client = MazeActionClient()
    maze_action_client.send_goal([5.0, 0.0, 5.0, -4.0, 0.0, -4.0, 0.0, -8.0, 7.0, -8.0, 7.0, 2.0, -2.0, 2.0])
    rclpy.spin(maze_action_client)

if __name__ == '__main__':
    main()