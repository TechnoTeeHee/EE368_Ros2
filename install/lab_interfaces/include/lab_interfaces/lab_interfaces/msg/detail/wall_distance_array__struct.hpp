// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lab_interfaces:msg/WallDistanceArray.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__STRUCT_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'dist_array'
#include "lab_interfaces/msg/detail/wall_distance_measurement__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lab_interfaces__msg__WallDistanceArray __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__msg__WallDistanceArray __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WallDistanceArray_
{
  using Type = WallDistanceArray_<ContainerAllocator>;

  explicit WallDistanceArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit WallDistanceArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _dist_array_type =
    std::vector<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>>;
  _dist_array_type dist_array;

  // setters for named parameter idiom
  Type & set__dist_array(
    const std::vector<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>> & _arg)
  {
    this->dist_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__msg__WallDistanceArray
    std::shared_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__msg__WallDistanceArray
    std::shared_ptr<lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WallDistanceArray_ & other) const
  {
    if (this->dist_array != other.dist_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const WallDistanceArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WallDistanceArray_

// alias to use template instance with default allocator
using WallDistanceArray =
  lab_interfaces::msg::WallDistanceArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_ARRAY__STRUCT_HPP_
