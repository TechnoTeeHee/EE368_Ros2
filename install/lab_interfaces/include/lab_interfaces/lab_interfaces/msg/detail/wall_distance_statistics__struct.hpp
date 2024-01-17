// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lab_interfaces:msg/WallDistanceStatistics.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__STRUCT_HPP_
#define LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lab_interfaces__msg__WallDistanceStatistics __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__msg__WallDistanceStatistics __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WallDistanceStatistics_
{
  using Type = WallDistanceStatistics_<ContainerAllocator>;

  explicit WallDistanceStatistics_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mean = 0.0;
      this->std = 0.0;
    }
  }

  explicit WallDistanceStatistics_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mean = 0.0;
      this->std = 0.0;
    }
  }

  // field types and members
  using _mean_type =
    double;
  _mean_type mean;
  using _std_type =
    double;
  _std_type std;

  // setters for named parameter idiom
  Type & set__mean(
    const double & _arg)
  {
    this->mean = _arg;
    return *this;
  }
  Type & set__std(
    const double & _arg)
  {
    this->std = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__msg__WallDistanceStatistics
    std::shared_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__msg__WallDistanceStatistics
    std::shared_ptr<lab_interfaces::msg::WallDistanceStatistics_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WallDistanceStatistics_ & other) const
  {
    if (this->mean != other.mean) {
      return false;
    }
    if (this->std != other.std) {
      return false;
    }
    return true;
  }
  bool operator!=(const WallDistanceStatistics_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WallDistanceStatistics_

// alias to use template instance with default allocator
using WallDistanceStatistics =
  lab_interfaces::msg::WallDistanceStatistics_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__MSG__DETAIL__WALL_DISTANCE_STATISTICS__STRUCT_HPP_
