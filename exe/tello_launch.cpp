#include <tello_driver/udp_client.h>
#include <tello_driver/tello_packet_builder.h>

int main()
{
    tello_driver::UdpClient client;
    tello_driver::TelloPacketBuilder builder;
    client.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder.buildLandOffCmd());
    return 0;
}