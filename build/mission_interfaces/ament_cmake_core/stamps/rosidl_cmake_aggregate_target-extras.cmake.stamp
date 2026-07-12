# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target mission_interfaces::mission_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${mission_interfaces_TARGETS}.
if(mission_interfaces_TARGETS AND NOT TARGET mission_interfaces::mission_interfaces)
  add_library(mission_interfaces::mission_interfaces INTERFACE IMPORTED)
  set_target_properties(mission_interfaces::mission_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${mission_interfaces_TARGETS}")
endif()
