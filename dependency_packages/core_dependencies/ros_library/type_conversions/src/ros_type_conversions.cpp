#include "ros_operations.hpp"

RTL::RobotState RosOperations::TypeConversions::updateRobotStateFromMessage(const scion_types::msg::State::SharedPtr msg, RTL::RobotState& robot_state)
{
    if (msg->orientation.yaw.set)   {robot_state.orientation.yaw = msg->orientation.yaw.value;}
    if (msg->orientation.pitch.set) {robot_state.orientation.pitch = msg->orientation.pitch.value;}
    if (msg->orientation.roll.set)  {robot_state.orientation.roll = msg->orientation.roll.value;}
    if (msg->position.x_pos.set)    {robot_state.position.x_pos = msg->position.x_pos.value;}
    if (msg->position.y_pos.set)    {robot_state.position.y_pos = msg->position.y_pos.value;}
    if (msg->position.z_pos.set)    {robot_state.position.z_pos = msg->position.z_pos.value;}
    return robot_state;
}

RTL::RobotState RosOperations::TypeConversions::fromStateMsgToRobotState(const scion_types::msg::State::SharedPtr msg)
{
    RTL::RobotState robot_state;
    if (msg->orientation.yaw.set)   {robot_state.orientation.yaw = msg->orientation.yaw.value;}
    if (msg->orientation.pitch.set) {robot_state.orientation.pitch = msg->orientation.pitch.value;}
    if (msg->orientation.roll.set)  {robot_state.orientation.roll = msg->orientation.roll.value;}
    if (msg->position.x_pos.set)    {robot_state.position.x_pos = msg->position.x_pos.value;}
    if (msg->position.y_pos.set)    {robot_state.position.y_pos = msg->position.y_pos.value;}
    if (msg->position.z_pos.set)    {robot_state.position.z_pos = msg->position.z_pos.value;}
    return robot_state;
}

scion_types::msg::State RosOperations::TypeConversions::fromRobotStateToStateMsg(const RTL::RobotState& robot_state)
{
    scion_types::msg::State msg =  scion_types::msg::State();
    msg.orientation.yaw.value =    robot_state.orientation.yaw;
    msg.orientation.pitch.value =  robot_state.orientation.pitch;
    msg.orientation.roll.value =   robot_state.orientation.roll;
    msg.position.x_pos.value =     robot_state.position.x_pos;
    msg.position.y_pos.value =     robot_state.position.y_pos;
    msg.position.z_pos.value =     robot_state.position.z_pos;
    return msg;
}

scion_types::srv::GetDesiredState::Response RosOperations::TypeConversions::fromRobotStateToGetDesiredStateResponse(const RTL::RobotState& robot_state)
{
    scion_types::srv::GetDesiredState::Response response = scion_types::srv::GetDesiredState::Response();
    response.desired_state.orientation.yaw.value =    robot_state.orientation.yaw;
    response.desired_state.orientation.pitch.value =  robot_state.orientation.pitch;
    response.desired_state.orientation.roll.value =   robot_state.orientation.roll;
    response.desired_state.position.x_pos.value =     robot_state.position.x_pos;
    response.desired_state.position.y_pos.value =     robot_state.position.y_pos;
    response.desired_state.position.z_pos.value =     robot_state.position.z_pos;
    return response;
}

scion_types::srv::GetAbsoluteState::Response RosOperations::TypeConversions::fromRobotStateToGetAbsoluteStateResponse(const RTL::RobotState& robot_state)
{
    scion_types::srv::GetAbsoluteState::Response response = scion_types::srv::GetAbsoluteState::Response();
    response.absolute_state.orientation.yaw.value =    robot_state.orientation.yaw;
    response.absolute_state.orientation.pitch.value =  robot_state.orientation.pitch;
    response.absolute_state.orientation.roll.value =   robot_state.orientation.roll;
    response.absolute_state.position.x_pos.value =     robot_state.position.x_pos;
    response.absolute_state.position.y_pos.value =     robot_state.position.y_pos;
    response.absolute_state.position.z_pos.value =     robot_state.position.z_pos;
    return response;
}

