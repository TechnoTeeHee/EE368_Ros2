// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_
#define LAB_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/msg/detail/turtle_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleArray_turtle_array
{
public:
  Init_TurtleArray_turtle_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lab_interfaces::msg::TurtleArray turtle_array(::lab_interfaces::msg::TurtleArray::_turtle_array_type arg)
  {
    msg_.turtle_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::msg::TurtleArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::msg::TurtleArray>()
{
  return lab_interfaces::msg::builder::Init_TurtleArray_turtle_array();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_
