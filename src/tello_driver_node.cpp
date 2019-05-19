// Headers in ROS
#include <ros/ros.h>

// Headers in this package
#include <tello_driver/tello_driver.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "tello_driver_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    tello_driver::TelloDriver driver(nh,pnh);
    ros::spin();
    return 0;
}