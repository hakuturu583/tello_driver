// Headers in this package
#include <tello_driver/constants.h>
#include <tello_driver/udp_client.h>

namespace tello_driver
{
    UdpClient::UdpClient():resolver_(io_service_)
    {

    }

    UdpClient::~UdpClient()
    {

    }

    void UdpClient::send(std::string address,int port,std::string data)
    {
        try
        {
            using boost::asio::ip::udp;
            udp::resolver::query query(udp::v4(), address, std::to_string(port));
            udp::endpoint receiver_endpoint = *resolver_.resolve(query);
            udp::socket socket(io_service_);
            socket.open(udp::v4());
            socket.send_to(boost::asio::buffer(data), receiver_endpoint);
        }
        catch(const std::exception& e)
        {
            ROS_ERROR_STREAM(e.what());
        }
    }
}