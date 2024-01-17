// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lab_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__NUM__TRAITS_HPP_
#define LAB_INTERFACES__MSG__DETAIL__NUM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lab_interfaces/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lab_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Num & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: num
  {
    out << "num: ";
    rosidl_generator_traits::value_to_yaml(msg.num, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Num & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num: ";
    rosidl_generator_traits::value_to_yaml(msg.num, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Num & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace lab_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use lab_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lab_interfaces::msg::Num & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::msg::Num & msg)
{
  return lab_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::msg::Num>()
{
  return "lab_interfaces::msg::Num";
}

template<>
inline const char * name<lab_interfaces::msg::Num>()
{
  return "lab_interfaces/msg/Num";
}

template<>
struct has_fixed_size<lab_interfaces::msg::Num>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lab_interfaces::msg::Num>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lab_interfaces::msg::Num>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LAB_INTERFACES__MSG__DETAIL__NUM__TRAITS_HPP_
