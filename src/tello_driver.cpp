// Headers in this package
#include <tello_driver/tello_driver.h>

namespace tello_driver
{
    TelloDriver::TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh)
        : res_server_(tello_driver::TELLO_PORT_CMD),tf_listener_(tf_buffer_)
    {
        nh_ = nh;
        pnh_ = pnh;
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder_.buildInitCommand());
        takeoff_sub_ = pnh_.subscribe("takeoff",1,&TelloDriver::takeOffCallback,this);
        target_position_sub_ = pnh_.subscribe("target_position",1,&TelloDriver::targetPositionCallback,this);
        param_func_ = boost::bind(&TelloDriver::configCallback, this, _1, _2);
        param_server_.setCallback(param_func_);
    }

    TelloDriver::~TelloDriver()
    {

    }

    void TelloDriver::targetPositionCallback(const geometry_msgs::PointStamped::ConstPtr msg)
    {
        geometry_msgs::PointStamped target_position = *msg;
        if(target_position.header.frame_id != "base_link")
        {
            geometry_msgs::TransformStamped transform_stamped;
            try
            {
                transform_stamped = tf_buffer_.lookupTransform("base_link", target_position.header.frame_id ,ros::Time(0));
            }
            catch (tf2::TransformException &ex)
            {
                ROS_WARN("%s",ex.what());
                return;
            }
            tf2::doTransform(target_position,target_position,transform_stamped);
        }
        int x = (int)(target_position.point.x * 100.0);
        int y = (int)(target_position.point.y * 100.0);
        int z = (int)(target_position.point.z * 100.0);
        int speed = (int)(target_speed_*100);
        cmd_client_.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,
            builder_.buildMoveCommand(tello_driver::tello_commands::move_commands::GO,x,y,z,speed));
        return;
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