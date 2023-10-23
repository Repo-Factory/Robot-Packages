#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <stdlib.h>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <robot_libraries/robot.hpp>
#include <robot_libraries/component.hpp>
#include <robot_libraries/vector_operations.hpp>
#include <robot_libraries/can_client.hpp>

typedef void (CanClient::*button_function)();

class Controller : public Component
{
    public:
        Controller(const Robot& robot);
    private:
        std::vector<bool>                                           buttons;
        std::vector<button_function>                                button_functions;
        rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr      controller_sub;
        const Robot&                                                robot;
        std::shared_ptr<CanClient>                                  can_client;

        void controller_subscription_callback(const sensor_msgs::msg::Joy::SharedPtr msg);
        void processStickInputs(const std::vector<float>& ctrl_vals);
        void processButtonInputs(const std::vector<bool>& button_inputs);
};

#endif