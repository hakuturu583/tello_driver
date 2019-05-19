#ifndef TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED
#define TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED

// Headers in ROS
#include <ros/ros.h>

namespace tello_driver
{
    class TelloDriver
    {
    public:
        TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~TelloDriver();
    private:
        const ros::NodeHandle nh_;
        const ros::NodeHandle pnh_;
    };
}

#endif  //TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED