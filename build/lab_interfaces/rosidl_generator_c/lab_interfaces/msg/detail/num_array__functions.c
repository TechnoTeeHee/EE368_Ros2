// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice
#include "lab_interfaces/msg/detail/num_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `num_array`
#include "lab_interfaces/msg/detail/num__functions.h"

bool
lab_interfaces__msg__NumArray__init(lab_interfaces__msg__NumArray * msg)
{
  if (!msg) {
    return false;
  }
  // num_array
  if (!lab_interfaces__msg__Num__Sequence__init(&msg->num_array, 0)) {
    lab_interfaces__msg__NumArray__fini(msg);
    return false;
  }
  return true;
}

void
lab_interfaces__msg__NumArray__fini(lab_interfaces__msg__NumArray * msg)
{
  if (!msg) {
    return;
  }
  // num_array
  lab_interfaces__msg__Num__Sequence__fini(&msg->num_array);
}

bool
lab_interfaces__msg__NumArray__are_equal(const lab_interfaces__msg__NumArray * lhs, const lab_interfaces__msg__NumArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num_array
  if (!lab_interfaces__msg__Num__Sequence__are_equal(
      &(lhs->num_array), &(rhs->num_array)))
  {
    return false;
  }
  return true;
}

bool
lab_interfaces__msg__NumArray__copy(
  const lab_interfaces__msg__NumArray * input,
  lab_interfaces__msg__NumArray * output)
{
  if (!input || !output) {
    return false;
  }
  // num_array
  if (!lab_interfaces__msg__Num__Sequence__copy(
      &(input->num_array), &(output->num_array)))
  {
    return false;
  }
  return true;
}

lab_interfaces__msg__NumArray *
lab_interfaces__msg__NumArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__NumArray * msg = (lab_interfaces__msg__NumArray *)allocator.allocate(sizeof(lab_interfaces__msg__NumArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(lab_interfaces__msg__NumArray));
  bool success = lab_interfaces__msg__NumArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
lab_interfaces__msg__NumArray__destroy(lab_interfaces__msg__NumArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    lab_interfaces__msg__NumArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
lab_interfaces__msg__NumArray__Sequence__init(lab_interfaces__msg__NumArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__NumArray * data = NULL;

  if (size) {
    data = (lab_interfaces__msg__NumArray *)allocator.zero_allocate(size, sizeof(lab_interfaces__msg__NumArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = lab_interfaces__msg__NumArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        lab_interfaces__msg__NumArray__fini(&data[i - 1]);
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
lab_interfaces__msg__NumArray__Sequence__fini(lab_interfaces__msg__NumArray__Sequence * array)
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
      lab_interfaces__msg__NumArray__fini(&array->data[i]);
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

lab_interfaces__msg__NumArray__Sequence *
lab_interfaces__msg__NumArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  lab_interfaces__msg__NumArray__Sequence * array = (lab_interfaces__msg__NumArray__Sequence *)allocator.allocate(sizeof(lab_interfaces__msg__NumArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = lab_interfaces__msg__NumArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
lab_interfaces__msg__NumArray__Sequence__destroy(lab_interfaces__msg__NumArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    lab_interfaces__msg__NumArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
lab_interfaces__msg__NumArray__Sequence__are_equal(const lab_interfaces__msg__NumArray__Sequence * lhs, const lab_interfaces__msg__NumArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!lab_interfaces__msg__NumArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
lab_interfaces__msg__NumArray__Sequence__copy(
  const lab_interfaces__msg__NumArray__Sequence * input,
  lab_interfaces__msg__NumArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(lab_interfaces__msg__NumArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    lab_interfaces__msg__NumArray * data =
      (lab_interfaces__msg__NumArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!lab_interfaces__msg__NumArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          lab_interfaces__msg__NumArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!lab_interfaces__msg__NumArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
