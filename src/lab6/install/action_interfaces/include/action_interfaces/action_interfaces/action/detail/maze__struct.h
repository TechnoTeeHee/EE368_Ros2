// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interfaces:action/Maze.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACES__ACTION__DETAIL__MAZE__STRUCT_H_
#define ACTION_INTERFACES__ACTION__DETAIL__MAZE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goal_positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_Goal
{
  rosidl_runtime_c__float__Sequence goal_positions;
} action_interfaces__action__Maze_Goal;

// Struct for a sequence of action_interfaces__action__Maze_Goal.
typedef struct action_interfaces__action__Maze_Goal__Sequence
{
  action_interfaces__action__Maze_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_Result
{
  float final_time;
} action_interfaces__action__Maze_Result;

// Struct for a sequence of action_interfaces__action__Maze_Result.
typedef struct action_interfaces__action__Maze_Result__Sequence
{
  action_interfaces__action__Maze_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_goal'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_Feedback
{
  rosidl_runtime_c__float__Sequence current_goal;
  int32_t goal_num;
  float current_x;
  float current_y;
  float yaw;
  float time;
  int32_t goal_reached;
} action_interfaces__action__Maze_Feedback;

// Struct for a sequence of action_interfaces__action__Maze_Feedback.
typedef struct action_interfaces__action__Maze_Feedback__Sequence
{
  action_interfaces__action__Maze_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "action_interfaces/action/detail/maze__struct.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interfaces__action__Maze_Goal goal;
} action_interfaces__action__Maze_SendGoal_Request;

// Struct for a sequence of action_interfaces__action__Maze_SendGoal_Request.
typedef struct action_interfaces__action__Maze_SendGoal_Request__Sequence
{
  action_interfaces__action__Maze_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} action_interfaces__action__Maze_SendGoal_Response;

// Struct for a sequence of action_interfaces__action__Maze_SendGoal_Response.
typedef struct action_interfaces__action__Maze_SendGoal_Response__Sequence
{
  action_interfaces__action__Maze_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} action_interfaces__action__Maze_GetResult_Request;

// Struct for a sequence of action_interfaces__action__Maze_GetResult_Request.
typedef struct action_interfaces__action__Maze_GetResult_Request__Sequence
{
  action_interfaces__action__Maze_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interfaces/action/detail/maze__struct.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_GetResult_Response
{
  int8_t status;
  action_interfaces__action__Maze_Result result;
} action_interfaces__action__Maze_GetResult_Response;

// Struct for a sequence of action_interfaces__action__Maze_GetResult_Response.
typedef struct action_interfaces__action__Maze_GetResult_Response__Sequence
{
  action_interfaces__action__Maze_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "action_interfaces/action/detail/maze__struct.h"

/// Struct defined in action/Maze in the package action_interfaces.
typedef struct action_interfaces__action__Maze_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interfaces__action__Maze_Feedback feedback;
} action_interfaces__action__Maze_FeedbackMessage;

// Struct for a sequence of action_interfaces__action__Maze_FeedbackMessage.
typedef struct action_interfaces__action__Maze_FeedbackMessage__Sequence
{
  action_interfaces__action__Maze_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interfaces__action__Maze_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACES__ACTION__DETAIL__MAZE__STRUCT_H_
