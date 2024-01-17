// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from lab_interfaces:msg/NumArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__FUNCTIONS_H_
#define LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "lab_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "lab_interfaces/msg/detail/num_array__struct.h"

/// Initialize msg/NumArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * lab_interfaces__msg__NumArray
 * )) before or use
 * lab_interfaces__msg__NumArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
bool
lab_interfaces__msg__NumArray__init(lab_interfaces__msg__NumArray * msg);

/// Finalize msg/NumArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
void
lab_interfaces__msg__NumArray__fini(lab_interfaces__msg__NumArray * msg);

/// Create msg/NumArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * lab_interfaces__msg__NumArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
lab_interfaces__msg__NumArray *
lab_interfaces__msg__NumArray__create();

/// Destroy msg/NumArray message.
/**
 * It calls
 * lab_interfaces__msg__NumArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
void
lab_interfaces__msg__NumArray__destroy(lab_interfaces__msg__NumArray * msg);

/// Check for msg/NumArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
bool
lab_interfaces__msg__NumArray__are_equal(const lab_interfaces__msg__NumArray * lhs, const lab_interfaces__msg__NumArray * rhs);

/// Copy a msg/NumArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
bool
lab_interfaces__msg__NumArray__copy(
  const lab_interfaces__msg__NumArray * input,
  lab_interfaces__msg__NumArray * output);

/// Initialize array of msg/NumArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * lab_interfaces__msg__NumArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
bool
lab_interfaces__msg__NumArray__Sequence__init(lab_interfaces__msg__NumArray__Sequence * array, size_t size);

/// Finalize array of msg/NumArray messages.
/**
 * It calls
 * lab_interfaces__msg__NumArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
void
lab_interfaces__msg__NumArray__Sequence__fini(lab_interfaces__msg__NumArray__Sequence * array);

/// Create array of msg/NumArray messages.
/**
 * It allocates the memory for the array and calls
 * lab_interfaces__msg__NumArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
lab_interfaces__msg__NumArray__Sequence *
lab_interfaces__msg__NumArray__Sequence__create(size_t size);

/// Destroy array of msg/NumArray messages.
/**
 * It calls
 * lab_interfaces__msg__NumArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
void
lab_interfaces__msg__NumArray__Sequence__destroy(lab_interfaces__msg__NumArray__Sequence * array);

/// Check for msg/NumArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
bool
lab_interfaces__msg__NumArray__Sequence__are_equal(const lab_interfaces__msg__NumArray__Sequence * lhs, const lab_interfaces__msg__NumArray__Sequence * rhs);

/// Copy an array of msg/NumArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_lab_interfaces
bool
lab_interfaces__msg__NumArray__Sequence__copy(
  const lab_interfaces__msg__NumArray__Sequence * input,
  lab_interfaces__msg__NumArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LAB_INTERFACES__MSG__DETAIL__NUM_ARRAY__FUNCTIONS_H_
