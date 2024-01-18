from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node"
    )

    control_turtle_node = Node(
        package="tf2_pkg",
        executable="control_turtle",
        name="control_turtle",
        parameters=[
            {"kv": 2.0},
            {"ka": 6.0}
        ]
    )

    turtle_monitor_node = Node(
        package="tf2_pkg",
        executable="turtle_monitor",
        name="turtle_monitor"
    )

    spawn_turtles_node = Node(
        package="tf2_pkg",
        executable="spawn_turtles",
        name="spawn_turtles",
        parameters=[
            {"name_prefix": "turtle"},
            {"spawn_rate": 1.0}
        ]
    )

    ld.add_action(turtlesim_node)
    ld.add_action(control_turtle_node)
    ld.add_action(turtle_monitor_node)
    ld.add_action(spawn_turtles_node)
    return ld