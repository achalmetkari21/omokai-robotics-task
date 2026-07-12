// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mission_interfaces:msg/Mission.idl
// generated code does not contain a copyright notice
#include "mission_interfaces/msg/detail/mission__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `command`
// Member `target`
// Member `mission`
#include "rosidl_runtime_c/string_functions.h"

bool
mission_interfaces__msg__Mission__init(mission_interfaces__msg__Mission * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    mission_interfaces__msg__Mission__fini(msg);
    return false;
  }
  // target
  if (!rosidl_runtime_c__String__init(&msg->target)) {
    mission_interfaces__msg__Mission__fini(msg);
    return false;
  }
  // mission
  if (!rosidl_runtime_c__String__init(&msg->mission)) {
    mission_interfaces__msg__Mission__fini(msg);
    return false;
  }
  // distance
  // angle
  return true;
}

void
mission_interfaces__msg__Mission__fini(mission_interfaces__msg__Mission * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // target
  rosidl_runtime_c__String__fini(&msg->target);
  // mission
  rosidl_runtime_c__String__fini(&msg->mission);
  // distance
  // angle
}

bool
mission_interfaces__msg__Mission__are_equal(const mission_interfaces__msg__Mission * lhs, const mission_interfaces__msg__Mission * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // target
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target), &(rhs->target)))
  {
    return false;
  }
  // mission
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mission), &(rhs->mission)))
  {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  return true;
}

bool
mission_interfaces__msg__Mission__copy(
  const mission_interfaces__msg__Mission * input,
  mission_interfaces__msg__Mission * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // target
  if (!rosidl_runtime_c__String__copy(
      &(input->target), &(output->target)))
  {
    return false;
  }
  // mission
  if (!rosidl_runtime_c__String__copy(
      &(input->mission), &(output->mission)))
  {
    return false;
  }
  // distance
  output->distance = input->distance;
  // angle
  output->angle = input->angle;
  return true;
}

mission_interfaces__msg__Mission *
mission_interfaces__msg__Mission__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mission_interfaces__msg__Mission * msg = (mission_interfaces__msg__Mission *)allocator.allocate(sizeof(mission_interfaces__msg__Mission), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mission_interfaces__msg__Mission));
  bool success = mission_interfaces__msg__Mission__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mission_interfaces__msg__Mission__destroy(mission_interfaces__msg__Mission * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mission_interfaces__msg__Mission__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mission_interfaces__msg__Mission__Sequence__init(mission_interfaces__msg__Mission__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mission_interfaces__msg__Mission * data = NULL;

  if (size) {
    data = (mission_interfaces__msg__Mission *)allocator.zero_allocate(size, sizeof(mission_interfaces__msg__Mission), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mission_interfaces__msg__Mission__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mission_interfaces__msg__Mission__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mission_interfaces__msg__Mission__Sequence__fini(mission_interfaces__msg__Mission__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mission_interfaces__msg__Mission__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mission_interfaces__msg__Mission__Sequence *
mission_interfaces__msg__Mission__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mission_interfaces__msg__Mission__Sequence * array = (mission_interfaces__msg__Mission__Sequence *)allocator.allocate(sizeof(mission_interfaces__msg__Mission__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mission_interfaces__msg__Mission__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mission_interfaces__msg__Mission__Sequence__destroy(mission_interfaces__msg__Mission__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mission_interfaces__msg__Mission__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mission_interfaces__msg__Mission__Sequence__are_equal(const mission_interfaces__msg__Mission__Sequence * lhs, const mission_interfaces__msg__Mission__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mission_interfaces__msg__Mission__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mission_interfaces__msg__Mission__Sequence__copy(
  const mission_interfaces__msg__Mission__Sequence * input,
  mission_interfaces__msg__Mission__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mission_interfaces__msg__Mission);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mission_interfaces__msg__Mission * data =
      (mission_interfaces__msg__Mission *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mission_interfaces__msg__Mission__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mission_interfaces__msg__Mission__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mission_interfaces__msg__Mission__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
