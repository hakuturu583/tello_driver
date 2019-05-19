#ifndef TELLO_DRIVER_UDP_SERVER_H_INCLUDED
#define TELLO_DRIVER_UDP_SERVER_H_INCLUDED

// Headers in this package
#include <tello_driver/constants.h>

// Headers in Boost
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace tello_driver
{
    class UdpServer
    {
    public:
        UdpServer(int port);
        ~UdpServer();
    private:
        boost::asio::io_service io_service_;
        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint remote_endpoint_;
        void receive(const boost::system::error_code&, std::size_t len);
        boost::array<char, 512> recieve_buf_;
    };
}

#endif  //TELLO_DRIVER_UDP_SERVER_H_INCLUDED