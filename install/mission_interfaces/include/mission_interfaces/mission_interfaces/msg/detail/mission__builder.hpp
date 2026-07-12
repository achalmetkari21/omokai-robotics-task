// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mission_interfaces:msg/Mission.idl
// generated code does not contain a copyright notice

#ifndef MISSION_INTERFACES__MSG__DETAIL__MISSION__BUILDER_HPP_
#define MISSION_INTERFACES__MSG__DETAIL__MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mission_interfaces/msg/detail/mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mission_interfaces
{

namespace msg
{

namespace builder
{

class Init_Mission_angle
{
public:
  explicit Init_Mission_angle(::mission_interfaces::msg::Mission & msg)
  : msg_(msg)
  {}
  ::mission_interfaces::msg::Mission angle(::mission_interfaces::msg::Mission::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mission_interfaces::msg::Mission msg_;
};

class Init_Mission_distance
{
public:
  explicit Init_Mission_distance(::mission_interfaces::msg::Mission & msg)
  : msg_(msg)
  {}
  Init_Mission_angle distance(::mission_interfaces::msg::Mission::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_Mission_angle(msg_);
  }

private:
  ::mission_interfaces::msg::Mission msg_;
};

class Init_Mission_mission
{
public:
  explicit Init_Mission_mission(::mission_interfaces::msg::Mission & msg)
  : msg_(msg)
  {}
  Init_Mission_distance mission(::mission_interfaces::msg::Mission::_mission_type arg)
  {
    msg_.mission = std::move(arg);
    return Init_Mission_distance(msg_);
  }

private:
  ::mission_interfaces::msg::Mission msg_;
};

class Init_Mission_target
{
public:
  explicit Init_Mission_target(::mission_interfaces::msg::Mission & msg)
  : msg_(msg)
  {}
  Init_Mission_mission target(::mission_interfaces::msg::Mission::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_Mission_mission(msg_);
  }

private:
  ::mission_interfaces::msg::Mission msg_;
};

class Init_Mission_command
{
public:
  Init_Mission_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Mission_target command(::mission_interfaces::msg::Mission::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_Mission_target(msg_);
  }

private:
  ::mission_interfaces::msg::Mission msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mission_interfaces::msg::Mission>()
{
  return mission_interfaces::msg::builder::Init_Mission_command();
}

}  // namespace mission_interfaces

#endif  // MISSION_INTERFACES__MSG__DETAIL__MISSION__BUILDER_HPP_
