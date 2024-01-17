from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    integer_publisher_node = Node(
        package="labs_pkg",
        executable="integer_publisher",
        name="new_integer_publisher",
        remappings=[
            ("integer","new_integer")
        ],
        parameters=[
            {"int_to_publish": 6},
            {"publish_rate": 0.5}
        ]
    )

    cumulative_adder_node = Node(
        package="labs_pkg",
        executable="cumulative_adder",
        name="new_cumulative_adder",
        remappings=[
            ("integer","new_integer"),
            ("integer_sum","new_integer_sum")
        ],
    )
    
    integer_publisher_two_node = Node(
        package="labs_pkg",
        executable="integer_publisher",
        name="integer_publisher",
        parameters=[
            {"int_to_publish": 4},
            {"publish_rate": 0.5}
        ]
    )

    cumulative_adder_two_node = Node(
        package="labs_pkg",
        executable="cumulative_adder",
        name="cumulative_adder",
    )

    ld.add_action(integer_publisher_node)
    ld.add_action(cumulative_adder_node)
    ld.add_action(integer_publisher_two_node)
    ld.add_action(cumulative_adder_two_node)
    return ld