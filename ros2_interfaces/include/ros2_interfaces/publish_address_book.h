#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "ros2_interfaces/msg/address_book.hpp"

using namespace std::chrono_literals;

class AddressBookPublisher : public rclcpp::Node
{
    rclcpp::Publisher<ros2_interfaces::msg::AddressBook>::SharedPtr address_book_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
public:
    AddressBookPublisher();
};

