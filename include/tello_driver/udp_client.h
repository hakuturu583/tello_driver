#ifndef TELLO_DRIVER_UDP_CLIENT_H_INCLUDED
#define TELLO_DRIVER_UDP_CLIENT_H_INCLUDED

// Headers in this package
#include <tello_driver/constants.h>

// Headers in Boost
#include <boost/asio.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>

// Headers in ROS
#include <ros/ros.h>

namespace tello_driver
{
    class UdpClient
    {
    public:
        UdpClient();
        ~UdpClient();
        void send(std::string address,int port,std::vector<tello_driver::BYTE1> data);
    private:
        boost::asio::io_service io_service_;
        boost::asio::ip::udp::resolver resolver_;
    };
}

#endif  //TELLO_DRIVER_UDP_CLIENT_H_INCLUDED