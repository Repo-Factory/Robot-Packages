cmake_minimum_required(VERSION 3.5)
project(component)

set(CMAKE_CXX_STANDARD 20)

find_package(rclcpp REQUIRED)

add_library(component 
    SHARED
    src/component.cpp
)

target_include_directories(
    component PUBLIC 
    include
)

# Add your package's source files
add_executable(
    component_exec
    src/main.cpp
)

target_link_libraries(
  component_exec
  component
)

ament_target_dependencies(component rclcpp)

# Install the executable
install(TARGETS component
  DESTINATION lib
)

file(GLOB HEADERS include/component.hpp)

install(FILES ${HEADERS} DESTINATION include/robot_libraries)
