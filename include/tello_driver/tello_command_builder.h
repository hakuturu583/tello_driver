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
        std::string buildLandCommand();
        std::string buildMoveCommand(int command_type,int data);
        std::string buildMoveCommand(int command_type,int data0,int data1,int data2,int data3);
    private:
    };
}

#endif  //TELLO_DRIVER_TELLO_COMMAND_BUILDER_H_INCLUDED