RTL::RobotState RosOperations::TypeConversions::fromGetDesiredStateRequestToRobotState(const RTL::change_desired_state_request_t request)
{
    RTL::RobotState robot_state;
    if (request->requested_state.orientation.yaw.set)   {robot_state.orientation.yaw = request->requested_state.orientation.yaw.value;}
    if (request->requested_state.orientation.pitch.set) {robot_state.orientation.pitch = request->requested_state.orientation.pitch.value;}
    if (request->requested_state.orientation.roll.set)  {robot_state.orientation.roll = request->requested_state.orientation.roll.value;}
    if (request->requested_state.position.x_pos.set)    {robot_state.position.x_pos = request->requested_state.position.x_pos.value;}
    if (request->requested_state.position.y_pos.set)    {robot_state.position.y_pos = request->requested_state.position.y_pos.value;}
    if (request->requested_state.position.z_pos.set)    {robot_state.position.z_pos = request->requested_state.position.z_pos.value;}
    return robot_state;
}

scion_types::srv::ChangeDesiredState::Response RosOperations::TypeConversions::fromRobotStateToChangeDesiredStateResponse(const RTL::RobotState& robot_state)
{
    scion_types::srv::ChangeDesiredState::Response response = scion_types::srv::ChangeDesiredState::Response();
    response.desired_state.orientation.yaw.value =    robot_state.orientation.yaw;
    response.desired_state.orientation.pitch.value =  robot_state.orientation.pitch;
    response.desired_state.orientation.roll.value =   robot_state.orientation.roll;
    response.desired_state.position.x_pos.value =     robot_state.position.x_pos;
    response.desired_state.position.y_pos.value =     robot_state.position.y_pos;
    response.desired_state.position.z_pos.value =     robot_state.position.z_pos;
    return response;
}

RTL::RobotState RosOperations::TypeConversions::fromGetDesiredStateResponseToRobotState(const scion_types::srv::GetDesiredState::Response& response)
{
    RTL::RobotState robot_state;
    if (response.desired_state.orientation.yaw.set)   {robot_state.orientation.yaw = response.desired_state.orientation.yaw.value;}
    if (response.desired_state.orientation.pitch.set) {robot_state.orientation.pitch = response.desired_state.orientation.pitch.value;}
    if (response.desired_state.orientation.roll.set)  {robot_state.orientation.roll = response.desired_state.orientation.roll.value;}
    if (response.desired_state.position.x_pos.set)    {robot_state.position.x_pos = response.desired_state.position.x_pos.value;}
    if (response.desired_state.position.y_pos.set)    {robot_state.position.y_pos = response.desired_state.position.y_pos.value;}
    if (response.desired_state.position.z_pos.set)    {robot_state.position.z_pos = response.desired_state.position.z_pos.value;}
    return robot_state;
}

RTL::RobotState RosOperations::TypeConversions::fromChangeDesiredStateResponseToRobotState(const scion_types::srv::ChangeDesiredState::Response& response)
{
    RTL::RobotState robot_state;
    if (response.desired_state.orientation.yaw.set)   {robot_state.orientation.yaw = response.desired_state.orientation.yaw.value;}
    if (response.desired_state.orientation.pitch.set) {robot_state.orientation.pitch = response.desired_state.orientation.pitch.value;}
    if (response.desired_state.orientation.roll.set)  {robot_state.orientation.roll = response.desired_state.orientation.roll.value;}
    if (response.desired_state.position.x_pos.set)    {robot_state.position.x_pos = response.desired_state.position.x_pos.value;}
    if (response.desired_state.position.y_pos.set)    {robot_state.position.y_pos = response.desired_state.position.y_pos.value;}
    if (response.desired_state.position.z_pos.set)    {robot_state.position.z_pos = response.desired_state.position.z_pos.value;}
    return robot_state;
}

RTL::RobotState RosOperations::TypeConversions::fromGetAbsoluteStateResponseToRobotState(const scion_types::srv::GetAbsoluteState::Response& response)
{
    RTL::RobotState robot_state;
    if (response.absolute_state.orientation.yaw.set)   {robot_state.orientation.yaw = response.absolute_state.orientation.yaw.value;}
    if (response.absolute_state.orientation.pitch.set) {robot_state.orientation.pitch = response.absolute_state.orientation.pitch.value;}
    if (response.absolute_state.orientation.roll.set)  {robot_state.orientation.roll = response.absolute_state.orientation.roll.value;}
    if (response.absolute_state.position.x_pos.set)    {robot_state.position.x_pos = response.absolute_state.position.x_pos.value;}
    if (response.absolute_state.position.y_pos.set)    {robot_state.position.y_pos = response.absolute_state.position.y_pos.value;}
    if (response.absolute_state.position.z_pos.set)    {robot_state.position.z_pos = response.absolute_state.position.z_pos.value;}
    return robot_state;
}