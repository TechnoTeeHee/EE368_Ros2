// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__STRUCT_H_
#define LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'num_array'
#include "lab_interfaces/msg/detail/num__struct.h"

/// Struct defined in msg/NumArray in the package lab_interfaces.
typedef struct lab_interfaces__msg__NumArray
{
  lab_interfaces__msg__Num__Sequence num_array;
} lab_interfaces__msg__NumArray;

// Struct for a sequence of lab_interfaces__msg__NumArray.
typedef struct lab_interfaces__msg__NumArray__Sequence
{
  lab_interfaces__msg__NumArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__msg__NumArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__STRUCT_H_
