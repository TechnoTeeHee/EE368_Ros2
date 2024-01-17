// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__STRUCT_H_
#define LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MeasureWallDist in the package lab_interfaces.
typedef struct lab_interfaces__srv__MeasureWallDist_Request
{
  uint8_t structure_needs_at_least_one_member;
} lab_interfaces__srv__MeasureWallDist_Request;

// Struct for a sequence of lab_interfaces__srv__MeasureWallDist_Request.
typedef struct lab_interfaces__srv__MeasureWallDist_Request__Sequence
{
  lab_interfaces__srv__MeasureWallDist_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__srv__MeasureWallDist_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'wall_dist_array'
#include "lab_interfaces/msg/detail/wall_distance_array__struct.h"

/// Struct defined in srv/MeasureWallDist in the package lab_interfaces.
typedef struct lab_interfaces__srv__MeasureWallDist_Response
{
  lab_interfaces__msg__WallDistanceArray wall_dist_array;
} lab_interfaces__srv__MeasureWallDist_Response;

// Struct for a sequence of lab_interfaces__srv__MeasureWallDist_Response.
typedef struct lab_interfaces__srv__MeasureWallDist_Response__Sequence
{
  lab_interfaces__srv__MeasureWallDist_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} lab_interfaces__srv__MeasureWallDist_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__STRUCT_H_
