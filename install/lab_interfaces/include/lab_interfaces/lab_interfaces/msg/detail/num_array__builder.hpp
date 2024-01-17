// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__BUILDER_HPP_
#define LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/msg/detail/num_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_NumArray_num_array
{
public:
  Init_NumArray_num_array()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lab_interfaces::msg::NumArray num_array(::lab_interfaces::msg::NumArray::_num_array_type arg)
  {
    msg_.num_array = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::msg::NumArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::msg::NumArray>()
{
  return lab_interfaces::msg::builder::Init_NumArray_num_array();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__BUILDER_HPP_
