#include "component.hpp"
#include <cstring>

namespace
{
    void initMessage(rclcpp::Node* node, const std::string& name)
    {
        RCLCPP_INFO(node->get_logger(), "################################################");
        RCLCPP_INFO(node->get_logger(), "%s Node Initialized", name.c_str());
        RCLCPP_INFO(node->get_logger(), "################################################\n");
    }
}

Component::Component(std::string name) : Node(name) 
{
    // state = std::make_unique<InactiveState>();
    initMessage(this, name);
}

// void Component::spin()
// {
//     rclcpp::spin_some(shared_from_this());
// }

// void Component::update(Component& component)
// {
//     state->update(component);
// }

// void Component::idle()
// {
//     return;
// }

// void ActiveState::update(Component& component) 
// {
//     component.spin();
// }

// void InactiveState::update(Component& component) 
// {
//     component.idle();
// }
