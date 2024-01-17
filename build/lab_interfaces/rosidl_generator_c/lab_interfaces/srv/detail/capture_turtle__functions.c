// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lab_interfaces:srv/CaptureTurtle.idl
// generated code does not contain a copyright notice
#include "lab_interfaces/srv/detail/capture_turtle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
lab_interfaces__srv__CaptureTurtle_Request__init(lab_interfaces__srv__CaptureTurtle_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    lab_interfaces__srv__CaptureTurtle_Request__fini(msg);
    return false;
  }
  return true;
}

void
lab_interfaces__srv__CaptureTurtle_Request__fini(lab_interfaces__srv__CaptureTurtle_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
lab_interfaces__srv__CaptureTurtle_Request__are_equal(const lab_interfaces__srv__CaptureTurtle_Request * lhs, const lab_interfaces__srv__CaptureTurtle_Request * rhs)
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
  return true;
}

bool
lab_interfaces__srv__CaptureTurtle_Request__copy(
  const lab_interfaces__srv__CaptureTurtle_Request * input,
  lab_interfaces__srv__CaptureTurtle_Request * output)
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
  return true;
}

lab_interfaces__srv__CaptureTurtle_Request *
lab_interfaces__srv__CaptureTurtle_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__CaptureTurtle_Request * msg = (lab_interfaces__srv__CaptureTurtle_Request *)allocator.allocate(sizeof(lab_interfaces__srv__CaptureTurtle_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__srv__CaptureTurtle_Request));
  bool success = lab_interfaces__srv__CaptureTurtle_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__srv__CaptureTurtle_Request__destroy(lab_interfaces__srv__CaptureTurtle_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__srv__CaptureTurtle_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__srv__CaptureTurtle_Request__Sequence__init(lab_interfaces__srv__CaptureTurtle_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__CaptureTurtle_Request * data = NULL;

  if (size) {
    data = (lab_interfaces__srv__CaptureTurtle_Request *)allocator.zero_allocate(size, sizeof(lab_interfaces__srv__CaptureTurtle_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__srv__CaptureTurtle_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__srv__CaptureTurtle_Request__fini(&data[i - 1]);
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
lab_interfaces__srv__CaptureTurtle_Request__Sequence__fini(lab_interfaces__srv__CaptureTurtle_Request__Sequence * array)
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
      lab_interfaces__srv__CaptureTurtle_Request__fini(&array->data[i]);
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

lab_interfaces__srv__CaptureTurtle_Request__Sequence *
lab_interfaces__srv__CaptureTurtle_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__CaptureTurtle_Request__Sequence * array = (lab_interfaces__srv__CaptureTurtle_Request__Sequence *)allocator.allocate(sizeof(lab_interfaces__srv__CaptureTurtle_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__srv__CaptureTurtle_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__srv__CaptureTurtle_Request__Sequence__destroy(lab_interfaces__srv__CaptureTurtle_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__srv__CaptureTurtle_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__srv__CaptureTurtle_Request__Sequence__are_equal(const lab_interfaces__srv__CaptureTurtle_Request__Sequence * lhs, const lab_interfaces__srv__CaptureTurtle_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__srv__CaptureTurtle_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__srv__CaptureTurtle_Request__Sequence__copy(
  const lab_interfaces__srv__CaptureTurtle_Request__Sequence * input,
  lab_interfaces__srv__CaptureTurtle_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__srv__CaptureTurtle_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__srv__CaptureTurtle_Request * data =
      (lab_interfaces__srv__CaptureTurtle_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__srv__CaptureTurtle_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__srv__CaptureTurtle_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__srv__CaptureTurtle_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
lab_interfaces__srv__CaptureTurtle_Response__init(lab_interfaces__srv__CaptureTurtle_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
lab_interfaces__srv__CaptureTurtle_Response__fini(lab_interfaces__srv__CaptureTurtle_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
lab_interfaces__srv__CaptureTurtle_Response__are_equal(const lab_interfaces__srv__CaptureTurtle_Response * lhs, const lab_interfaces__srv__CaptureTurtle_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
lab_interfaces__srv__CaptureTurtle_Response__copy(
  const lab_interfaces__srv__CaptureTurtle_Response * input,
  lab_interfaces__srv__CaptureTurtle_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

lab_interfaces__srv__CaptureTurtle_Response *
lab_interfaces__srv__CaptureTurtle_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__CaptureTurtle_Response * msg = (lab_interfaces__srv__CaptureTurtle_Response *)allocator.allocate(sizeof(lab_interfaces__srv__CaptureTurtle_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__srv__CaptureTurtle_Response));
  bool success = lab_interfaces__srv__CaptureTurtle_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__srv__CaptureTurtle_Response__destroy(lab_interfaces__srv__CaptureTurtle_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__srv__CaptureTurtle_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__srv__CaptureTurtle_Response__Sequence__init(lab_interfaces__srv__CaptureTurtle_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__CaptureTurtle_Response * data = NULL;

  if (size) {
    data = (lab_interfaces__srv__CaptureTurtle_Response *)allocator.zero_allocate(size, sizeof(lab_interfaces__srv__CaptureTurtle_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__srv__CaptureTurtle_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__srv__CaptureTurtle_Response__fini(&data[i - 1]);
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
lab_interfaces__srv__CaptureTurtle_Response__Sequence__fini(lab_interfaces__srv__CaptureTurtle_Response__Sequence * array)
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
      lab_interfaces__srv__CaptureTurtle_Response__fini(&array->data[i]);
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

lab_interfaces__srv__CaptureTurtle_Response__Sequence *
lab_interfaces__srv__CaptureTurtle_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__srv__CaptureTurtle_Response__Sequence * array = (lab_interfaces__srv__CaptureTurtle_Response__Sequence *)allocator.allocate(sizeof(lab_interfaces__srv__CaptureTurtle_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__srv__CaptureTurtle_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__srv__CaptureTurtle_Response__Sequence__destroy(lab_interfaces__srv__CaptureTurtle_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__srv__CaptureTurtle_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__srv__CaptureTurtle_Response__Sequence__are_equal(const lab_interfaces__srv__CaptureTurtle_Response__Sequence * lhs, const lab_interfaces__srv__CaptureTurtle_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__srv__CaptureTurtle_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__srv__CaptureTurtle_Response__Sequence__copy(
  const lab_interfaces__srv__CaptureTurtle_Response__Sequence * input,
  lab_interfaces__srv__CaptureTurtle_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__srv__CaptureTurtle_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__srv__CaptureTurtle_Response * data =
      (lab_interfaces__srv__CaptureTurtle_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__srv__CaptureTurtle_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__srv__CaptureTurtle_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__srv__CaptureTurtle_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
