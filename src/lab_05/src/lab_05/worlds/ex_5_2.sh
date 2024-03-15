source cleanup.sh

# build robot
xacro ../description/robot.urdf.xacro > ../description/robot.urdf
ign sdf -p ../description/robot.urdf > ../description/robot.sdf

xacro ../description/scene.urdf.xacro > ../description/scene.urdf
ign sdf -p ../description/scene.urdf > ../description/scene.sdf

# start the robot 
ros2 launch lab_05 rsp.launch.py &

# run Gazebo and connect it to ros2 
ign gazebo ex_5_2.sdf &
ros2 run ros_gz_bridge parameter_bridge --ros-args -p config_file:=bridges.yaml &
