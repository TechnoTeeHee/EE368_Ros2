import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from action_interfaces.action import Maze
from rosgraph_msgs.msg import Clock
import time
import subprocess

gStartTime = time.time_ns()

def MyPrint(str):
    deltaTime = time.time_ns() - gStartTime
    secs = int(deltaTime / 1000000000.0)
    msecs = int((deltaTime - secs * 1000000000.0) / 1000000)
    print(f"{secs:03d}.{msecs:03d} {str}\r")
    
class sInfo:
    sim_clock = 0.0
    start_time = 0.0
    
def elapse_time():
    return sInfo.sim_clock - sInfo.start_time

class ClockClient(Node):
    def __init__(self):
        super().__init__('clock_client')
        self.clock_subscriber = self.create_subscription(Clock, "/clock", self.process_clock, 10)
        MyPrint('ClockClient ready... ')

    def process_clock(self, message):
        sInfo.sim_clock = message.clock.sec + (message.clock.nanosec / 1e9)
        if sInfo.start_time == 0:
            sInfo.start_time = sInfo.sim_clock

class MazeActionClient(Node):
    def __init__(self):
        super().__init__('maze_action_client')
        self._action_client = ActionClient(self, Maze, 'maze')
        self.waypointDone = False
        MyPrint('MazeActionClient ready... ')

    def send_goal(self, index):
        self.index = index
        goal_msg = Maze.Goal()
        goal_msg.index = index
        self.waypointDone = False
        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            MyPrint(f"Goal rejected.")
            self.waypointDone = True
            return
        #MyPrint(f"Goal accepted.")
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        MyPrint(f"Result  : ({elapse_time():5.1f} s): #{result.index} distance={result.distance:.1f} DONE")
        self.waypointDone = True

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        MyPrint(f"Feedback: ({elapse_time():5.1f} s): #{feedback.index} distance={feedback.distance:.1f} direction={feedback.direction}")

    def done(self):
        return self.waypointDone

def ResetPosition():
    subprocess.run([
        "ign", 
        "service",
        "-s",
        "/world/followTheLeader/set_pose",
        "--reqtype",
        "ignition.msgs.Pose",
        "--reptype",
        "ignition.msgs.Boolean",
        "--timeout",
        "300",
        "--req",
        "name:\"chase\",position:{x:8.0,y:0.0,z:0.05}"
    ], capture_output=True)
    time.sleep(1.0)
            

def main(args=None):
    rclpy.init(args=args)
    action_client = MazeActionClient()
    clock_client = ClockClient()
    
    try:
        index = 0
        rclpy.spin_once(clock_client)
        while index < 3:
            rclpy.spin_once(clock_client)
            MyPrint(f"##################################################")
            MyPrint(f"Goal #{index}")
            ResetPosition();
            action_client.send_goal(index)
            while action_client.done() == False:
                rclpy.spin_once(clock_client)
                rclpy.spin_once(action_client)
                time.sleep(0.01)
            index = index + 1
        MyPrint(f"##################################################")
        rclpy.spin_once(clock_client)
        MyPrint(f"Total simulation time = {elapse_time():.1f} s")
        ResetPosition();
    except KeyboardInterrupt:
        print("\nKeyboardInterrupt...")
    
if __name__ == '__main__':
    main()
