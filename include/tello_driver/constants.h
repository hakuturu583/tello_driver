#ifndef TELLO_DRIVER_CONSTANTS_H_INCLUDED
#define TELLO_DRIVER_CONSTANTS_H_INCLUDED

#include <string>

namespace tello_driver
{
    const std::string TELLO_IP = "192.168.10.1";
    constexpr int TELLO_PORT_CMD = 8889;
    constexpr int TELLO_PORT_STATE = 8890;
    constexpr int TELLO_PORT_VIDEO = 6038;

    namespace tello_commands
    {
        enum mission_commands
        {
            /**
             * @brief Enter the command mode
             * 
             */
            COMMAND = 0,
            /**
             * @brief Take off Tello
             * 
             */
            TAKEOFF = 1,
            /**
             * @brief Land Tello
             * 
             */
            LAND = 2,
            /**
             * @brief Enable video stream
             * 
             */
            STREAM_ON = 3,
            /**
             * @brief Disable video stream
             * 
             */
            STREAM_OFF = 4,
            /**
             * @brief Stop motors immediately.
             * 
             */
            EMERGENCY = 5,
        };

        enum move_commands
        {
            UP = 0,
            /**
             * @brief move down
             * 
             */
            DOWN = 1,
            /**
             * @brief move left
             * 
             */
            LEFT = 2,
            /**
             * @brief move right
             * 
             */
            RIGHT = 3,
            /**
             * @brief move forward
             * 
             */
            FORWARD = 4,
            /**
             * @brief move back
             * 
             */
            BACK = 5,
            /**
             * @brief move clockwise
             * 
             */
            CLOCKWISE = 6,
            /**
             * @brief move counter clockwise
             * 
             */
            COUNTER_CLOCKWISE = 7,
            /**
             * @brief flip
             * 
             */
            FLIP = 8,
            /**
             * @brief Go to the target position
             * 
             */
            GO = 9,
            /**
             * @brief Move in curve
             * 
             */
            CURVE = 10,
            /**
             * @brief send remote controller command
             * 
             */
            REMOTE_CONTROL = 11,
        };

        enum system_commands
        {
            /**
             * @brief set speed of the tello
             * 
             */
            SPEED = 0,
            /**
             * @brief set wifi ssid and pass
             * 
             */
            WIFI = 1,
            /**
             * @brief set the tello to the station mode and connect to the target access point
             * 
             */
            ACCESS_POINT = 2,
        };
    }

    namespace tello_status
    {
        enum status
        {
            /**
             * @brief Current speed of the tello
             * 
             */
            SPEED = 0,
            /**
             * @brief Current battery ratio of the tello
             * 
             */
            BATTERY = 1,
            /**
             * @brief Current Flight Time
             * 
             */
            TIME = 2,
            /**
             * @brief Wifi Signal Noise Ratio
             * 
             */
            WIFI_SNR = 3,
        };
    }

    /**
     * @brief typedef for the 1 Byte
     * 
     */
    typedef unsigned char BYTE1;
    /**
     * @brief typedef for the 2 Bytes
     * 
     */
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