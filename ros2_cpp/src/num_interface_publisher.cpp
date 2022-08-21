#include "ros2_cpp/num_interface_publisher.h"

MinimalPublisher::MinimalPublisher() :
    Node("minimal_publisher"),
    count_(0)
{
    publisher_ = this->create_publisher<ros2_interfaces::msg::Num>("topic", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MinimalPublisher::timer_callback, this));
}

void MinimalPublisher::timer_callback()
{
    auto message = ros2_interfaces::msg::Num();
    message.num = this->count_++;
    RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: '" << message.num << "'");
    publisher_->publish(message);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}