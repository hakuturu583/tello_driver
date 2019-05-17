#ifndef TELLO_DRIVER_TELLO_PACKET_BUILDER_H_INCLUDED
#define TELLO_DRIVER_TELLO_PACKET_BUILDER_H_INCLUDED

// Headers in this package
#include <tello_driver/constants.h>

// Headers in STL
#include <vector>

namespace tello_driver
{
    class TelloPacketBuilder
    {
    public:
        TelloPacketBuilder();
        ~TelloPacketBuilder();
        std::vector<tello_driver::BYTE1> buildLandOffCmd();
    private:
        std::vector<tello_driver::BYTE1> build(BYTE1 packet_type,BYTE2 command_id,unsigned short seq,std::vector<tello_driver::BYTE1> data);
        tello_driver::BYTE1 getCrc8(std::vector<tello_driver::BYTE1> data);
        tello_driver::BYTE2 getCrc16(std::vector<tello_driver::BYTE1> data);
    };
}

#endif  //TELLO_DRIVER_TELLO_PACKET_BUILDER_H_INCLUDED