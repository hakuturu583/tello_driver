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
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES tello_driver
  CATKIN_DEPENDS cv_bridge geometry_msgs image_transport joy roscpp sensor_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(udp_client src/udp_client.cpp)
target_link_libraries(udp_client ${catkin_LIBRARIES})

add_library(tello_packet_builder src/tello_packet_builder.cpp)
target_link_libraries(tello_packet_builder ${catkin_LIBRARIES})

add_executable(tello_launch exe/tello_launch.cpp)
target_link_libraries(tello_launch udp_client tello_packet_builder ${catkin_LIBRARIES})