// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lab_interfaces:srv/MeasureWallDist.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__STRUCT_HPP_
#define LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lab_interfaces__srv__MeasureWallDist_Request __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__srv__MeasureWallDist_Request __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MeasureWallDist_Request_
{
  using Type = MeasureWallDist_Request_<ContainerAllocator>;

  explicit MeasureWallDist_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit MeasureWallDist_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__srv__MeasureWallDist_Request
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__srv__MeasureWallDist_Request
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MeasureWallDist_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const MeasureWallDist_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MeasureWallDist_Request_

// alias to use template instance with default allocator
using MeasureWallDist_Request =
  lab_interfaces::srv::MeasureWallDist_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lab_interfaces


// Include directives for member types
// Member 'wall_dist_array'
#include "lab_interfaces/msg/detail/wall_distance_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lab_interfaces__srv__MeasureWallDist_Response __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__srv__MeasureWallDist_Response __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MeasureWallDist_Response_
{
  using Type = MeasureWallDist_Response_<ContainerAllocator>;

  explicit MeasureWallDist_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : wall_dist_array(_init)
  {
    (void)_init;
  }

  explicit MeasureWallDist_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : wall_dist_array(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _wall_dist_array_type =
    lab_interfaces::msg::WallDistanceArray_<ContainerAllocator>;
  _wall_dist_array_type wall_dist_array;

  // setters for named parameter idiom
  Type & set__wall_dist_array(
    const lab_interfaces::msg::WallDistanceArray_<ContainerAllocator> & _arg)
  {
    this->wall_dist_array = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__srv__MeasureWallDist_Response
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__srv__MeasureWallDist_Response
    std::shared_ptr<lab_interfaces::srv::MeasureWallDist_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MeasureWallDist_Response_ & other) const
  {
    if (this->wall_dist_array != other.wall_dist_array) {
      return false;
    }
    return true;
  }
  bool operator!=(const MeasureWallDist_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MeasureWallDist_Response_

// alias to use template instance with default allocator
using MeasureWallDist_Response =
  lab_interfaces::srv::MeasureWallDist_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lab_interfaces

namespace lab_interfaces
{

namespace srv
{

struct MeasureWallDist
{
  using Request = lab_interfaces::srv::MeasureWallDist_Request;
  using Response = lab_interfaces::srv::MeasureWallDist_Response;
};

}  // namespace srv

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__SRV__DETAIL__MEASURE_WALL_DIST__STRUCT_HPP_
