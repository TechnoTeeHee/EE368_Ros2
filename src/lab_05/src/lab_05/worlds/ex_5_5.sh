source cleanup.sh

# build robot
xacro ../description/robot.urdf.xacro > ../description/robot.urdf
ign sdf -p ../description/robot.urdf > ../description/robot.sdf

# start the robot 
ros2 launch lab_05 rsp.launch.py &

# run Gazebo and connect it to ros2 
ign gazebo ex_5_5.sdf &

ros2 run ros_gz_bridge parameter_bridge --ros-args -p config_file:=bridges.yaml &
ros2 run robot_localization ekf_node --ros-args -r __node:=ekf_filter_node --params-file ekf.yaml &
# start Rviz2 
rviz2 