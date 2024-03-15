// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:action/Maze.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MAZE__BUILDER_HPP_
#define ACTION_INTERFACES__ACTION__DETAIL__MAZE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/action/detail/maze__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_Goal_goal_coordinates
{
public:
  Init_Maze_Goal_goal_coordinates()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::Maze_Goal goal_coordinates(::action_interfaces::action::Maze_Goal::_goal_coordinates_type arg)
  {
    msg_.goal_coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_Goal>()
{
  return action_interfaces::action::builder::Init_Maze_Goal_goal_coordinates();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_Result_goal_time
{
public:
  Init_Maze_Result_goal_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::Maze_Result goal_time(::action_interfaces::action::Maze_Result::_goal_time_type arg)
  {
    msg_.goal_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_Result>()
{
  return action_interfaces::action::builder::Init_Maze_Result_goal_time();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_Feedback_time
{
public:
  explicit Init_Maze_Feedback_time(::action_interfaces::action::Maze_Feedback & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Maze_Feedback time(::action_interfaces::action::Maze_Feedback::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

class Init_Maze_Feedback_goal_update
{
public:
  explicit Init_Maze_Feedback_goal_update(::action_interfaces::action::Maze_Feedback & msg)
  : msg_(msg)
  {}
  Init_Maze_Feedback_time goal_update(::action_interfaces::action::Maze_Feedback::_goal_update_type arg)
  {
    msg_.goal_update = std::move(arg);
    return Init_Maze_Feedback_time(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

class Init_Maze_Feedback_n_goal
{
public:
  explicit Init_Maze_Feedback_n_goal(::action_interfaces::action::Maze_Feedback & msg)
  : msg_(msg)
  {}
  Init_Maze_Feedback_goal_update n_goal(::action_interfaces::action::Maze_Feedback::_n_goal_type arg)
  {
    msg_.n_goal = std::move(arg);
    return Init_Maze_Feedback_goal_update(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

class Init_Maze_Feedback_current_goal
{
public:
  explicit Init_Maze_Feedback_current_goal(::action_interfaces::action::Maze_Feedback & msg)
  : msg_(msg)
  {}
  Init_Maze_Feedback_n_goal current_goal(::action_interfaces::action::Maze_Feedback::_current_goal_type arg)
  {
    msg_.current_goal = std::move(arg);
    return Init_Maze_Feedback_n_goal(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

class Init_Maze_Feedback_z
{
public:
  explicit Init_Maze_Feedback_z(::action_interfaces::action::Maze_Feedback & msg)
  : msg_(msg)
  {}
  Init_Maze_Feedback_current_goal z(::action_interfaces::action::Maze_Feedback::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Maze_Feedback_current_goal(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

class Init_Maze_Feedback_y
{
public:
  explicit Init_Maze_Feedback_y(::action_interfaces::action::Maze_Feedback & msg)
  : msg_(msg)
  {}
  Init_Maze_Feedback_z y(::action_interfaces::action::Maze_Feedback::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Maze_Feedback_z(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

class Init_Maze_Feedback_x
{
public:
  Init_Maze_Feedback_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Maze_Feedback_y x(::action_interfaces::action::Maze_Feedback::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Maze_Feedback_y(msg_);
  }

private:
  ::action_interfaces::action::Maze_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_Feedback>()
{
  return action_interfaces::action::builder::Init_Maze_Feedback_x();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_SendGoal_Request_goal
{
public:
  explicit Init_Maze_SendGoal_Request_goal(::action_interfaces::action::Maze_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Maze_SendGoal_Request goal(::action_interfaces::action::Maze_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_SendGoal_Request msg_;
};

class Init_Maze_SendGoal_Request_goal_id
{
public:
  Init_Maze_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Maze_SendGoal_Request_goal goal_id(::action_interfaces::action::Maze_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Maze_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interfaces::action::Maze_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_SendGoal_Request>()
{
  return action_interfaces::action::builder::Init_Maze_SendGoal_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_SendGoal_Response_stamp
{
public:
  explicit Init_Maze_SendGoal_Response_stamp(::action_interfaces::action::Maze_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Maze_SendGoal_Response stamp(::action_interfaces::action::Maze_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_SendGoal_Response msg_;
};

class Init_Maze_SendGoal_Response_accepted
{
public:
  Init_Maze_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Maze_SendGoal_Response_stamp accepted(::action_interfaces::action::Maze_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Maze_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interfaces::action::Maze_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_SendGoal_Response>()
{
  return action_interfaces::action::builder::Init_Maze_SendGoal_Response_accepted();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_GetResult_Request_goal_id
{
public:
  Init_Maze_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::Maze_GetResult_Request goal_id(::action_interfaces::action::Maze_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_GetResult_Request>()
{
  return action_interfaces::action::builder::Init_Maze_GetResult_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_GetResult_Response_result
{
public:
  explicit Init_Maze_GetResult_Response_result(::action_interfaces::action::Maze_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Maze_GetResult_Response result(::action_interfaces::action::Maze_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_GetResult_Response msg_;
};

class Init_Maze_GetResult_Response_status
{
public:
  Init_Maze_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Maze_GetResult_Response_result status(::action_interfaces::action::Maze_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Maze_GetResult_Response_result(msg_);
  }

private:
  ::action_interfaces::action::Maze_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_GetResult_Response>()
{
  return action_interfaces::action::builder::Init_Maze_GetResult_Response_status();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Maze_FeedbackMessage_feedback
{
public:
  explicit Init_Maze_FeedbackMessage_feedback(::action_interfaces::action::Maze_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Maze_FeedbackMessage feedback(::action_interfaces::action::Maze_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Maze_FeedbackMessage msg_;
};

class Init_Maze_FeedbackMessage_goal_id
{
public:
  Init_Maze_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Maze_FeedbackMessage_feedback goal_id(::action_interfaces::action::Maze_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Maze_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interfaces::action::Maze_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Maze_FeedbackMessage>()
{
  return action_interfaces::action::builder::Init_Maze_FeedbackMessage_goal_id();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__ACTION__DETAIL__MAZE__BUILDER_HPP_
