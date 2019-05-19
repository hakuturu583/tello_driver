// Headers in this package
#include <tello_driver/tello_driver.h>

namespace tello_driver
{
    TelloDriver::TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh)
        : nh_(nh),pnh_(pnh),res_server_(tello_driver::TELLO_PORT_CMD)
    {
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildInitCommand());
    }

    TelloDriver::~TelloDriver()
    {

    }

    bool TelloDriver::TakeOffService(tello_driver::TakeOff::Request &req,tello_driver::TakeOff::Response &res)
    {
        ros::Time now = ros::Time::now();
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildTakeOffCommand());
    }
}