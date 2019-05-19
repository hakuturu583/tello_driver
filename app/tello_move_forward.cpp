#include <tello_driver/udp_client.h>
#include <tello_driver/tello_command_builder.h>

int main()
{
    tello_driver::UdpClient client;
    tello_driver::TelloCommandBuilder builder;
    //client.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder.buildInitCommand());
    //client.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder.buildTakeOffCommand());
    using namespace tello_driver::tello_commands;
    client.send(tello_driver::TELLO_IP,tello_driver::TELLO_PORT_CMD,builder.buildMoveCommand(move_commands::UP,100));
    return 0;
}