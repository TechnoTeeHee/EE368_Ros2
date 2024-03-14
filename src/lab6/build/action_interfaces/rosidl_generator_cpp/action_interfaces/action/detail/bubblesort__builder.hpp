// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interfaces:action/Bubblesort.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__BUBBLESORT__BUILDER_HPP_
#define ACTION_INTERFACES__ACTION__DETAIL__BUBBLESORT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interfaces/action/detail/bubblesort__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_Goal_order
{
public:
  Init_Bubblesort_Goal_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::Bubblesort_Goal order(::action_interfaces::action::Bubblesort_Goal::_order_type arg)
  {
    msg_.order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_Goal>()
{
  return action_interfaces::action::builder::Init_Bubblesort_Goal_order();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_Result_j
{
public:
  explicit Init_Bubblesort_Result_j(::action_interfaces::action::Bubblesort_Result & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Bubblesort_Result j(::action_interfaces::action::Bubblesort_Result::_j_type arg)
  {
    msg_.j = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Result msg_;
};

class Init_Bubblesort_Result_i
{
public:
  explicit Init_Bubblesort_Result_i(::action_interfaces::action::Bubblesort_Result & msg)
  : msg_(msg)
  {}
  Init_Bubblesort_Result_j i(::action_interfaces::action::Bubblesort_Result::_i_type arg)
  {
    msg_.i = std::move(arg);
    return Init_Bubblesort_Result_j(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Result msg_;
};

class Init_Bubblesort_Result_sequence
{
public:
  Init_Bubblesort_Result_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bubblesort_Result_i sequence(::action_interfaces::action::Bubblesort_Result::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return Init_Bubblesort_Result_i(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_Result>()
{
  return action_interfaces::action::builder::Init_Bubblesort_Result_sequence();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_Feedback_j
{
public:
  explicit Init_Bubblesort_Feedback_j(::action_interfaces::action::Bubblesort_Feedback & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Bubblesort_Feedback j(::action_interfaces::action::Bubblesort_Feedback::_j_type arg)
  {
    msg_.j = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Feedback msg_;
};

class Init_Bubblesort_Feedback_i
{
public:
  explicit Init_Bubblesort_Feedback_i(::action_interfaces::action::Bubblesort_Feedback & msg)
  : msg_(msg)
  {}
  Init_Bubblesort_Feedback_j i(::action_interfaces::action::Bubblesort_Feedback::_i_type arg)
  {
    msg_.i = std::move(arg);
    return Init_Bubblesort_Feedback_j(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Feedback msg_;
};

class Init_Bubblesort_Feedback_partial_sequence
{
public:
  Init_Bubblesort_Feedback_partial_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bubblesort_Feedback_i partial_sequence(::action_interfaces::action::Bubblesort_Feedback::_partial_sequence_type arg)
  {
    msg_.partial_sequence = std::move(arg);
    return Init_Bubblesort_Feedback_i(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_Feedback>()
{
  return action_interfaces::action::builder::Init_Bubblesort_Feedback_partial_sequence();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_SendGoal_Request_goal
{
public:
  explicit Init_Bubblesort_SendGoal_Request_goal(::action_interfaces::action::Bubblesort_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Bubblesort_SendGoal_Request goal(::action_interfaces::action::Bubblesort_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_SendGoal_Request msg_;
};

class Init_Bubblesort_SendGoal_Request_goal_id
{
public:
  Init_Bubblesort_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bubblesort_SendGoal_Request_goal goal_id(::action_interfaces::action::Bubblesort_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Bubblesort_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_SendGoal_Request>()
{
  return action_interfaces::action::builder::Init_Bubblesort_SendGoal_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_SendGoal_Response_stamp
{
public:
  explicit Init_Bubblesort_SendGoal_Response_stamp(::action_interfaces::action::Bubblesort_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Bubblesort_SendGoal_Response stamp(::action_interfaces::action::Bubblesort_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_SendGoal_Response msg_;
};

class Init_Bubblesort_SendGoal_Response_accepted
{
public:
  Init_Bubblesort_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bubblesort_SendGoal_Response_stamp accepted(::action_interfaces::action::Bubblesort_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Bubblesort_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_SendGoal_Response>()
{
  return action_interfaces::action::builder::Init_Bubblesort_SendGoal_Response_accepted();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_GetResult_Request_goal_id
{
public:
  Init_Bubblesort_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interfaces::action::Bubblesort_GetResult_Request goal_id(::action_interfaces::action::Bubblesort_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_GetResult_Request>()
{
  return action_interfaces::action::builder::Init_Bubblesort_GetResult_Request_goal_id();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_GetResult_Response_result
{
public:
  explicit Init_Bubblesort_GetResult_Response_result(::action_interfaces::action::Bubblesort_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Bubblesort_GetResult_Response result(::action_interfaces::action::Bubblesort_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_GetResult_Response msg_;
};

class Init_Bubblesort_GetResult_Response_status
{
public:
  Init_Bubblesort_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bubblesort_GetResult_Response_result status(::action_interfaces::action::Bubblesort_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Bubblesort_GetResult_Response_result(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_GetResult_Response>()
{
  return action_interfaces::action::builder::Init_Bubblesort_GetResult_Response_status();
}

}  // namespace action_interfaces


namespace action_interfaces
{

namespace action
{

namespace builder
{

class Init_Bubblesort_FeedbackMessage_feedback
{
public:
  explicit Init_Bubblesort_FeedbackMessage_feedback(::action_interfaces::action::Bubblesort_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interfaces::action::Bubblesort_FeedbackMessage feedback(::action_interfaces::action::Bubblesort_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_FeedbackMessage msg_;
};

class Init_Bubblesort_FeedbackMessage_goal_id
{
public:
  Init_Bubblesort_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Bubblesort_FeedbackMessage_feedback goal_id(::action_interfaces::action::Bubblesort_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Bubblesort_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interfaces::action::Bubblesort_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interfaces::action::Bubblesort_FeedbackMessage>()
{
  return action_interfaces::action::builder::Init_Bubblesort_FeedbackMessage_goal_id();
}

}  // namespace action_interfaces

#endif  // ACTION_INTERFACES__ACTION__DETAIL__BUBBLESORT__BUILDER_HPP_
