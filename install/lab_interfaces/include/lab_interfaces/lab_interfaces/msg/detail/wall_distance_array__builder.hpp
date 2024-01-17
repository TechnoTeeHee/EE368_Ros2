// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:msg/WallDistanceArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__BUILDER_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/msg/detail/wall_distance_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_WallDistanceArray_dist_array
{
public:
  Init_WallDistanceArray_dist_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lab_interfaces::msg::WallDistanceArray dist_array(::lab_interfaces::msg::WallDistanceArray::_dist_array_type arg)
  {
    msg_.dist_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::msg::WallDistanceArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::msg::WallDistanceArray>()
{
  return lab_interfaces::msg::builder::Init_WallDistanceArray_dist_array();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__BUILDER_HPP_
