from launch import LaunchDescription
from launch_ros.actions import Node

remap_my_chatter_topic = ("my_chatter","new_chatter")

def generate_launch_description():
    ld = LaunchDescription()
    my_talker_node = Node(
        package="labs_pkg",
        executable="my_talker",
        name="new_talker",
        remappings=[
            remap_integer_topic
        ],
        parameters=[
            {"string_to_publish": "Hello ROS2"},
            {"publish_rate": 0.5}
        ]
    )

    my_listener_node = Node(
        package="labs_pkg",
        executable="my_listener",
        name="new_cumulative_adder",
        remappings=[
            ("integer","new_integer")
        ],
    )

    ld.add_action(my_talker_node)
    ld.add_action(my_listener_node)
    return ld