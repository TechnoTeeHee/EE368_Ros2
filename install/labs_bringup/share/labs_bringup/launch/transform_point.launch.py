from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    st_pub_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name= 'static_tf_base_link_to_base_laser',
        output = 'screen',
        emulate_tty = True,
        arguments=['0.1', '0', '0.2', '0', '0', '0', 'base_link', 'base_laser']
    )
    
    transform_point_node = Node(
        package="tf2_pkg",
        executable="transform_point"
    )

    ld.add_action(st_pub_node)
    ld.add_action(transform_point_node)
    return ld