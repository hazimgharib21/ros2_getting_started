#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "ros2_interfaces/msg/num.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
    rclcpp::Subscription<ros2_interfaces::msg::Num>::SharedPtr subscription_;

    void topic_callback(const ros2_interfaces::msg::Num &msg) const;
public:
    MinimalSubscriber();
};

