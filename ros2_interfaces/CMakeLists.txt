cmake_minimum_required(VERSION 3.8)
project(ros2_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

INCLUDE_DIRECTORIES(
  include
)

set(msg_files
  "msg/Num.msg"
  "msg/Sphere.msg"
  "msg/AddressBook.msg"
)

set(srv_files
  "srv/AddTwoInts.srv"
  "srv/AddThreeInts.srv"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  DEPENDENCIES geometry_msgs
)

add_executable(publish_address_book
  src/publish_address_book.cpp
)
ament_target_dependencies(publish_address_book "rclcpp")

add_executable(subscribe_address_book
  src/subscribe_address_book.cpp
)
ament_target_dependencies(subscribe_address_book "rclcpp")


install(TARGETS
  publish_address_book
  subscribe_address_book
  DESTINATION lib/${PROJECT_NAME}
)

rosidl_get_typesupport_target(
  cpp_typesupport_target
  ${PROJECT_NAME}
  "rosidl_typesupport_cpp"
)

target_link_libraries(publish_address_book "${cpp_typesupport_target}")
target_link_libraries(subscribe_address_book "${cpp_typesupport_target}")

ament_export_dependencies(rosidl_default_runtime)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
