from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
    )
    
    control_turtle_node = Node(
        package="labs_pkg",
        executable="control_turtle",
    )
    
    turtle_monitor_node = Node(
        package="labs_pkg",
        executable="turtle_monitor",
    )

    spawn_turtles_node = Node(
        package="labs_pkg",
        executable="spawn_turtles",
    )

    ld.add_action(turtlesim_node)
    ld.add_action(control_turtle_node)
    ld.add_action(turtle_monitor_node)
    ld.add_action(spawn_turtles_node)
    
    return ld