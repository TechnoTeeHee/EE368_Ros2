// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lab_interfaces:msg/WallDistanceArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__TRAITS_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lab_interfaces/msg/detail/wall_distance_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'dist_array'
#include "lab_interfaces/msg/detail/wall_distance_measurement__traits.hpp"

namespace lab_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WallDistanceArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: dist_array
  {
    if (msg.dist_array.size() == 0) {
      out << "dist_array: []";
    } else {
      out << "dist_array: [";
      size_t pending_items = msg.dist_array.size();
      for (auto item : msg.dist_array) {
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
  const WallDistanceArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dist_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dist_array.size() == 0) {
      out << "dist_array: []\n";
    } else {
      out << "dist_array:\n";
      for (auto item : msg.dist_array) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WallDistanceArray & msg, bool use_flow_style = false)
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
  const lab_interfaces::msg::WallDistanceArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::msg::WallDistanceArray & msg)
{
  return lab_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::msg::WallDistanceArray>()
{
  return "lab_interfaces::msg::WallDistanceArray";
}

template<>
inline const char * name<lab_interfaces::msg::WallDistanceArray>()
{
  return "lab_interfaces/msg/WallDistanceArray";
}

template<>
struct has_fixed_size<lab_interfaces::msg::WallDistanceArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lab_interfaces::msg::WallDistanceArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lab_interfaces::msg::WallDistanceArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__TRAITS_HPP_
