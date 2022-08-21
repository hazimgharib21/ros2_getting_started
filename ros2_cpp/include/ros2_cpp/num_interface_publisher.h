#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "ros2_interfaces/msg/num.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<ros2_interfaces::msg::Num>::SharedPtr publisher_;
    size_t count_;

    void timer_callback();

public:
    MinimalPublisher();
};

