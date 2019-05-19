cmake_minimum_required(VERSION 2.8.3)
project(tello_driver)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  geometry_msgs
  image_transport
  joy
  roscpp
  sensor_msgs
  std_msgs
  message_generation
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES tello_driver
  CATKIN_DEPENDS cv_bridge geometry_msgs image_transport joy roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

set(tello_driver_core_src src/tello_command_builder.cpp src/udp_client.cpp src/udp_server.cpp)

add_executable(tello_takeoff app/tello_takeoff.cpp ${tello_driver_core_src})
target_link_libraries(tello_takeoff  ${catkin_LIBRARIES})

add_executable(tello_move_forward app/tello_move_forward.cpp ${tello_driver_core_src})
target_link_libraries(tello_move_forward  ${catkin_LIBRARIES})

add_executable(tello_driver_node src/tello_driver_node.cpp src/tello_driver.cpp ${tello_driver_core_src})
target_link_libraries(tello_driver_node ${catkin_LIBRARIES})
add_dependencies(tello_driver_node tello_driver_generate_messages_cpp)