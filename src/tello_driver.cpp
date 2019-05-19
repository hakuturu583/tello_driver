// Headers in this package
#include <tello_driver/tello_driver.h>

namespace tello_driver
{
    TelloDriver::TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh)
        : nh_(nh),pnh_(pnh)
    {
        client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildInitCommand());
    }

    TelloDriver::~TelloDriver()
    {

    }

    bool TelloDriver::TakeOffService(tello_driver::TakeOff::Request &req,tello_driver::TakeOff::Response &res)
    {
        
    }
}