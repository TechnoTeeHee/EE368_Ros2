// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:srv/CaptureTurtle.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__STRUCT_H_
#define LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CaptureTurtle in the package lab_interfaces.
typedef struct lab_interfaces__srv__CaptureTurtle_Request
{
  rosidl_runtime_c__String name;
} lab_interfaces__srv__CaptureTurtle_Request;

// Struct for a sequence of lab_interfaces__srv__CaptureTurtle_Request.
typedef struct lab_interfaces__srv__CaptureTurtle_Request__Sequence
{
  lab_interfaces__srv__CaptureTurtle_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__srv__CaptureTurtle_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CaptureTurtle in the package lab_interfaces.
typedef struct lab_interfaces__srv__CaptureTurtle_Response
{
  bool status;
  rosidl_runtime_c__String message;
} lab_interfaces__srv__CaptureTurtle_Response;

// Struct for a sequence of lab_interfaces__srv__CaptureTurtle_Response.
typedef struct lab_interfaces__srv__CaptureTurtle_Response__Sequence
{
  lab_interfaces__srv__CaptureTurtle_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__srv__CaptureTurtle_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__STRUCT_H_
