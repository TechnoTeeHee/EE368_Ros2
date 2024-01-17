// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lab_interfaces/msg/detail/num_array__rosidl_typesupport_introspection_c.h"
#include "lab_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lab_interfaces/msg/detail/num_array__functions.h"
#include "lab_interfaces/msg/detail/num_array__struct.h"


// Include directives for member types
// Member `num_array`
#include "lab_interfaces/msg/num.h"
// Member `num_array`
#include "lab_interfaces/msg/detail/num__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lab_interfaces__msg__NumArray__init(message_memory);
}

void lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_fini_function(void * message_memory)
{
  lab_interfaces__msg__NumArray__fini(message_memory);
}

size_t lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__size_function__NumArray__num_array(
  const void * untyped_member)
{
  const lab_interfaces__msg__Num__Sequence * member =
    (const lab_interfaces__msg__Num__Sequence *)(untyped_member);
  return member->size;
}

const void * lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__get_const_function__NumArray__num_array(
  const void * untyped_member, size_t index)
{
  const lab_interfaces__msg__Num__Sequence * member =
    (const lab_interfaces__msg__Num__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__get_function__NumArray__num_array(
  void * untyped_member, size_t index)
{
  lab_interfaces__msg__Num__Sequence * member =
    (lab_interfaces__msg__Num__Sequence *)(untyped_member);
  return &member->data[index];
}

void lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__fetch_function__NumArray__num_array(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const lab_interfaces__msg__Num * item =
    ((const lab_interfaces__msg__Num *)
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__get_const_function__NumArray__num_array(untyped_member, index));
  lab_interfaces__msg__Num * value =
    (lab_interfaces__msg__Num *)(untyped_value);
  *value = *item;
}

void lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__assign_function__NumArray__num_array(
  void * untyped_member, size_t index, const void * untyped_value)
{
  lab_interfaces__msg__Num * item =
    ((lab_interfaces__msg__Num *)
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__get_function__NumArray__num_array(untyped_member, index));
  const lab_interfaces__msg__Num * value =
    (const lab_interfaces__msg__Num *)(untyped_value);
  *item = *value;
}

bool lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__resize_function__NumArray__num_array(
  void * untyped_member, size_t size)
{
  lab_interfaces__msg__Num__Sequence * member =
    (lab_interfaces__msg__Num__Sequence *)(untyped_member);
  lab_interfaces__msg__Num__Sequence__fini(member);
  return lab_interfaces__msg__Num__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_member_array[1] = {
  {
    "num_array",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lab_interfaces__msg__NumArray, num_array),  // bytes offset in struct
    NULL,  // default value
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__size_function__NumArray__num_array,  // size() function pointer
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__get_const_function__NumArray__num_array,  // get_const(index) function pointer
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__get_function__NumArray__num_array,  // get(index) function pointer
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__fetch_function__NumArray__num_array,  // fetch(index, &value) function pointer
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__assign_function__NumArray__num_array,  // assign(index, value) function pointer
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__resize_function__NumArray__num_array  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_members = {
  "lab_interfaces__msg",  // message namespace
  "NumArray",  // message name
  1,  // number of fields
  sizeof(lab_interfaces__msg__NumArray),
  lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_member_array,  // message members
  lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_init_function,  // function to initialize message memory (memory has to be allocated)
  lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_type_support_handle = {
  0,
  &lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lab_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lab_interfaces, msg, NumArray)() {
  lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lab_interfaces, msg, Num)();
  if (!lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_type_support_handle.typesupport_identifier) {
    lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lab_interfaces__msg__NumArray__rosidl_typesupport_introspection_c__NumArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
