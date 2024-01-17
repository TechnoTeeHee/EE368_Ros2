// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:msg/WallDistanceArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__STRUCT_H_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'dist_array'
#include "lab_interfaces/msg/detail/wall_distance_measurement__struct.h"

/// Struct defined in msg/WallDistanceArray in the package lab_interfaces.
typedef struct lab_interfaces__msg__WallDistanceArray
{
  lab_interfaces__msg__WallDistanceMeasurement__Sequence dist_array;
} lab_interfaces__msg__WallDistanceArray;

// Struct for a sequence of lab_interfaces__msg__WallDistanceArray.
typedef struct lab_interfaces__msg__WallDistanceArray__Sequence
{
  lab_interfaces__msg__WallDistanceArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__msg__WallDistanceArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__STRUCT_H_
