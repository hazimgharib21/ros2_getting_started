#include "ros2_cpp/num_interface_subscriber.h"

MinimalSubscriber::MinimalSubscriber() :
    Node("minimal_subscriber")
{
    subscription_ = this->create_subscription<ros2_interfaces::msg::Num>(
    "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
}

void MinimalSubscriber::topic_callback(const ros2_interfaces::msg::Num &msg) const
{
    RCLCPP_INFO_STREAM(this->get_logger(), "I heard: '" << msg.num << "'");
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}