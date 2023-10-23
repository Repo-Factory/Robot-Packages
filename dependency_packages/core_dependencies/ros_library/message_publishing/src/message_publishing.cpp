#include "ros_operations.hpp"

void RosOperations::MessagePublishing::kill(RTL::sub_state_pub_t& sub_state_pub)
{
    #define KILL_MODE 0
    scion_types::msg::SubState msg;
    msg.host_mode = KILL_MODE;
    sub_state_pub->publish(msg);
}