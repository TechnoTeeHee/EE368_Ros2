# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lab_05_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lab_05_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lab_05_FOUND FALSE)
  elseif(NOT lab_05_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lab_05_FOUND FALSE)
  endif()
  return()
endif()
set(_lab_05_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lab_05_FIND_QUIETLY)
  message(STATUS "Found lab_05: 0.0.0 (${lab_05_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lab_05' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${lab_05_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lab_05_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${lab_05_DIR}/${_extra}")
endforeach()
