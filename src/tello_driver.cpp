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
        param_func_ = boost::bind(&TelloDriver::configCallback, this, _1, _2);
        param_server_.setCallback(param_func_);
    }

    TelloDriver::~TelloDriver()
    {

    }

    void TelloDriver::takeOffCallback(const std_msgs::Empty::ConstPtr msg)
    {
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildTakeOffCommand());
        return;
    }

    void TelloDriver::configCallback(tello_driver::TelloConfig &config, uint32_t level)
    {
        target_speed_ = config.speed;
        return;
    }
}