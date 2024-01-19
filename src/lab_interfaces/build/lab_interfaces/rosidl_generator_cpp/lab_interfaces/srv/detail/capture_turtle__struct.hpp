// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lab_interfaces:srv/CaptureTurtle.idl
// generated code does not contain a copyright notice

#ifndef LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__STRUCT_HPP_
#define LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lab_interfaces__srv__CaptureTurtle_Request __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__srv__CaptureTurtle_Request __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CaptureTurtle_Request_
{
  using Type = CaptureTurtle_Request_<ContainerAllocator>;

  explicit CaptureTurtle_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  explicit CaptureTurtle_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__srv__CaptureTurtle_Request
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__srv__CaptureTurtle_Request
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CaptureTurtle_Request_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    return true;
  }
  bool operator!=(const CaptureTurtle_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CaptureTurtle_Request_

// alias to use template instance with default allocator
using CaptureTurtle_Request =
  lab_interfaces::srv::CaptureTurtle_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lab_interfaces


#ifndef _WIN32
# define DEPRECATED__lab_interfaces__srv__CaptureTurtle_Response __attribute__((deprecated))
#else
# define DEPRECATED__lab_interfaces__srv__CaptureTurtle_Response __declspec(deprecated)
#endif

namespace lab_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CaptureTurtle_Response_
{
  using Type = CaptureTurtle_Response_<ContainerAllocator>;

  explicit CaptureTurtle_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
      this->message = "";
    }
  }

  explicit CaptureTurtle_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = false;
      this->message = "";
    }
  }

  // field types and members
  using _status_type =
    bool;
  _status_type status;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__status(
    const bool & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lab_interfaces__srv__CaptureTurtle_Response
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lab_interfaces__srv__CaptureTurtle_Response
    std::shared_ptr<lab_interfaces::srv::CaptureTurtle_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CaptureTurtle_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const CaptureTurtle_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CaptureTurtle_Response_

// alias to use template instance with default allocator
using CaptureTurtle_Response =
  lab_interfaces::srv::CaptureTurtle_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lab_interfaces

namespace lab_interfaces
{

namespace srv
{

struct CaptureTurtle
{
  using Request = lab_interfaces::srv::CaptureTurtle_Request;
  using Response = lab_interfaces::srv::CaptureTurtle_Response;
};

}  // namespace srv

}  // namespace lab_interfaces

#endif  // LAB_INTERFACES__SRV__DETAIL__CAPTURE_TURTLE__STRUCT_HPP_