source cleanup.sh

# build robot
xacro ../description/robot.urdf.xacro > ../description/robot.urdf
ign sdf -p ../description/robot.urdf > ../description/robot.sdf

# start the robot 
ros2 launch lab_05 rsp.launch.py &

# run Gazebo and connect it to ros2 
ign gazebo ex_5_1.sdf &
ros2 run ros_gz_bridge parameter_bridge --ros-args -p config_file:=bridges.yaml &

# start Rviz2 
rviz2 &
ros2 run tf2_ros static_transform_publisher --frame-id camera_link --child-frame-id base_link/base_link/camera