import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import xacro
import launch
import launch_ros

def generate_launch_description():

    # Specify the name of the package and path to xacro file within the package
    pkg_name = 'lab05'
    file_subpath = 'description/robot.urdf.xacro'
    pkg_share = launch_ros.substitutions.FindPackageShare(package='lab05').find('lab05')
    default_model_path = os.path.join(pkg_share, 'src/description/robot.urdf')
    # Use xacro to process the file
    xacro_file = os.path.join(get_package_share_directory(pkg_name),file_subpath)
    robot_description_raw = xacro.process_file(xacro_file).toxml()

    # Configure the node
    node_robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': robot_description_raw}] 
  # add other parameters here if required
    )
    
    joint_state_publisher_node = launch_ros.actions.Node(
    package='joint_state_publisher',
    executable='joint_state_publisher',
    name='joint_state_publisher',
    )
    
    # Run the node
    return LaunchDescription([
        node_robot_state_publisher,
        joint_state_publisher_node
    ])
