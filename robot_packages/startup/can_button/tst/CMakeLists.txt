cmake_minimum_required(VERSION 3.5)
project(test_can_button)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
    ${PROJECT_NAME}_exec
    src/test_can_button.cpp
    main/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}_exec PRIVATE 
    can_button
    gtest
    gmock
    gtest_main
)

install(
    TARGETS ${PROJECT_NAME}_exec 
    DESTINATION bin/test_robot
)

