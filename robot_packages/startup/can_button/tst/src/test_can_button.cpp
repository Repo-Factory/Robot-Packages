#include "gtest/gtest.h"
#include "test_can_button.hpp"

TEST_F(CAN_BUTTON_TEST_SUITE, setup_can)
{
    CAN_Setup_Info can_setup_info = setupCan();
}

TEST_F(CAN_BUTTON_TEST_SUITE, start_program)
{
    startTargetProgram("robot_exec");
}