// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:srv/CaptureTurtle.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__BUILDER_HPP_
#define LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/srv/detail/capture_turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace srv
{

namespace builder
{

class Init_CaptureTurtle_Request_name
{
public:
  Init_CaptureTurtle_Request_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lab_interfaces::srv::CaptureTurtle_Request name(::lab_interfaces::srv::CaptureTurtle_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::srv::CaptureTurtle_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::srv::CaptureTurtle_Request>()
{
  return lab_interfaces::srv::builder::Init_CaptureTurtle_Request_name();
}

}  // namespace lab_interfaces


namespace lab_interfaces
{

namespace srv
{

namespace builder
{

class Init_CaptureTurtle_Response_success
{
public:
  Init_CaptureTurtle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lab_interfaces::srv::CaptureTurtle_Response success(::lab_interfaces::srv::CaptureTurtle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::srv::CaptureTurtle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::srv::CaptureTurtle_Response>()
{
  return lab_interfaces::srv::builder::Init_CaptureTurtle_Response_success();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__BUILDER_HPP_
