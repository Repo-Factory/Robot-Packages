#ifndef TYPE_CONVERSIONS_H
#define TYPE_CONVERSIONS_H

namespace TypeConversions
{
        RTL::RobotState updateRobotStateFromMessage(const scion_types::msg::State::SharedPtr msg, RTL::RobotState& robot_state);
        RTL::RobotState fromStateMsgToRobotState(const scion_types::msg::State::SharedPtr msg);
        scion_types::msg::State fromRobotStateToStateMsg(const RTL::RobotState& robot_state);
        scion_types::srv::GetDesiredState::Response fromRobotStateToGetDesiredStateResponse(const RTL::RobotState& robot_state);
        scion_types::srv::GetAbsoluteState::Response fromRobotStateToGetAbsoluteStateResponse(const RTL::RobotState& robot_state);
        RTL::RobotState fromGetDesiredStateRequestToRobotState(const RTL::change_desired_state_request_t request);
        scion_types::srv::ChangeDesiredState::Response fromRobotStateToChangeDesiredStateResponse(const RTL::RobotState& robot_state);
        RTL::RobotState fromGetDesiredStateResponseToRobotState(const scion_types::srv::GetDesiredState::Response& response);
        RTL::RobotState fromChangeDesiredStateResponseToRobotState(const scion_types::srv::ChangeDesiredState::Response& response);
        RTL::RobotState fromGetAbsoluteStateResponseToRobotState(const scion_types::srv::GetAbsoluteState::Response& response);
}

#endif
