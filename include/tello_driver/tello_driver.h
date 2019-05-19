#ifndef TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED
#define TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED

// Headers in ROS
#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/PointStamped.h>
#include <dynamic_reconfigure/server.h>

// Heades in this package
#include <tello_driver/tello_command_builder.h>
#include <tello_driver/udp_client.h>
#include <tello_driver/udp_server.h>
#include <tello_driver/TelloConfig.h>

namespace tello_driver
{
    class TelloDriver
    {
    public:
        TelloDriver(ros::NodeHandle nh,ros::NodeHandle pnh);
        ~TelloDriver();
    private:
        ros::NodeHandle nh_;
        ros::NodeHandle pnh_;
        TelloCommandBuilder builder_;
        UdpClient cmd_client_;
        UdpServer res_server_;
        ros::Subscriber takeoff_sub_;
        void takeOffCallback(const std_msgs::Empty::ConstPtr msg);
        ros::Subscriber move_sub_;
        void moveCallback(const geometry_msgs::PointStamped::ConstPtr msg);
        dynamic_reconfigure::Server<tello_driver::TelloConfig> param_server_;
        dynamic_reconfigure::Server<tello_driver::TelloConfig>::CallbackType param_func_;
        void configCallback(tello_driver::TelloConfig &config, uint32_t level);
        /**
         * @brief Target Speed of the tello (m/s)
         * 
         */
        double target_speed_;
    };
}

#endif  //TELLO_DRIVER_TELLO_DRIVER_H_INCLUDED