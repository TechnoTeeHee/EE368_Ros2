// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice
#include "lab_interfaces/srv/detail/measure_wall_dist__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
lab_interfaces__srv__MeasureWallDist_Request__init(lab_interfaces__srv__MeasureWallDist_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
lab_interfaces__srv__MeasureWallDist_Request__fini(lab_interfaces__srv__MeasureWallDist_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
lab_interfaces__srv__MeasureWallDist_Request__are_equal(const lab_interfaces__srv__MeasureWallDist_Request * lhs, const lab_interfaces__srv__MeasureWallDist_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
lab_interfaces__srv__MeasureWallDist_Request__copy(
  const lab_interfaces__srv__MeasureWallDist_Request * input,
  lab_interfaces__srv__MeasureWallDist_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

lab_interfaces__srv__MeasureWallDist_Request *
lab_interfaces__srv__MeasureWallDist_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__MeasureWallDist_Request * msg = (lab_interfaces__srv__MeasureWallDist_Request *)allocator.allocate(sizeof(lab_interfaces__srv__MeasureWallDist_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__srv__MeasureWallDist_Request));
  bool success = lab_interfaces__srv__MeasureWallDist_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__srv__MeasureWallDist_Request__destroy(lab_interfaces__srv__MeasureWallDist_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__srv__MeasureWallDist_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__srv__MeasureWallDist_Request__Sequence__init(lab_interfaces__srv__MeasureWallDist_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__MeasureWallDist_Request * data = NULL;

  if (size) {
    data = (lab_interfaces__srv__MeasureWallDist_Request *)allocator.zero_allocate(size, sizeof(lab_interfaces__srv__MeasureWallDist_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__srv__MeasureWallDist_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__srv__MeasureWallDist_Request__fini(&data[i - 1]);
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
lab_interfaces__srv__MeasureWallDist_Request__Sequence__fini(lab_interfaces__srv__MeasureWallDist_Request__Sequence * array)
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
      lab_interfaces__srv__MeasureWallDist_Request__fini(&array->data[i]);
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

lab_interfaces__srv__MeasureWallDist_Request__Sequence *
lab_interfaces__srv__MeasureWallDist_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__MeasureWallDist_Request__Sequence * array = (lab_interfaces__srv__MeasureWallDist_Request__Sequence *)allocator.allocate(sizeof(lab_interfaces__srv__MeasureWallDist_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__srv__MeasureWallDist_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__srv__MeasureWallDist_Request__Sequence__destroy(lab_interfaces__srv__MeasureWallDist_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__srv__MeasureWallDist_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__srv__MeasureWallDist_Request__Sequence__are_equal(const lab_interfaces__srv__MeasureWallDist_Request__Sequence * lhs, const lab_interfaces__srv__MeasureWallDist_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__srv__MeasureWallDist_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__srv__MeasureWallDist_Request__Sequence__copy(
  const lab_interfaces__srv__MeasureWallDist_Request__Sequence * input,
  lab_interfaces__srv__MeasureWallDist_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__srv__MeasureWallDist_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__srv__MeasureWallDist_Request * data =
      (lab_interfaces__srv__MeasureWallDist_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__srv__MeasureWallDist_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__srv__MeasureWallDist_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__srv__MeasureWallDist_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `wall_dist_array`
#include "lab_interfaces/msg/detail/wall_distance_array__functions.h"

bool
lab_interfaces__srv__MeasureWallDist_Response__init(lab_interfaces__srv__MeasureWallDist_Response * msg)
{
  if (!msg) {
    return false;
  }
  // wall_dist_array
  if (!lab_interfaces__msg__WallDistanceArray__init(&msg->wall_dist_array)) {
    lab_interfaces__srv__MeasureWallDist_Response__fini(msg);
    return false;
  }
  return true;
}

void
lab_interfaces__srv__MeasureWallDist_Response__fini(lab_interfaces__srv__MeasureWallDist_Response * msg)
{
  if (!msg) {
    return;
  }
  // wall_dist_array
  lab_interfaces__msg__WallDistanceArray__fini(&msg->wall_dist_array);
}

bool
lab_interfaces__srv__MeasureWallDist_Response__are_equal(const lab_interfaces__srv__MeasureWallDist_Response * lhs, const lab_interfaces__srv__MeasureWallDist_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // wall_dist_array
  if (!lab_interfaces__msg__WallDistanceArray__are_equal(
      &(lhs->wall_dist_array), &(rhs->wall_dist_array)))
  {
    return false;
  }
  return true;
}

bool
lab_interfaces__srv__MeasureWallDist_Response__copy(
  const lab_interfaces__srv__MeasureWallDist_Response * input,
  lab_interfaces__srv__MeasureWallDist_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // wall_dist_array
  if (!lab_interfaces__msg__WallDistanceArray__copy(
      &(input->wall_dist_array), &(output->wall_dist_array)))
  {
    return false;
  }
  return true;
}

lab_interfaces__srv__MeasureWallDist_Response *
lab_interfaces__srv__MeasureWallDist_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__MeasureWallDist_Response * msg = (lab_interfaces__srv__MeasureWallDist_Response *)allocator.allocate(sizeof(lab_interfaces__srv__MeasureWallDist_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__srv__MeasureWallDist_Response));
  bool success = lab_interfaces__srv__MeasureWallDist_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__srv__MeasureWallDist_Response__destroy(lab_interfaces__srv__MeasureWallDist_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__srv__MeasureWallDist_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__srv__MeasureWallDist_Response__Sequence__init(lab_interfaces__srv__MeasureWallDist_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__MeasureWallDist_Response * data = NULL;

  if (size) {
    data = (lab_interfaces__srv__MeasureWallDist_Response *)allocator.zero_allocate(size, sizeof(lab_interfaces__srv__MeasureWallDist_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__srv__MeasureWallDist_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__srv__MeasureWallDist_Response__fini(&data[i - 1]);
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
lab_interfaces__srv__MeasureWallDist_Response__Sequence__fini(lab_interfaces__srv__MeasureWallDist_Response__Sequence * array)
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
      lab_interfaces__srv__MeasureWallDist_Response__fini(&array->data[i]);
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

lab_interfaces__srv__MeasureWallDist_Response__Sequence *
lab_interfaces__srv__MeasureWallDist_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__MeasureWallDist_Response__Sequence * array = (lab_interfaces__srv__MeasureWallDist_Response__Sequence *)allocator.allocate(sizeof(lab_interfaces__srv__MeasureWallDist_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__srv__MeasureWallDist_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__srv__MeasureWallDist_Response__Sequence__destroy(lab_interfaces__srv__MeasureWallDist_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__srv__MeasureWallDist_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__srv__MeasureWallDist_Response__Sequence__are_equal(const lab_interfaces__srv__MeasureWallDist_Response__Sequence * lhs, const lab_interfaces__srv__MeasureWallDist_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__srv__MeasureWallDist_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__srv__MeasureWallDist_Response__Sequence__copy(
  const lab_interfaces__srv__MeasureWallDist_Response__Sequence * input,
  lab_interfaces__srv__MeasureWallDist_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__srv__MeasureWallDist_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__srv__MeasureWallDist_Response * data =
      (lab_interfaces__srv__MeasureWallDist_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__srv__MeasureWallDist_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__srv__MeasureWallDist_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__srv__MeasureWallDist_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
