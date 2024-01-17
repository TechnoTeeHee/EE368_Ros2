// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lab_interfaces:msg/WallDistanceArray.idl
// generated code does not contain a copyright notice
#include "lab_interfaces/msg/detail/wall_distance_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `dist_array`
#include "lab_interfaces/msg/detail/wall_distance_measurement__functions.h"

bool
lab_interfaces__msg__WallDistanceArray__init(lab_interfaces__msg__WallDistanceArray * msg)
{
  if (!msg) {
    return false;
  }
  // dist_array
  if (!lab_interfaces__msg__WallDistanceMeasurement__Sequence__init(&msg->dist_array, 0)) {
    lab_interfaces__msg__WallDistanceArray__fini(msg);
    return false;
  }
  return true;
}

void
lab_interfaces__msg__WallDistanceArray__fini(lab_interfaces__msg__WallDistanceArray * msg)
{
  if (!msg) {
    return;
  }
  // dist_array
  lab_interfaces__msg__WallDistanceMeasurement__Sequence__fini(&msg->dist_array);
}

bool
lab_interfaces__msg__WallDistanceArray__are_equal(const lab_interfaces__msg__WallDistanceArray * lhs, const lab_interfaces__msg__WallDistanceArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // dist_array
  if (!lab_interfaces__msg__WallDistanceMeasurement__Sequence__are_equal(
      &(lhs->dist_array), &(rhs->dist_array)))
  {
    return false;
  }
  return true;
}

bool
lab_interfaces__msg__WallDistanceArray__copy(
  const lab_interfaces__msg__WallDistanceArray * input,
  lab_interfaces__msg__WallDistanceArray * output)
{
  if (!input || !output) {
    return false;
  }
  // dist_array
  if (!lab_interfaces__msg__WallDistanceMeasurement__Sequence__copy(
      &(input->dist_array), &(output->dist_array)))
  {
    return false;
  }
  return true;
}

lab_interfaces__msg__WallDistanceArray *
lab_interfaces__msg__WallDistanceArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__WallDistanceArray * msg = (lab_interfaces__msg__WallDistanceArray *)allocator.allocate(sizeof(lab_interfaces__msg__WallDistanceArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__msg__WallDistanceArray));
  bool success = lab_interfaces__msg__WallDistanceArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__msg__WallDistanceArray__destroy(lab_interfaces__msg__WallDistanceArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__msg__WallDistanceArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__msg__WallDistanceArray__Sequence__init(lab_interfaces__msg__WallDistanceArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__WallDistanceArray * data = NULL;

  if (size) {
    data = (lab_interfaces__msg__WallDistanceArray *)allocator.zero_allocate(size, sizeof(lab_interfaces__msg__WallDistanceArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__msg__WallDistanceArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__msg__WallDistanceArray__fini(&data[i - 1]);
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
lab_interfaces__msg__WallDistanceArray__Sequence__fini(lab_interfaces__msg__WallDistanceArray__Sequence * array)
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
      lab_interfaces__msg__WallDistanceArray__fini(&array->data[i]);
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

lab_interfaces__msg__WallDistanceArray__Sequence *
lab_interfaces__msg__WallDistanceArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__WallDistanceArray__Sequence * array = (lab_interfaces__msg__WallDistanceArray__Sequence *)allocator.allocate(sizeof(lab_interfaces__msg__WallDistanceArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__msg__WallDistanceArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__msg__WallDistanceArray__Sequence__destroy(lab_interfaces__msg__WallDistanceArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__msg__WallDistanceArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__msg__WallDistanceArray__Sequence__are_equal(const lab_interfaces__msg__WallDistanceArray__Sequence * lhs, const lab_interfaces__msg__WallDistanceArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__msg__WallDistanceArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__msg__WallDistanceArray__Sequence__copy(
  const lab_interfaces__msg__WallDistanceArray__Sequence * input,
  lab_interfaces__msg__WallDistanceArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__msg__WallDistanceArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__msg__WallDistanceArray * data =
      (lab_interfaces__msg__WallDistanceArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__msg__WallDistanceArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__msg__WallDistanceArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__msg__WallDistanceArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
