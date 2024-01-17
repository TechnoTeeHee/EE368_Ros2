// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__TRAITS_HPP_
#define LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lab_interfaces/srv/detail/measure_wall_dist__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lab_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MeasureWallDist_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MeasureWallDist_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MeasureWallDist_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace lab_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use lab_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lab_interfaces::srv::MeasureWallDist_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::srv::MeasureWallDist_Request & msg)
{
  return lab_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::srv::MeasureWallDist_Request>()
{
  return "lab_interfaces::srv::MeasureWallDist_Request";
}

template<>
inline const char * name<lab_interfaces::srv::MeasureWallDist_Request>()
{
  return "lab_interfaces/srv/MeasureWallDist_Request";
}

template<>
struct has_fixed_size<lab_interfaces::srv::MeasureWallDist_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lab_interfaces::srv::MeasureWallDist_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lab_interfaces::srv::MeasureWallDist_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'wall_dist_array'
#include "lab_interfaces/msg/detail/wall_distance_array__traits.hpp"

namespace lab_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MeasureWallDist_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: wall_dist_array
  {
    out << "wall_dist_array: ";
    to_flow_style_yaml(msg.wall_dist_array, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MeasureWallDist_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: wall_dist_array
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wall_dist_array:\n";
    to_block_style_yaml(msg.wall_dist_array, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MeasureWallDist_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace lab_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use lab_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lab_interfaces::srv::MeasureWallDist_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::srv::MeasureWallDist_Response & msg)
{
  return lab_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::srv::MeasureWallDist_Response>()
{
  return "lab_interfaces::srv::MeasureWallDist_Response";
}

template<>
inline const char * name<lab_interfaces::srv::MeasureWallDist_Response>()
{
  return "lab_interfaces/srv/MeasureWallDist_Response";
}

template<>
struct has_fixed_size<lab_interfaces::srv::MeasureWallDist_Response>
  : std::integral_constant<bool, has_fixed_size<lab_interfaces::msg::WallDistanceArray>::value> {};

template<>
struct has_bounded_size<lab_interfaces::srv::MeasureWallDist_Response>
  : std::integral_constant<bool, has_bounded_size<lab_interfaces::msg::WallDistanceArray>::value> {};

template<>
struct is_message<lab_interfaces::srv::MeasureWallDist_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lab_interfaces::srv::MeasureWallDist>()
{
  return "lab_interfaces::srv::MeasureWallDist";
}

template<>
inline const char * name<lab_interfaces::srv::MeasureWallDist>()
{
  return "lab_interfaces/srv/MeasureWallDist";
}

template<>
struct has_fixed_size<lab_interfaces::srv::MeasureWallDist>
  : std::integral_constant<
    bool,
    has_fixed_size<lab_interfaces::srv::MeasureWallDist_Request>::value &&
    has_fixed_size<lab_interfaces::srv::MeasureWallDist_Response>::value
  >
{
};

template<>
struct has_bounded_size<lab_interfaces::srv::MeasureWallDist>
  : std::integral_constant<
    bool,
    has_bounded_size<lab_interfaces::srv::MeasureWallDist_Request>::value &&
    has_bounded_size<lab_interfaces::srv::MeasureWallDist_Response>::value
  >
{
};

template<>
struct is_service<lab_interfaces::srv::MeasureWallDist>
  : std::true_type
{
};

template<>
struct is_service_request<lab_interfaces::srv::MeasureWallDist_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lab_interfaces::srv::MeasureWallDist_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__TRAITS_HPP_
