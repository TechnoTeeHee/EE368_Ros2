function MyKillAll () {
    PROG=$1
    CMD="ps ax|grep '$PROG'|grep -v grep|awk '{\$1=\$1};1'|cut -f 1 -d ' '"
    PS=$(eval "$CMD")
    IFS=$'\n'
    for item in $PS
    do
        echo "Killing $PROG: $item"
        kill -9 $item
    done
}

MyKillAll "ign gazebo"
MyKillAll "static_transform_publisher"
MyKillAll "rviz2"
MyKillAll "parameter_bridge"
MyKillAll "ros2"
MyKillAll "robot_state_publisher"
MyKillAll "robot_local"