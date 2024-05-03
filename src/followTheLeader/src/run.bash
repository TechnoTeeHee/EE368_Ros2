PROJECT=`pwd`

. cleanup.bash

cd $PROJECT/..
colcon build --symlink-install
source install/setup.bash

cd $PROJECT
ign gazebo world.sdf --gui-config gz.config -r &
ros2 run ros_gz_bridge parameter_bridge --ros-args -p config_file:=bridges.yaml &

python3 rabbits.py &
python3 action_server.py &
python3 action_client.py

