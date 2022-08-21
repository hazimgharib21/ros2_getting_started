#include "ros2_interfaces/subscribe_address_book.h"

AddressBookSubscriber::AddressBookSubscriber() : Node("minimal_subscriber")
{
    subscription_ = this->create_subscription<ros2_interfaces::msg::AddressBook>(
        "address_book",
        10,
        std::bind(&AddressBookSubscriber::topic_callback, this, _1)
    );
}

void AddressBookSubscriber::topic_callback(const ros2_interfaces::msg::AddressBook & msg) const
{
    std::string gender;
    if(msg.gender == ros2_interfaces::msg::AddressBook::MALE)
        gender = "Male";
    if(msg.gender == ros2_interfaces::msg::AddressBook::FEMALE)
        gender = "Female";

    RCLCPP_INFO(
        this->get_logger(),
        "First Name : '%s' Last Name : '%s' Gender : '%s' Age : '%d' Address : '%s'",
        msg.first_name.c_str(), msg.last_name.c_str(), gender.c_str(), msg.age, msg.address.c_str()
    );
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AddressBookSubscriber>());
    rclcpp::shutdown();
    return 0;
}