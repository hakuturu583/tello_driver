#ifndef TELLO_DRIVER_CONSTANTS_H_INCLUDED
#define TELLO_DRIVER_CONSTANTS_H_INCLUDED

#include <string>

namespace tello_driver
{
    const std::string TELLO_IP = "192.168.10.1";
    constexpr int TELLO_PORT_CMD = 8889;
    constexpr int TELLO_PORT_VIDEO = 6038;
    typedef unsigned char BYTE1;
    typedef unsigned short BYTE2;

    union BYTE
    {
        BYTE2 byte2;
        struct
        {
            BYTE1 first_byte;
            BYTE1 second_byte;
        };
    };

    namespace byte_format
    {
        constexpr BYTE1 FIRST_BYTE = 0xcc;
        namespace packet_type
        {
            constexpr BYTE1 takeoff = 0x68;
            constexpr BYTE1 land = 0x68;
            constexpr BYTE1 stick = 0x60;
        }

        namespace command_id
        {
            constexpr BYTE1 takeoff = 0x54;
            constexpr BYTE1 land = 0x55;
            constexpr BYTE1 stick = 0x50;
        }
    }
}

#endif  //TELLO_DRIVER_CONSTANTS_H_INCLUDED