#include <tello_driver/tello_command_builder.h>

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
}