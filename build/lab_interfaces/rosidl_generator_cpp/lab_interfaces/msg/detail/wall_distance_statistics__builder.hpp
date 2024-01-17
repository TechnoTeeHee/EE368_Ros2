// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:msg/WallDistanceStatistics.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__BUILDER_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/msg/detail/wall_distance_statistics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_WallDistanceStatistics_std
{
public:
  explicit Init_WallDistanceStatistics_std(::lab_interfaces::msg::WallDistanceStatistics & msg)
  : msg_(msg)
  {}
  ::lab_interfaces::msg::WallDistanceStatistics std(::lab_interfaces::msg::WallDistanceStatistics::_std_type arg)
  {
    msg_.std = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::msg::WallDistanceStatistics msg_;
};

class Init_WallDistanceStatistics_mean
{
public:
  Init_WallDistanceStatistics_mean()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WallDistanceStatistics_std mean(::lab_interfaces::msg::WallDistanceStatistics::_mean_type arg)
  {
    msg_.mean = std::move(arg);
    return Init_WallDistanceStatistics_std(msg_);
  }

private:
  ::lab_interfaces::msg::WallDistanceStatistics msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::msg::WallDistanceStatistics>()
{
  return lab_interfaces::msg::builder::Init_WallDistanceStatistics_mean();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__BUILDER_HPP_
