cmake_minimum_required(VERSION 3.8)
project(ros2_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros2_interfaces REQUIRED)

INCLUDE_DIRECTORIES(
  include
)

# build talker
add_executable(talker src/minimal_publisher.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

# build listener
add_executable(listener src/minimal_subscriber.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(server src/add_two_ints_server.cpp)
ament_target_dependencies(server rclcpp ros2_interfaces)

add_executable(client src/add_two_ints_client.cpp)
ament_target_dependencies(client rclcpp ros2_interfaces)

add_executable(num_talker src/num_interface_publisher.cpp)
ament_target_dependencies(num_talker rclcpp ros2_interfaces)

add_executable(num_listener src/num_interface_subscriber.cpp)
ament_target_dependencies(num_listener rclcpp ros2_interfaces)

add_executable(parameter_node src/parameter_node.cpp)
ament_target_dependencies(parameter_node rclcpp)


install(TARGETS
  talker
  listener
  server
  client
  num_talker
  num_listener
  parameter_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
