#include <tello_driver/udp_server.h>

namespace tello_driver
{
    UdpServer::UdpServer(int port)
        :socket_(io_service_, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
    {
        message_queue_ = boost::circular_buffer<std::pair<ros::Time,std::string> >(tello_driver::MESSAGE_QUEUE_LENGTH);
        socket_.async_receive_from(
            boost::asio::buffer(recieve_buf_), remote_endpoint_,
            boost::bind(&UdpServer::receive, this,
            boost::asio::placeholders::error, _2));
    }

    UdpServer::~UdpServer()
    {

    }

    boost::circular_buffer<std::pair<ros::Time,std::string> > UdpServer::getMessageQueue()
    {
        std::lock_guard<std::mutex> lock(mtx_);
        return message_queue_;
    }

    void UdpServer::receive(const boost::system::error_code& error, size_t len)
    {
        std::lock_guard<std::mutex> lock(mtx_);
        if (!error || error == boost::asio::error::message_size)
        {
            std::string message(recieve_buf_.data(), len);
            message_queue_.push_back(std::make_pair(ros::Time::now(),message));
        }
        return;
    }
}