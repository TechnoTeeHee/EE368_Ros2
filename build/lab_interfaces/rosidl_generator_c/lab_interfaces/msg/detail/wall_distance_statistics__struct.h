// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:msg/WallDistanceStatistics.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__STRUCT_H_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/WallDistanceStatistics in the package lab_interfaces.
typedef struct lab_interfaces__msg__WallDistanceStatistics
{
  double mean;
  double std;
} lab_interfaces__msg__WallDistanceStatistics;

// Struct for a sequence of lab_interfaces__msg__WallDistanceStatistics.
typedef struct lab_interfaces__msg__WallDistanceStatistics__Sequence
{
  lab_interfaces__msg__WallDistanceStatistics * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__msg__WallDistanceStatistics__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__STRUCT_H_
