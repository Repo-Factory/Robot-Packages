#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

#include <vector>
#include <map>
#include <iostream>
#include <deque>
#include <unordered_map>
#include <memory>
#include "struct_types.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "std_srvs/srv/set_bool.hpp"
#include "scion_types/srv/send_frame.hpp"
#include "scion_types/srv/get_desired_state.hpp"
#include "scion_types/srv/get_absolute_state.hpp"
#include "scion_types/srv/change_desired_state.hpp"
#include "scion_types/srv/update_pid.hpp"
#include "scion_types/msg/idea.hpp"
#include "scion_types/msg/state.hpp"
#include "scion_types/msg/position.hpp"
#include "scion_types/msg/orientation.hpp"
#include "scion_types/msg/datapoint.hpp"
#include "scion_types/msg/vision_object.hpp"
#include "scion_types/msg/zed_object.hpp"
#include "scion_types/msg/pid_tuning.hpp"
#include "scion_types/msg/raw_data.hpp"
#include "scion_types/msg/sub_state.hpp"
#include "scion_types/action/pid.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"

namespace RTL   // RobotTypeLibrary
{
    /* Custom Types to Use In Control System */
    typedef std::vector<float>                                                              current_state_t;
    typedef std::vector<float>                                                              desired_state_t;
    typedef scion_types::msg::Idea                                                          idea_message_t;
    typedef std::vector<scion_types::msg::Idea>                                             idea_vector_t;
    typedef std::vector<std::vector<float>>                                                 matrix_t;
    typedef std::map<std::string, std::shared_ptr<RawSensorStream>>                         rawdata_map_t;                                                                                                                                                              

    /* General ROS Types */
    typedef rclcpp::Node::SharedPtr                                                         node_t;
    typedef rclcpp::TimerBase::SharedPtr                                                    ros_timer_t;

    /* Clients  */
    typedef rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr                               ros_trigger_client_t;
    typedef rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr                               ros_bool_client_t;
    typedef rclcpp::Client<scion_types::srv::SendFrame>::SharedPtr                          ros_sendframe_client_t;
    typedef rclcpp::Client<scion_types::srv::GetDesiredState>::SharedPtr                    get_desired_state_client_t;
    typedef rclcpp::Client<scion_types::srv::GetAbsoluteState>::SharedPtr                   get_absolute_state_client_t;
    typedef rclcpp::Client<scion_types::srv::ChangeDesiredState>::SharedPtr                 change_desired_state_client_t;
    typedef rclcpp::Client<scion_types::srv::UpdatePid>::SharedPtr                          update_pid_client_t;

    
    /* Services */
    typedef rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr                              ros_trigger_service_t;
    typedef rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr                              ros_bool_service_t;
    typedef rclcpp::Service<scion_types::srv::SendFrame>::SharedPtr                         ros_sendframe_service_t;
    typedef rclcpp::Service<scion_types::srv::GetDesiredState>::SharedPtr                   get_desired_state_service_t;
    typedef rclcpp::Service<scion_types::srv::GetAbsoluteState>::SharedPtr                  get_absolute_state_service_t;
    typedef rclcpp::Service<scion_types::srv::ChangeDesiredState>::SharedPtr                change_desired_state_service_t;
    typedef rclcpp::Service<scion_types::srv::UpdatePid>::SharedPtr                         update_pid_service_t;


    /* Subscriptions */
    typedef rclcpp::Subscription<scion_types::msg::Datapoint>::SharedPtr                    datapoint_sub_t;
    typedef rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr                           int_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::Idea>::SharedPtr                         idea_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::VisionObject>::SharedPtr                 object_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::Orientation>::SharedPtr                  orientation_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::Position>::SharedPtr                     position_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::RawData>::SharedPtr                      rawdata_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::State>::SharedPtr                        state_sub_t;
    typedef rclcpp::Subscription<std_msgs::msg::String>::SharedPtr                          string_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::SubState>::SharedPtr                     sub_state_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::PidTuning>::SharedPtr                    tune_pid_sub_t;
    typedef rclcpp::Subscription<scion_types::msg::ZedObject>::SharedPtr                    vision_sub_t;

    /* Publishers */
    typedef rclcpp::Publisher<scion_types::msg::Datapoint>::SharedPtr                       datapoint_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::Idea>::SharedPtr                            idea_pub_t;
    typedef rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr                              int_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::VisionObject>::SharedPtr                    object_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::Orientation>::SharedPtr                     orientation_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::Position>::SharedPtr                        position_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::RawData>::SharedPtr                         rawdata_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::State>::SharedPtr                           state_pub_t;
    typedef rclcpp::Publisher<std_msgs::msg::String>::SharedPtr                             string_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::SubState>::SharedPtr                        sub_state_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::PidTuning>::SharedPtr                       tune_pid_pub_t;
    typedef rclcpp::Publisher<scion_types::msg::ZedObject>::SharedPtr                       vision_pub_t;
    
    /* Requests/Responses */
    typedef std::shared_ptr<std_srvs::srv::Trigger::Request>                                trigger_request_t;
    typedef std::shared_ptr<std_srvs::srv::Trigger::Response>                               trigger_response_t;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<scion_types::srv::UpdatePid::Request>                           update_pid_request_t;
    typedef std::shared_ptr<scion_types::srv::UpdatePid::Response>                          update_pid_response_t;
    typedef rclcpp::Client<scion_types::srv::UpdatePid>::SharedFuture                       update_pid_future_t;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<scion_types::srv::GetDesiredState::Request>                     get_desired_state_request_t;
    typedef std::shared_ptr<scion_types::srv::GetDesiredState::Response>                    get_desired_state_response_t;
    typedef rclcpp::Client<scion_types::srv::GetDesiredState>::SharedFuture                 get_desired_state_future_t;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<scion_types::srv::GetAbsoluteState::Request>                    get_absolute_state_request_t;
    typedef std::shared_ptr<scion_types::srv::GetAbsoluteState::Response>                   get_absolute_state_response_t;
    typedef rclcpp::Client<scion_types::srv::GetAbsoluteState>::SharedFuture                get_absolute_state_future_t;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    typedef std::shared_ptr<scion_types::srv::ChangeDesiredState::Request>                  change_desired_state_request_t;
    typedef std::shared_ptr<scion_types::srv::ChangeDesiredState::Response>                 change_desired_state_response_t;
    typedef rclcpp::Client<scion_types::srv::ChangeDesiredState>::SharedFuture              change_desired_state_future_t;
}

#endif
