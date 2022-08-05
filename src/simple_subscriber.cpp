#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// create a node class called MinimalSubscriber by inheriting from rclcpp::Node
class MinimalSubscriber : public rclcpp::Node
{
    // declaration of private variables - subscriber
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    // callback function
    // it receives the string message data published over the topic
    // and simply writes it to the console
    void topic_callback(const std_msgs::msg::String & msg) const
    {
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }

    public:
        // Constructor
        // Initialize node name
        MinimalSubscriber()
            : Node("minimal_subscriber")
        {
            // Initialized subscriber to execute the callback
            subscription_ = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
        }
};

int main(int argc, char * argv[])
{
    // initialize ROS2
    rclcpp::init(argc, argv);

    // start processing data from node
    rclcpp::spin(std::make_shared<MinimalSubscriber>());

    rclcpp::shutdown();
    return 0;
}
