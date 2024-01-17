// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lab_interfaces:msg/WallDistanceMeasurement.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__STRUCT_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lab_interfaces__msg__WallDistanceMeasurement __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__msg__WallDistanceMeasurement __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WallDistanceMeasurement_
{
  using Type = WallDistanceMeasurement_<ContainerAllocator>;

  explicit WallDistanceMeasurement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->dist = 0.0;
    }
  }

  explicit WallDistanceMeasurement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->dist = 0.0;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _dist_type =
    double;
  _dist_type dist;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__dist(
    const double & _arg)
  {
    this->dist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__msg__WallDistanceMeasurement
    std::shared_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__msg__WallDistanceMeasurement
    std::shared_ptr<lab_interfaces::msg::WallDistanceMeasurement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WallDistanceMeasurement_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->dist != other.dist) {
      return false;
    }
    return true;
  }
  bool operator!=(const WallDistanceMeasurement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WallDistanceMeasurement_

// alias to use template instance with default allocator
using WallDistanceMeasurement =
  lab_interfaces::msg::WallDistanceMeasurement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_MEASUREMENT__STRUCT_HPP_
