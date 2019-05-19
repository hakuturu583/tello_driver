#ifndef TELLO_DRIVER_UDP_SERVER_H_INCLUDED
#define TELLO_DRIVER_UDP_SERVER_H_INCLUDED

// Headers in this package
#include <tello_driver/constants.h>

// Headers in Boost
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/optional.hpp>

// Headers in ROS
#include <ros/ros.h>

// Headers in STL
#include <map>
#include <mutex>
#include <functional>

namespace tello_driver
{
    class UdpServer
    {
    public:
        UdpServer(int port);
        ~UdpServer();
        boost::circular_buffer<std::pair<ros::Time,std::string> > getMessageQueue();
    private:
        boost::asio::io_service io_service_;
        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint remote_endpoint_;
        void receive(const boost::system::error_code&, std::size_t len);
        boost::array<char, 512> recieve_buf_;
        boost::circular_buffer<std::pair<ros::Time,std::string> > message_queue_;
        std::mutex mtx_;
    };
}

#endif  //TELLO_DRIVER_UDP_SERVER_H_INCLUDED