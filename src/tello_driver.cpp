// Headers in this package
#include <tello_driver/tello_driver.h>

namespace tello_driver
{
    TelloDriver::TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh)
        : res_server_(tello_driver::TELLO_PORT_CMD)
    {
        nh_ = nh;
        pnh_ = pnh;
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildInitCommand());
        takeoff_sub_ = pnh_.subscribe("takeoff",1,&TelloDriver::takeOffCallback,this);
    }

    TelloDriver::~TelloDriver()
    {

    }

    void TelloDriver::takeOffCallback(const std_msgs::Empty::ConstPtr msg)
    {
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildTakeOffCommand());
        return;
    }
}