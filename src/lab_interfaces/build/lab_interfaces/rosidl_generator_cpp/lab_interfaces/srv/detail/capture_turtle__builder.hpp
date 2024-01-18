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

class Init_CaptureTurtle_Response_message
{
public:
  explicit Init_CaptureTurtle_Response_message(::lab_interfaces::srv::CaptureTurtle_Response & msg)
  : msg_(msg)
  {}
  ::lab_interfaces::srv::CaptureTurtle_Response message(::lab_interfaces::srv::CaptureTurtle_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::srv::CaptureTurtle_Response msg_;
};

class Init_CaptureTurtle_Response_status
{
public:
  Init_CaptureTurtle_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CaptureTurtle_Response_message status(::lab_interfaces::srv::CaptureTurtle_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_CaptureTurtle_Response_message(msg_);
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
  return lab_interfaces::srv::builder::Init_CaptureTurtle_Response_status();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__BUILDER_HPP_
