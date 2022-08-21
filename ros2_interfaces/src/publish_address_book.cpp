#include "ros2_interfaces/publish_address_book.h"

AddressBookPublisher::AddressBookPublisher() :
    Node("address_book_publisher")
{
    address_book_publisher_ =
        this->create_publisher<ros2_interfaces::msg::AddressBook>("address_book", 10);

    auto publish_msg = [this]() -> void
    {
        auto message = ros2_interfaces::msg::AddressBook();

        message.first_name = "John";
        message.last_name = "Doe";
        message.age = 30;
        message.gender = message.MALE;
        message.address = "unknown";

        std::cout << "Publishing Contact\nFirst:" << message.first_name << "  Last:" << message.last_name << std::endl;

        this->address_book_publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(1s, publish_msg);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AddressBookPublisher>());
    rclcpp::shutdown();

    return 0;
}