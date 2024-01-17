// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lab_interfaces:srv/CaptureTurtle.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__TRAITS_HPP_
#define LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lab_interfaces/srv/detail/capture_turtle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lab_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CaptureTurtle_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CaptureTurtle_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CaptureTurtle_Request & msg, bool use_flow_style = false)
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
  const lab_interfaces::srv::CaptureTurtle_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::srv::CaptureTurtle_Request & msg)
{
  return lab_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::srv::CaptureTurtle_Request>()
{
  return "lab_interfaces::srv::CaptureTurtle_Request";
}

template<>
inline const char * name<lab_interfaces::srv::CaptureTurtle_Request>()
{
  return "lab_interfaces/srv/CaptureTurtle_Request";
}

template<>
struct has_fixed_size<lab_interfaces::srv::CaptureTurtle_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lab_interfaces::srv::CaptureTurtle_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lab_interfaces::srv::CaptureTurtle_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lab_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CaptureTurtle_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CaptureTurtle_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CaptureTurtle_Response & msg, bool use_flow_style = false)
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
  const lab_interfaces::srv::CaptureTurtle_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lab_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lab_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const lab_interfaces::srv::CaptureTurtle_Response & msg)
{
  return lab_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lab_interfaces::srv::CaptureTurtle_Response>()
{
  return "lab_interfaces::srv::CaptureTurtle_Response";
}

template<>
inline const char * name<lab_interfaces::srv::CaptureTurtle_Response>()
{
  return "lab_interfaces/srv/CaptureTurtle_Response";
}

template<>
struct has_fixed_size<lab_interfaces::srv::CaptureTurtle_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lab_interfaces::srv::CaptureTurtle_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lab_interfaces::srv::CaptureTurtle_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lab_interfaces::srv::CaptureTurtle>()
{
  return "lab_interfaces::srv::CaptureTurtle";
}

template<>
inline const char * name<lab_interfaces::srv::CaptureTurtle>()
{
  return "lab_interfaces/srv/CaptureTurtle";
}

template<>
struct has_fixed_size<lab_interfaces::srv::CaptureTurtle>
  : std::integral_constant<
    bool,
    has_fixed_size<lab_interfaces::srv::CaptureTurtle_Request>::value &&
    has_fixed_size<lab_interfaces::srv::CaptureTurtle_Response>::value
  >
{
};

template<>
struct has_bounded_size<lab_interfaces::srv::CaptureTurtle>
  : std::integral_constant<
    bool,
    has_bounded_size<lab_interfaces::srv::CaptureTurtle_Request>::value &&
    has_bounded_size<lab_interfaces::srv::CaptureTurtle_Response>::value
  >
{
};

template<>
struct is_service<lab_interfaces::srv::CaptureTurtle>
  : std::true_type
{
};

template<>
struct is_service_request<lab_interfaces::srv::CaptureTurtle_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lab_interfaces::srv::CaptureTurtle_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__TRAITS_HPP_
