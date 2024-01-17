// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:msg/WallDistanceMeasurement.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__STRUCT_H_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__STRUCT_H_

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

/// Struct defined in msg/WallDistanceMeasurement in the package lab_interfaces.
typedef struct lab_interfaces__msg__WallDistanceMeasurement
{
  rosidl_runtime_c__String name;
  double dist;
} lab_interfaces__msg__WallDistanceMeasurement;

// Struct for a sequence of lab_interfaces__msg__WallDistanceMeasurement.
typedef struct lab_interfaces__msg__WallDistanceMeasurement__Sequence
{
  lab_interfaces__msg__WallDistanceMeasurement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__msg__WallDistanceMeasurement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__STRUCT_H_
