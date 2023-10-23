/*  
 *  @author Conner Sommerfield
 *  For questions - Zix on Discord
 *  Controller node for transmitting controller commands on PS4 controller as PID alternative
 *  Uses code very similar to PID such as the thrust_mapper matrix
 *  
 *  To run make sure you source properly and:
 *  1. enable the bluetooth device ds4drv
 *  2. ros2 run joy joy_node
 *  3. ros2 run controller_node controller_exec
 */

#include "controller_node.hpp"
#include <robot_libraries/math_operations.hpp>

namespace
{
    #define MAX_POWER 100
    #define CONTROLLER_NODE_NAME "controller"
    #define JOY_NODE_TOPIC_NAME "/joy"
    #define JOY_NODE_QUEUE_SIZE 10
    #define LOOP_INIT_COUNTER 0
}

namespace
{
    #define INVERT -1
    #define DEFAULT_1_OF_TRIGGER_BUTTONS 1
    #define LEFT_STICK_HORIZONTAL_JOY_TOPIC_INDEX 0
    #define LEFT_STICK_VERTICAL_JOY_TOPIC_INDEX 1
    #define RIGHT_STICK_HORIZONTAL_JOY_TOPIC_INDEX 4 
    #define RIGHT_STICK_VERTICAL_JOY_TOPIC_INDEX 3
    #define RIGHT_TRIGGER_JOY_TOPIC_INDEX 5
    #define LEFT_TRIGGER_JOY_TOPIC_INDEX 2
}

namespace
{    
    #define X_BUTTON 0
    #define O_BUTTON 1
    #define TRI_BUTTON 2
    #define SQUARE_BUTTON 3
    #define BUTTON_PRESSED 1
    #define BUTTON_RELEASED 0
}

namespace
{
    std::vector<button_function> populateButtonFunctions()
    {
        return std::vector<button_function> 
        {
            &CanClient::killRobot, 
            &CanClient::allClear, 
            &CanClient::turnOnLight,
            &CanClient::turnOffLight
        };   
    }
}

Controller::Controller(const Robot& robot) : Component(CONTROLLER_NODE_NAME), robot{robot}
{
    this->controller_sub = this->create_subscription<sensor_msgs::msg::Joy>(JOY_NODE_TOPIC_NAME, JOY_NODE_QUEUE_SIZE, std::bind(&Controller::controller_subscription_callback, this, std::placeholders::_1));
    this->buttons = std::vector<bool>{BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};
    this->button_functions = populateButtonFunctions();
    this->can_client = std::make_shared<CanClient>();
}

void Controller::controller_subscription_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
    float yaw   =          INVERT * msg->axes[LEFT_STICK_HORIZONTAL_JOY_TOPIC_INDEX];                                           
    float pitch =                   msg->axes[RIGHT_TRIGGER_JOY_TOPIC_INDEX] - DEFAULT_1_OF_TRIGGER_BUTTONS;       
    float roll  =                   msg->axes[LEFT_TRIGGER_JOY_TOPIC_INDEX] -  DEFAULT_1_OF_TRIGGER_BUTTONS;       
    float x     =                   msg->axes[RIGHT_STICK_HORIZONTAL_JOY_TOPIC_INDEX];                                           
    float y     =          INVERT * msg->axes[RIGHT_STICK_VERTICAL_JOY_TOPIC_INDEX];                                           
    float z     =          INVERT * msg->axes[LEFT_STICK_VERTICAL_JOY_TOPIC_INDEX];

    processStickInputs({yaw, pitch, roll, x, y, z});
    processButtonInputs({(bool)msg->buttons[X_BUTTON], (bool)msg->buttons[O_BUTTON], (bool)msg->buttons[TRI_BUTTON], (bool)msg->buttons[SQUARE_BUTTON]});
}

// Side effect: motor request equal to power provided by stick
void Controller::processStickInputs(const std::vector<float>& ctrl_vals)
{
    this->can_client->make_motor_request(
        robot.getThrustMapper() * MathOperations::ControlOperations::normalizeCtrlVals(ctrl_vals), 
        robot.getMotorCount(), MAX_POWER
    );
}

// Side effect: CAN request equal to function mapped to button
void Controller::processButtonInputs(const std::vector<bool>& button_inputs)
{
    for (int i = LOOP_INIT_COUNTER; i < button_inputs.size(); i++) {
        bool button_currently_pressed = button_inputs[i];
        bool button_recorded_as_pressed = this->buttons[i];

        if (button_currently_pressed && !button_recorded_as_pressed) {
            this->buttons[i] = BUTTON_PRESSED;
            (this->can_client->*(this->button_functions[i]))();
        }
        if (!button_currently_pressed && button_recorded_as_pressed) {
            this->buttons[i] = BUTTON_RELEASED;
        }
    }
}