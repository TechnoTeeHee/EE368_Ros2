// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lab_interfaces:msg/WallDistanceMeasurement.idl
// generated code does not contain a copyright notice
#include "lab_interfaces/msg/detail/wall_distance_measurement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
lab_interfaces__msg__WallDistanceMeasurement__init(lab_interfaces__msg__WallDistanceMeasurement * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    lab_interfaces__msg__WallDistanceMeasurement__fini(msg);
    return false;
  }
  // dist
  return true;
}

void
lab_interfaces__msg__WallDistanceMeasurement__fini(lab_interfaces__msg__WallDistanceMeasurement * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // dist
}

bool
lab_interfaces__msg__WallDistanceMeasurement__are_equal(const lab_interfaces__msg__WallDistanceMeasurement * lhs, const lab_interfaces__msg__WallDistanceMeasurement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // dist
  if (lhs->dist != rhs->dist) {
    return false;
  }
  return true;
}

bool
lab_interfaces__msg__WallDistanceMeasurement__copy(
  const lab_interfaces__msg__WallDistanceMeasurement * input,
  lab_interfaces__msg__WallDistanceMeasurement * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // dist
  output->dist = input->dist;
  return true;
}

lab_interfaces__msg__WallDistanceMeasurement *
lab_interfaces__msg__WallDistanceMeasurement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__WallDistanceMeasurement * msg = (lab_interfaces__msg__WallDistanceMeasurement *)allocator.allocate(sizeof(lab_interfaces__msg__WallDistanceMeasurement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__msg__WallDistanceMeasurement));
  bool success = lab_interfaces__msg__WallDistanceMeasurement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__msg__WallDistanceMeasurement__destroy(lab_interfaces__msg__WallDistanceMeasurement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__msg__WallDistanceMeasurement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__msg__WallDistanceMeasurement__Sequence__init(lab_interfaces__msg__WallDistanceMeasurement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__WallDistanceMeasurement * data = NULL;

  if (size) {
    data = (lab_interfaces__msg__WallDistanceMeasurement *)allocator.zero_allocate(size, sizeof(lab_interfaces__msg__WallDistanceMeasurement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__msg__WallDistanceMeasurement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__msg__WallDistanceMeasurement__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
lab_interfaces__msg__WallDistanceMeasurement__Sequence__fini(lab_interfaces__msg__WallDistanceMeasurement__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      lab_interfaces__msg__WallDistanceMeasurement__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

lab_interfaces__msg__WallDistanceMeasurement__Sequence *
lab_interfaces__msg__WallDistanceMeasurement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__WallDistanceMeasurement__Sequence * array = (lab_interfaces__msg__WallDistanceMeasurement__Sequence *)allocator.allocate(sizeof(lab_interfaces__msg__WallDistanceMeasurement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__msg__WallDistanceMeasurement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__msg__WallDistanceMeasurement__Sequence__destroy(lab_interfaces__msg__WallDistanceMeasurement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__msg__WallDistanceMeasurement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__msg__WallDistanceMeasurement__Sequence__are_equal(const lab_interfaces__msg__WallDistanceMeasurement__Sequence * lhs, const lab_interfaces__msg__WallDistanceMeasurement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__msg__WallDistanceMeasurement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__msg__WallDistanceMeasurement__Sequence__copy(
  const lab_interfaces__msg__WallDistanceMeasurement__Sequence * input,
  lab_interfaces__msg__WallDistanceMeasurement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__msg__WallDistanceMeasurement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__msg__WallDistanceMeasurement * data =
      (lab_interfaces__msg__WallDistanceMeasurement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__msg__WallDistanceMeasurement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__msg__WallDistanceMeasurement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__msg__WallDistanceMeasurement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
