from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    my_talker_node = Node(
    package="labs_pkg",
    executable="my_talker"
    )

    my_listener_node = Node(
    package="labs_pkg",
    executable="my_listener"
    )

    ld.add_action(my_talker_node)
    ld.add_action(my_listener_node)
    return ld