# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lab05_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lab05_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lab05_FOUND FALSE)
  elseif(NOT lab05_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lab05_FOUND FALSE)
  endif()
  return()
endif()
set(_lab05_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lab05_FIND_QUIETLY)
  message(STATUS "Found lab05: 0.0.0 (${lab05_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lab05' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${lab05_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lab05_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${lab05_DIR}/${_extra}")
endforeach()
