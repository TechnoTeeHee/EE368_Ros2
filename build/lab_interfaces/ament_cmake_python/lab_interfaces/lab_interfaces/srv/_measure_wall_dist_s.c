// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "lab_interfaces/srv/detail/measure_wall_dist__struct.h"
#include "lab_interfaces/srv/detail/measure_wall_dist__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool lab_interfaces__srv__measure_wall_dist__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("lab_interfaces.srv._measure_wall_dist.MeasureWallDist_Request", full_classname_dest, 61) == 0);
  }
  lab_interfaces__srv__MeasureWallDist_Request * ros_message = _ros_message;
  ros_message->structure_needs_at_least_one_member = 0;

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lab_interfaces__srv__measure_wall_dist__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MeasureWallDist_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lab_interfaces.srv._measure_wall_dist");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MeasureWallDist_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  (void)raw_ros_message;

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "lab_interfaces/srv/detail/measure_wall_dist__struct.h"
// already included above
// #include "lab_interfaces/srv/detail/measure_wall_dist__functions.h"

bool lab_interfaces__msg__wall_distance_array__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * lab_interfaces__msg__wall_distance_array__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool lab_interfaces__srv__measure_wall_dist__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("lab_interfaces.srv._measure_wall_dist.MeasureWallDist_Response", full_classname_dest, 62) == 0);
  }
  lab_interfaces__srv__MeasureWallDist_Response * ros_message = _ros_message;
  {  // wall_dist_array
    PyObject * field = PyObject_GetAttrString(_pymsg, "wall_dist_array");
    if (!field) {
      return false;
    }
    if (!lab_interfaces__msg__wall_distance_array__convert_from_py(field, &ros_message->wall_dist_array)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lab_interfaces__srv__measure_wall_dist__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MeasureWallDist_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lab_interfaces.srv._measure_wall_dist");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MeasureWallDist_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lab_interfaces__srv__MeasureWallDist_Response * ros_message = (lab_interfaces__srv__MeasureWallDist_Response *)raw_ros_message;
  {  // wall_dist_array
    PyObject * field = NULL;
    field = lab_interfaces__msg__wall_distance_array__convert_to_py(&ros_message->wall_dist_array);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "wall_dist_array", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
