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
        std::vector<tello_driver::BYTE1> data = {0x00};
        std::vector<tello_driver::BYTE1> ret = build(packet_type::land,command_id::land,0,data);
        ROS_ASSERT(ret.size() == 11);
        return ret;
    }

    std::vector<tello_driver::BYTE1> TelloPacketBuilder::build(BYTE1 packet_type,BYTE2 command_id,unsigned short seq,std::vector<tello_driver::BYTE1> data)
    {
        std::vector<tello_driver::BYTE1> ret;
        BYTE2 byte_packet_length = ((unsigned int)(data.size() + 11))<<3;
        BYTE converter;
        converter.byte2 = byte_packet_length;
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        ret.push_back(getCrc8(ret));
        ret.push_back(packet_type);
        converter.byte2 = command_id;
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        converter.byte2 = seq;
        ret.push_back(converter.first_byte);
        ret.push_back(converter.second_byte);
        for(auto itr = data.begin(); itr != data.end(); itr++)
        {
            ret.push_back(*itr);
        }
        BYTE2 crc16 = getCrc16(ret);
        converter.byte2 = crc16;
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