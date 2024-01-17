// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice
#include "lab_interfaces/srv/detail/measure_wall_dist__rosidl_typesupport_fastrtps_cpp.hpp"
#include "lab_interfaces/srv/detail/measure_wall_dist__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace lab_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
cdr_serialize(
  const lab_interfaces::srv::MeasureWallDist_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lab_interfaces::srv::MeasureWallDist_Request & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
get_serialized_size(
  const lab_interfaces::srv::MeasureWallDist_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
max_serialized_size_MeasureWallDist_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _MeasureWallDist_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lab_interfaces::srv::MeasureWallDist_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MeasureWallDist_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lab_interfaces::srv::MeasureWallDist_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MeasureWallDist_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lab_interfaces::srv::MeasureWallDist_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MeasureWallDist_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MeasureWallDist_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MeasureWallDist_Request__callbacks = {
  "lab_interfaces::srv",
  "MeasureWallDist_Request",
  _MeasureWallDist_Request__cdr_serialize,
  _MeasureWallDist_Request__cdr_deserialize,
  _MeasureWallDist_Request__get_serialized_size,
  _MeasureWallDist_Request__max_serialized_size
};

static rosidl_message_type_support_t _MeasureWallDist_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MeasureWallDist_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace lab_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lab_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<lab_interfaces::srv::MeasureWallDist_Request>()
{
  return &lab_interfaces::srv::typesupport_fastrtps_cpp::_MeasureWallDist_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab_interfaces, srv, MeasureWallDist_Request)() {
  return &lab_interfaces::srv::typesupport_fastrtps_cpp::_MeasureWallDist_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace lab_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const lab_interfaces::msg::WallDistanceArray &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  lab_interfaces::msg::WallDistanceArray &);
size_t get_serialized_size(
  const lab_interfaces::msg::WallDistanceArray &,
  size_t current_alignment);
size_t
max_serialized_size_WallDistanceArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace lab_interfaces


namespace lab_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
cdr_serialize(
  const lab_interfaces::srv::MeasureWallDist_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: wall_dist_array
  lab_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.wall_dist_array,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  lab_interfaces::srv::MeasureWallDist_Response & ros_message)
{
  // Member: wall_dist_array
  lab_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.wall_dist_array);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
get_serialized_size(
  const lab_interfaces::srv::MeasureWallDist_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: wall_dist_array

  current_alignment +=
    lab_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.wall_dist_array, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_lab_interfaces
max_serialized_size_MeasureWallDist_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: wall_dist_array
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        lab_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_WallDistanceArray(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MeasureWallDist_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const lab_interfaces::srv::MeasureWallDist_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MeasureWallDist_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<lab_interfaces::srv::MeasureWallDist_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MeasureWallDist_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const lab_interfaces::srv::MeasureWallDist_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MeasureWallDist_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MeasureWallDist_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MeasureWallDist_Response__callbacks = {
  "lab_interfaces::srv",
  "MeasureWallDist_Response",
  _MeasureWallDist_Response__cdr_serialize,
  _MeasureWallDist_Response__cdr_deserialize,
  _MeasureWallDist_Response__get_serialized_size,
  _MeasureWallDist_Response__max_serialized_size
};

static rosidl_message_type_support_t _MeasureWallDist_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MeasureWallDist_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace lab_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lab_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<lab_interfaces::srv::MeasureWallDist_Response>()
{
  return &lab_interfaces::srv::typesupport_fastrtps_cpp::_MeasureWallDist_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab_interfaces, srv, MeasureWallDist_Response)() {
  return &lab_interfaces::srv::typesupport_fastrtps_cpp::_MeasureWallDist_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace lab_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _MeasureWallDist__callbacks = {
  "lab_interfaces::srv",
  "MeasureWallDist",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab_interfaces, srv, MeasureWallDist_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab_interfaces, srv, MeasureWallDist_Response)(),
};

static rosidl_service_type_support_t _MeasureWallDist__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MeasureWallDist__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace lab_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_lab_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<lab_interfaces::srv::MeasureWallDist>()
{
  return &lab_interfaces::srv::typesupport_fastrtps_cpp::_MeasureWallDist__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, lab_interfaces, srv, MeasureWallDist)() {
  return &lab_interfaces::srv::typesupport_fastrtps_cpp::_MeasureWallDist__handle;
}

#ifdef __cplusplus
}
#endif
