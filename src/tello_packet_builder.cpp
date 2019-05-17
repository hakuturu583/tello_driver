// Headers in this package
#include <tello_driver/tello_packet_builder.h>
#include <tello_driver/tables.h>

// Headers in ROS
#include <ros/ros.h>

namespace tello_driver
{
    TelloPacketBuilder::TelloPacketBuilder()
    {

    }

    TelloPacketBuilder::~TelloPacketBuilder()
    {

    }

    std::vector<tello_driver::BYTE1> TelloPacketBuilder::buildLandOffCmd()
    {
        using namespace tello_driver::byte_format;
        // Landing data Byte is empty
        std::vector<tello_driver::BYTE1> data;
        std::vector<tello_driver::BYTE1> ret = build(packet_type::land,command_id::land,0,data);
        ROS_ASSERT(ret.size() == 11);
        ROS_ERROR_STREAM(ret);
        return ret;
    }

    std::vector<tello_driver::BYTE1> TelloPacketBuilder::build(BYTE1 packet_type,BYTE2 command_id,unsigned short seq,std::vector<tello_driver::BYTE1> data)
    {
        std::vector<tello_driver::BYTE1> ret;
        // 0 Byte
        ret.push_back(tello_driver::byte_format::FIRST_BYTE);
        BYTE2 byte_packet_length = ((unsigned int)(data.size() + 11))<<3;
        BYTE converter;
        converter.byte2 = byte_packet_length;
        // 1~2 Byte
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        // 3 Byte
        ret.push_back(getCrc8(ret));
        // 4 Byte
        ret.push_back(packet_type);
        converter.byte2 = command_id;
        // 5~6 Byte
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        converter.byte2 = seq;
        // 7~8 Byte
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        // Data Bytes
        for(auto itr = data.begin(); itr != data.end(); itr++)
        {
            ret.push_back(*itr);
        }
        BYTE2 crc16 = getCrc16(ret);
        converter.byte2 = crc16;
        // N-1~N Bytes
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        return ret;
    }

    tello_driver::BYTE1 TelloPacketBuilder::getCrc8(std::vector<tello_driver::BYTE1> data)
    {
        tello_driver::BYTE1 seed = 0x77;
        for(auto itr = data.begin(); itr != data.end(); itr++)
        {
            seed = tello_driver::tables::crc8_table[(seed ^ *itr) & 0xff];
        }
        return seed;
    }

    tello_driver::BYTE2 TelloPacketBuilder::getCrc16(std::vector<tello_driver::BYTE1> data)
    {
        tello_driver::BYTE2 seed = 0x3692;
        for(auto itr = data.begin(); itr != data.end(); itr++)
        {
            seed = tello_driver::tables::crc16_table[(seed ^ *itr) & 0xff] ^ (seed >> 8);
        }
        return seed;
    }
}