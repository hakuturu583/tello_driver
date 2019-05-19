// Headers in this package
#include <tello_driver/tello_driver.h>

namespace tello_driver
{
    TelloDriver::TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh)
        : nh_(nh),pnh_(pnh)
    {

    }

    TelloDriver::~TelloDriver()
    {

    }
}