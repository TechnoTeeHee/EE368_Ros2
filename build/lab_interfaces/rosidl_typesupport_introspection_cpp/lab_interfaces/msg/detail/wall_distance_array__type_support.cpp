// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lab_interfaces:msg/WallDistanceArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lab_interfaces/msg/detail/wall_distance_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace lab_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void WallDistanceArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lab_interfaces::msg::WallDistanceArray(_init);
}

void WallDistanceArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lab_interfaces::msg::WallDistanceArray *>(message_memory);
  typed_message->~WallDistanceArray();
}

size_t size_function__WallDistanceArray__dist_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lab_interfaces::msg::WallDistanceMeasurement> *>(untyped_member);
  return member->size();
}

const void * get_const_function__WallDistanceArray__dist_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lab_interfaces::msg::WallDistanceMeasurement> *>(untyped_member);
  return &member[index];
}

void * get_function__WallDistanceArray__dist_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lab_interfaces::msg::WallDistanceMeasurement> *>(untyped_member);
  return &member[index];
}

void fetch_function__WallDistanceArray__dist_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lab_interfaces::msg::WallDistanceMeasurement *>(
    get_const_function__WallDistanceArray__dist_array(untyped_member, index));
  auto & value = *reinterpret_cast<lab_interfaces::msg::WallDistanceMeasurement *>(untyped_value);
  value = item;
}

void assign_function__WallDistanceArray__dist_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lab_interfaces::msg::WallDistanceMeasurement *>(
    get_function__WallDistanceArray__dist_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const lab_interfaces::msg::WallDistanceMeasurement *>(untyped_value);
  item = value;
}

void resize_function__WallDistanceArray__dist_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lab_interfaces::msg::WallDistanceMeasurement> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WallDistanceArray_message_member_array[1] = {
  {
    "dist_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lab_interfaces::msg::WallDistanceMeasurement>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lab_interfaces::msg::WallDistanceArray, dist_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__WallDistanceArray__dist_array,  // size() function pointer
    get_const_function__WallDistanceArray__dist_array,  // get_const(index) function pointer
    get_function__WallDistanceArray__dist_array,  // get(index) function pointer
    fetch_function__WallDistanceArray__dist_array,  // fetch(index, &value) function pointer
    assign_function__WallDistanceArray__dist_array,  // assign(index, value) function pointer
    resize_function__WallDistanceArray__dist_array  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WallDistanceArray_message_members = {
  "lab_interfaces::msg",  // message namespace
  "WallDistanceArray",  // message name
  1,  // number of fields
  sizeof(lab_interfaces::msg::WallDistanceArray),
  WallDistanceArray_message_member_array,  // message members
  WallDistanceArray_init_function,  // function to initialize message memory (memory has to be allocated)
  WallDistanceArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WallDistanceArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WallDistanceArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace lab_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<lab_interfaces::msg::WallDistanceArray>()
{
  return &::lab_interfaces::msg::rosidl_typesupport_introspection_cpp::WallDistanceArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lab_interfaces, msg, WallDistanceArray)() {
  return &::lab_interfaces::msg::rosidl_typesupport_introspection_cpp::WallDistanceArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
