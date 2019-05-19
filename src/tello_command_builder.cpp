#include <tello_driver/tello_command_builder.h>
#include <codecvt>
#include <ros/ros.h>

namespace tello_driver
{
    TelloCommandBuilder::TelloCommandBuilder()
    {

    }

    TelloCommandBuilder::~TelloCommandBuilder()
    {

    }

    std::string TelloCommandBuilder::buildInitCommand()
    {
        std::string ret = u8"command";
        return ret;
    }

    std::string TelloCommandBuilder::buildTakeOffCommand()
    {
        std::string ret = u8"takeoff";
        return ret;
    }

    std::string TelloCommandBuilder::buildLandCommand()
    {
        std::string ret = u8"land";
        return ret;
    }

    std::string TelloCommandBuilder::buildMoveCommand(int command_type,int data0,int data1,int data2,int data3)
    {
        using namespace tello_driver::tello_commands;
        if(command_type == move_commands::GO)
        {
            std::string ret = u8"go " + std::to_string(data0) 
                + u8" " + std::to_string(data1) + u8" " + std::to_string(data2)
                + u8" " + std::to_string(data3);
            return ret;
        } 
    }

    std::string TelloCommandBuilder::buildMoveCommand(int command_type,int data)
    {
        using namespace tello_driver::tello_commands;
        if(command_type == move_commands::UP)
        {
            std::string ret = u8"up " + std::to_string(data);
            return ret;
        }
        else if(command_type == move_commands::DOWN)
        {
            std::string ret = u8"down " + std::to_string(data);
            return ret;
        }
        else if(command_type == move_commands::FORWARD)
        {
            std::string ret;
            ret = u8"forward "+ std::to_string(data);
            return ret;
        }
        else if(command_type == move_commands::BACK)
        {
            std::string ret;
            ret = u8"back "+ std::to_string(data);
            return ret;
        }
        else if(command_type == move_commands::LEFT)
        {
            std::string ret;
            ret = u8"left "+ std::to_string(data);
            return ret;
        }
        else if(command_type == move_commands::RIGHT)
        {
            std::string ret;
            ret = u8"left "+ std::to_string(data);
            return ret;
        }
    }
}