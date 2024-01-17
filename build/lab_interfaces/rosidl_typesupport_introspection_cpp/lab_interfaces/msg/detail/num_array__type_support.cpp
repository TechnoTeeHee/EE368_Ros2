// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "lab_interfaces/msg/detail/num_array__struct.hpp"
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

void NumArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) lab_interfaces::msg::NumArray(_init);
}

void NumArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<lab_interfaces::msg::NumArray *>(message_memory);
  typed_message->~NumArray();
}

size_t size_function__NumArray__num_array(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<lab_interfaces::msg::Num> *>(untyped_member);
  return member->size();
}

const void * get_const_function__NumArray__num_array(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<lab_interfaces::msg::Num> *>(untyped_member);
  return &member[index];
}

void * get_function__NumArray__num_array(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<lab_interfaces::msg::Num> *>(untyped_member);
  return &member[index];
}

void fetch_function__NumArray__num_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const lab_interfaces::msg::Num *>(
    get_const_function__NumArray__num_array(untyped_member, index));
  auto & value = *reinterpret_cast<lab_interfaces::msg::Num *>(untyped_value);
  value = item;
}

void assign_function__NumArray__num_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<lab_interfaces::msg::Num *>(
    get_function__NumArray__num_array(untyped_member, index));
  const auto & value = *reinterpret_cast<const lab_interfaces::msg::Num *>(untyped_value);
  item = value;
}

void resize_function__NumArray__num_array(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<lab_interfaces::msg::Num> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember NumArray_message_member_array[1] = {
  {
    "num_array",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<lab_interfaces::msg::Num>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lab_interfaces::msg::NumArray, num_array),  // bytes offset in struct
    nullptr,  // default value
    size_function__NumArray__num_array,  // size() function pointer
    get_const_function__NumArray__num_array,  // get_const(index) function pointer
    get_function__NumArray__num_array,  // get(index) function pointer
    fetch_function__NumArray__num_array,  // fetch(index, &value) function pointer
    assign_function__NumArray__num_array,  // assign(index, value) function pointer
    resize_function__NumArray__num_array  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers NumArray_message_members = {
  "lab_interfaces::msg",  // message namespace
  "NumArray",  // message name
  1,  // number of fields
  sizeof(lab_interfaces::msg::NumArray),
  NumArray_message_member_array,  // message members
  NumArray_init_function,  // function to initialize message memory (memory has to be allocated)
  NumArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t NumArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &NumArray_message_members,
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
get_message_type_support_handle<lab_interfaces::msg::NumArray>()
{
  return &::lab_interfaces::msg::rosidl_typesupport_introspection_cpp::NumArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, lab_interfaces, msg, NumArray)() {
  return &::lab_interfaces::msg::rosidl_typesupport_introspection_cpp::NumArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
