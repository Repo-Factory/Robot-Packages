cmake_minimum_required(VERSION 3.5)
project(controller_node)

set(CMAKE_CXX_STANDARD 20)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(scion_types REQUIRED)
find_package(std_srvs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_library(MATH_OPERATIONS math_operations)
find_library(COMPONENT component)
find_library(ROBOT_TYPES robot_types)
find_library(CAN_CLIENT can_client)

# Add your package's source files
add_executable(
    controller_exec 
    src/controller_node.cpp
    src/main.cpp
)

# Link gtest and other libraries to  executable
target_link_libraries(controller_exec
  robot_library
  ${rclcpp_LIBRARIES}
  ${COMPONENT}
  ${MATH_OPERATIONS}
  ${ROBOT_TYPES}
  ${CAN_CLIENT}
)

target_include_directories(
    controller_exec PUBLIC 
    include
)

ament_target_dependencies(controller_exec scion_types rclcpp std_srvs std_msgs sensor_msgs)

# Install the executable
install(TARGETS controller_exec
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
