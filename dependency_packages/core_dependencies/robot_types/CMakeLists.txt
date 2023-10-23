cmake_minimum_required(VERSION 3.5.0)

project(robot_types)

find_package(rclcpp REQUIRED)
find_package(scion_types REQUIRED)
find_package(std_srvs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

file(GLOB SOURCES src/dummy.cpp)

include_directories(include)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

file(GLOB HEADERS 
    include/robot_types.hpp
    include/struct_types.hpp        
)

install(FILES ${HEADERS} DESTINATION include/robot_libraries)

ament_target_dependencies(robot_types scion_types rclcpp std_srvs std_msgs sensor_msgs)
