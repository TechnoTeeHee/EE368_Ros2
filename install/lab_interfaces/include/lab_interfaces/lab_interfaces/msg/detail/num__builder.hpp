// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lab_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
#define LAB_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lab_interfaces/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  explicit Init_Num_num(::lab_interfaces::msg::Num & msg)
  : msg_(msg)
  {}
  ::lab_interfaces::msg::Num num(::lab_interfaces::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lab_interfaces::msg::Num msg_;
};

class Init_Num_name
{
public:
  Init_Num_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_num name(::lab_interfaces::msg::Num::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Num_num(msg_);
  }

private:
  ::lab_interfaces::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lab_interfaces::msg::Num>()
{
  return lab_interfaces::msg::builder::Init_Num_name();
}

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__NUM__BUILDER_HPP_
