// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:msg/WallDistanceMeasurement.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__BUILDER_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/msg/detail/wall_distance_measurement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_WallDistanceMeasurement_dist
{
public:
  explicit Init_WallDistanceMeasurement_dist(::lab_interfaces::msg::WallDistanceMeasurement & msg)
  : msg_(msg)
  {}
  ::lab_interfaces::msg::WallDistanceMeasurement dist(::lab_interfaces::msg::WallDistanceMeasurement::_dist_type arg)
  {
    msg_.dist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::msg::WallDistanceMeasurement msg_;
};

class Init_WallDistanceMeasurement_name
{
public:
  Init_WallDistanceMeasurement_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WallDistanceMeasurement_dist name(::lab_interfaces::msg::WallDistanceMeasurement::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_WallDistanceMeasurement_dist(msg_);
  }

private:
  ::lab_interfaces::msg::WallDistanceMeasurement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::msg::WallDistanceMeasurement>()
{
  return lab_interfaces::msg::builder::Init_WallDistanceMeasurement_name();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__BUILDER_HPP_
