#ifndef STRUCT_TYPES_H
#define STRUCT_TYPES_H

#include <deque>
#include <string>

namespace RTL
{
     struct Orientation
    {
        float yaw = 0;
        float pitch = 0;
        float roll = 0;
    };

    struct Position
    {
        float x_pos = 0;
        float y_pos = 0;
        float z_pos = 0;  
    };

    struct RobotState
    {   
        Orientation orientation;
        Position position;
    };

    enum class RawDataType
    {
        yaw =   0, 
        pitch = 1,
        roll =  2,
        x_pos = 3,
        y_pos = 4,
        z_pos = 5,
        x_vel = 6,
        y_vel = 7,
        z_vel = 8
    };

    struct RawSensorStream
    {
        RawDataType type;
        std::deque<float> values;
    };
}

#endif