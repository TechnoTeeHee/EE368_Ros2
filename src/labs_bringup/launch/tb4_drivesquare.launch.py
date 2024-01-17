from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    ld = LaunchDescription()

    # launch turtlebot drivesquare program
    drivesquare_node = Node(
        package="labex6",
        executable="tb4_drivesquare",
    )
    
    ld.add_action(drivesquare_node)

    return ld
