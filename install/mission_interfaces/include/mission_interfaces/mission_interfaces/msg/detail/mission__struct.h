// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mission_interfaces:msg/Mission.idl
// generated code does not contain a copyright notice

#ifndef MISSION_INTERFACES__MSG__DETAIL__MISSION__STRUCT_H_
#define MISSION_INTERFACES__MSG__DETAIL__MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
// Member 'target'
// Member 'mission'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Mission in the package mission_interfaces.
typedef struct mission_interfaces__msg__Mission
{
  rosidl_runtime_c__String command;
  rosidl_runtime_c__String target;
  rosidl_runtime_c__String mission;
  float distance;
  float angle;
} mission_interfaces__msg__Mission;

// Struct for a sequence of mission_interfaces__msg__Mission.
typedef struct mission_interfaces__msg__Mission__Sequence
{
  mission_interfaces__msg__Mission * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mission_interfaces__msg__Mission__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MISSION_INTERFACES__MSG__DETAIL__MISSION__STRUCT_H_
