from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import time

def generate_launch_description():
    ld = LaunchDescription()

    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
    )

    odom_node = Node(xuu
        package="labs_pkg",
        executable="turtlesim_odom",
    )
    
    drivesquare_node = Node(
        package="labs_pkg",
        executable="turtlesim_drivesquare",
    )

    move_turtle = ExecuteProcess(
        cmd=[
            'ros2', 'service', 'call',
            '/turtle1/teleport_absolute',
            'turtlesim/srv/TeleportAbsolute',
            '"{x: 5.0, y: 2.0, theta: 1}"',
        ],
        shell=True,
    )
    
    ld.add_action(turtlesim_node)
    ld.add_action(move_turtle)
    ld.add_action(odom_node)
    ld.add_action(drivesquare_node)

    return ld
