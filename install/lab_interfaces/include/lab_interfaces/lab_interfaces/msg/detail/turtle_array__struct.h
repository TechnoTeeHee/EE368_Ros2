// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_
#define LAB_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'turtle_array'
#include "lab_interfaces/msg/detail/turtle__struct.h"

/// Struct defined in msg/TurtleArray in the package lab_interfaces.
typedef struct lab_interfaces__msg__TurtleArray
{
  lab_interfaces__msg__Turtle__Sequence turtle_array;
} lab_interfaces__msg__TurtleArray;

// Struct for a sequence of lab_interfaces__msg__TurtleArray.
typedef struct lab_interfaces__msg__TurtleArray__Sequence
{
  lab_interfaces__msg__TurtleArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__msg__TurtleArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_
