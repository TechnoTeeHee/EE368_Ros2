// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__BUILDER_HPP_
#define LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/srv/detail/measure_wall_dist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::srv::MeasureWallDist_Request>()
{
  return ::lab_interfaces::srv::MeasureWallDist_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace lab_interfaces


namespace lab_interfaces
{

namespace srv
{

namespace builder
{

class Init_MeasureWallDist_Response_wall_dist_array
{
public:
  Init_MeasureWallDist_Response_wall_dist_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lab_interfaces::srv::MeasureWallDist_Response wall_dist_array(::lab_interfaces::srv::MeasureWallDist_Response::_wall_dist_array_type arg)
  {
    msg_.wall_dist_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::srv::MeasureWallDist_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::srv::MeasureWallDist_Response>()
{
  return lab_interfaces::srv::builder::Init_MeasureWallDist_Response_wall_dist_array();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__BUILDER_HPP_
