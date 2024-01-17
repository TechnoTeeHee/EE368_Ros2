// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lab_interfaces:msg/WallDistanceStatistics.idl
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
#include "lab_interfaces/msg/detail/wall_distance_statistics__struct.h"
#include "lab_interfaces/msg/detail/wall_distance_statistics__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool lab_interfaces__msg__wall_distance_statistics__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[68];
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
    assert(strncmp("lab_interfaces.msg._wall_distance_statistics.WallDistanceStatistics", full_classname_dest, 67) == 0);
  }
  lab_interfaces__msg__WallDistanceStatistics * ros_message = _ros_message;
  {  // mean
    PyObject * field = PyObject_GetAttrString(_pymsg, "mean");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->mean = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // std
    PyObject * field = PyObject_GetAttrString(_pymsg, "std");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->std = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lab_interfaces__msg__wall_distance_statistics__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of WallDistanceStatistics */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lab_interfaces.msg._wall_distance_statistics");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "WallDistanceStatistics");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lab_interfaces__msg__WallDistanceStatistics * ros_message = (lab_interfaces__msg__WallDistanceStatistics *)raw_ros_message;
  {  // mean
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->mean);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mean", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // std
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->std);
    {
      int rc = PyObject_SetAttrString(_pymessage, "std", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
