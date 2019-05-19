#ifndef TELLO_DRIVER_TELLO_COMMAND_BUILDER_H_INCLUDED
#define TELLO_DRIVER_TELLO_COMMAND_BUILDER_H_INCLUDED

// Headers in this package
#include <tello_driver/constants.h>

// Headers in STL
#include <string>

namespace tello_driver
{
    class TelloCommandBuilder
    {
    public:
        TelloCommandBuilder();
        ~TelloCommandBuilder();
        std::string buildInitCommand();
        std::string buildTakeOffCommand();
    };
}

#endif  //TELLO_DRIVER_TELLO_COMMAND_BUILDER_H_INCLUDED