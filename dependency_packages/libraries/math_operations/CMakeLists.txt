cmake_minimum_required(VERSION 3.5)
project(math_operations)

set(CMAKE_CXX_STANDARD 20)

find_package(rclcpp REQUIRED)
find_package(scion_types REQUIRED)
find_package(std_srvs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_library(ROBOT_TYPES robot_types)

include_directories(include)

file(GLOB SOURCES src/*.cpp)

# Add your package's source files
add_library(
    math_operations
    SHARED 
    ${SOURCES}
)

target_link_libraries(math_operations
  ${ROBOT_TYPES}
)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

file(GLOB HEADERS include/*.hpp)

install(FILES ${HEADERS} DESTINATION include/robot_libraries)

ament_target_dependencies(math_operations scion_types rclcpp std_srvs std_msgs sensor_msgs)
