#ifndef PUBLIC_SERVICE_APIS_H
#define PUBLIC_SERVICE_APIS_H

#include <robot_libraries/robot_types.hpp>

namespace ServiceAPIs
{
    /* auto-gen*/
    RTL::update_pid_response_t UpdatePid(RTL::node_t node, RTL::update_pid_client_t, const std::string& requester_name);
    RTL::get_desired_state_response_t getDesiredState(RTL::node_t node, RTL::get_desired_state_client_t client, const std::string& requester_name);
    RTL::change_desired_state_response_t changeDesiredState(RTL::node_t node, RTL::change_desired_state_client_t client, const std::string& requester_name, const scion_types::msg::State& requested_state);
    RTL::get_absolute_state_response_t getAbsoluteState(RTL::node_t node, RTL::get_absolute_state_client_t, const std::string& requester_name);
};

#endif
