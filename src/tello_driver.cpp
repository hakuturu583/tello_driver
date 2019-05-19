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
        ros::Time request_time = ros::Time::now();
        ros::Duration duration = ros::Duration(0.1);
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildTakeOffCommand());
        while(true)
        {
            boost::circular_buffer<std::pair<ros::Time,std::string> > queue = res_server_.getMessageQueue();
            if(queue.size() != 0 && queue[-1].first > request_time)
            {
                if(queue[-1].second == u8"ok")
                {
                    res.result = res.OK;
                    return true;
                }
                if(queue[-1].second == u8"error")
                {
                    res.result = res.ERROR;
                    return false;
                }
            }
            if(ros::Time::now()-request_time>ros::Duration(tello_driver::TIMEOUT))
            {
                res.result = res.TIMEOUT;
                return false;
            }
            duration.sleep();
        }
    }
}