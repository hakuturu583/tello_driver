#ifndef TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED
#define TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED

// Headers in ROS
#include <ros/ros.h>

// Heades in this package
#include <tello_driver/TakeOff.h>
#include <tello_driver/tello_command_builder.h>
#include <tello_driver/udp_client.h>

namespace tello_driver
{
    class TelloDriver
    {
    public:
        TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~TelloDriver();
    private:
        bool TakeOffService(tello_driver::TakeOff::Request &req,tello_driver::TakeOff::Response &res);
        const ros::NodeHandle nh_;
        const ros::NodeHandle pnh_;
        TelloCommandBuilder builder_;
        UdpClient client_;
    };
}

#endif  //TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED