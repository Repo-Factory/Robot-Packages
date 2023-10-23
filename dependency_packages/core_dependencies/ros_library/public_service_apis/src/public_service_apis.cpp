#include "public_service_apis.h"
/* 
 * Two methods
 * Either you have three nodes, and you spin until future 
 * Or you have two nodes and you do an async callback to keep spinning
 * Can't do method two inside of a function, as function will return before callback and it will go out of scope
 */ 
using namespace RTL;

namespace
{
    template<typename clientType>
    bool validateService(const clientType client)
    {
        while (!client->wait_for_service(std::chrono::milliseconds(10))) {
            if (!rclcpp::ok())
                return false;
        }
        return true;
    }

    template<typename responseType, typename futureType, typename clientType>
    responseType makeServiceCall(const node_t node, const clientType client, const std::function<futureType()> makeRequest)
    {
        if(!validateService(client))
            return nullptr;
        auto future = makeRequest();
        rclcpp::spin_until_future_complete(node, future);
        return future.get();
    }
}

/* auto-gen */
update_pid_response_t RosOperations::ServiceAPIs::UpdatePid(const node_t node, const update_pid_client_t client, const std::string& requester_name)
{
    return makeServiceCall<update_pid_response_t, update_pid_future_t>(node, client, [&]() {
        auto update_pid_request = std::make_shared<scion_types::srv::UpdatePid::Request>();
        update_pid_request->requester_name = requester_name;
        return client->async_send_request(update_pid_request).share();
    });
}

get_desired_state_response_t RosOperations::ServiceAPIs::getDesiredState(const node_t node, const get_desired_state_client_t client, const std::string& requester_name)
{
    return makeServiceCall<get_desired_state_response_t, get_desired_state_future_t>(node, client, [&]() {
        auto get_desired_state_request = std::make_shared<scion_types::srv::GetDesiredState::Request>();
        get_desired_state_request->requester_name = requester_name;
        return client->async_send_request(get_desired_state_request).share();
    });
}

change_desired_state_response_t RosOperations::ServiceAPIs::changeDesiredState(const node_t node, const change_desired_state_client_t client, const std::string& requester_name, const scion_types::msg::State& requested_state)
{
    return makeServiceCall<change_desired_state_response_t, change_desired_state_future_t>(node, client, [&]() {
        auto change_desired_state_request = std::make_shared<scion_types::srv::ChangeDesiredState::Request>();
        change_desired_state_request->requester_name = requester_name;
        change_desired_state_request->requested_state = requested_state;
        return client->async_send_request(change_desired_state_request).share();
    });   
}

get_absolute_state_response_t RosOperations::ServiceAPIs::getAbsoluteState(const node_t node, const get_absolute_state_client_t client, const std::string& requester_name)
{
    return makeServiceCall<get_absolute_state_response_t, get_absolute_state_future_t>(node, client, [&]() {
        auto get_absolute_state_request = std::make_shared<scion_types::srv::GetAbsoluteState::Request>();
        get_absolute_state_request->requester_name = requester_name;
        return client->async_send_request(get_absolute_state_request).share();
    });
}
