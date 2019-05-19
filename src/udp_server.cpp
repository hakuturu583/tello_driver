#include <tello_driver/udp_server.h>

namespace tello_driver
{
    UdpServer::UdpServer(int port)
        :socket_(io_service_, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
    {
        socket_.async_receive_from(
            boost::asio::buffer(recieve_buf_), remote_endpoint_,
            boost::bind(&UdpServer::receive, this,
            boost::asio::placeholders::error, _2));
    }

    UdpServer::~UdpServer()
    {

    }

    void UdpServer::receive(const boost::system::error_code& error, size_t len)
    {
        if (!error || error == boost::asio::error::message_size)
        {

        }
        return;
    }
}