#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

// creates a node class called MinimalPublisher by inheriting from rclcpp::Node
class MinimalPublisher : public rclcpp::Node
{
    // declaration of private variables - timer, publisher and counter.
    size_t count_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    // timer_callback function
    // this is where the message data is set and the messages are actually published
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }

    public:
        // Constructor
        // Initialize node name and count_ to 0
        MinimalPublisher()
            : Node("minimal_publisher"), count_(0)
        {
            // Initialized publisher with String type, topic name and required queue size to limit messages in the event of backup
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

            // Initialize timer which cause timer_callback function to be executed twice a second
            timer_ = this->create_wall_timer(
                    500ms, std::bind(&MinimalPublisher::timer_callback, this));
        }
};

int main(int argc, char * argv[])
{
    // initialize ROS2
    rclcpp::init(argc, argv);

    // start processing data from node
    rclcpp::spin(std::make_shared<MinimalPublisher>());

    rclcpp::shutdown();
    return 0;
}
