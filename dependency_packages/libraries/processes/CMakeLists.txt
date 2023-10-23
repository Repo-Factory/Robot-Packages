cmake_minimum_required(VERSION 3.5)
project(processes)

set(CMAKE_CXX_STANDARD 20)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
include_directories(include)

# Add your package's source files
add_library(
    processes 
    SHARED
    src/processes.cpp
)

target_link_libraries(processes
  ${rclcpp_LIBRARIES}
  PRIVATE Threads::Threads
)

add_executable(${PROJECT_NAME}_exec
    main/main.cpp
)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${PROJECT_NAME}_exec DESTINATION bin/robot)

file(GLOB HEADERS include/processes.hpp)

install(FILES ${HEADERS} DESTINATION include/robot_libraries)