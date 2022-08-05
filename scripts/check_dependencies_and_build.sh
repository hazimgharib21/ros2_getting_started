cd /home/df/ws/
rosdep install -i --from-path src --rosdistro humble -y
colcon build --packages-select ros2_getting_started
