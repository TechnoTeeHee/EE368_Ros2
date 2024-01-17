// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__TRAITS_HPP_
#define LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lab_interfaces/msg/detail/num_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'num_array'
#include "lab_interfaces/msg/detail/num__traits.hpp"

namespace lab_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NumArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: num_array
  {
    if (msg.num_array.size() == 0) {
      out << "num_array: []";
    } else {
      out << "num_array: [";
      size_t pending_items = msg.num_array.size();
      for (auto item : msg.num_array) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NumArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: num_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.num_array.size() == 0) {
      out << "num_array: []\n";
    } else {
      out << "num_array:\n";
      for (auto item : msg.num_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NumArray & msg, bool use_flow_style = false)
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
  const lab_interfaces::msg::NumArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::msg::NumArray & msg)
{
  return lab_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::msg::NumArray>()
{
  return "lab_interfaces::msg::NumArray";
}

template<>
inline const char * name<lab_interfaces::msg::NumArray>()
{
  return "lab_interfaces/msg/NumArray";
}

template<>
struct has_fixed_size<lab_interfaces::msg::NumArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lab_interfaces::msg::NumArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lab_interfaces::msg::NumArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__TRAITS_HPP_
