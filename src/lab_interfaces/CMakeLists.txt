cmake_minimum_required(VERSION 3.8)
project(lab_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Num.msg"
  "msg/NumArray.msg"
  "msg/Turtle.msg"
  "msg/TurtleArray.msg"
  "srv/MeasureWallDist.srv"
  "srv/CaptureTurtle.srv"
  "msg/WallDistanceMeasurement.msg"
  "msg/WallDistanceArray.msg"
  "msg/WallDistanceStatistics.msg"
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
