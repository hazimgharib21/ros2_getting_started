#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "ros2_interfaces/msg/address_book.hpp"

using std::placeholders::_1;

class AddressBookSubscriber : public rclcpp::Node
{
    rclcpp::Subscription<ros2_interfaces::msg::AddressBook>::SharedPtr subscription_;
    void topic_callback(const ros2_interfaces::msg::AddressBook & msg) const;
public:
    AddressBookSubscriber();
};