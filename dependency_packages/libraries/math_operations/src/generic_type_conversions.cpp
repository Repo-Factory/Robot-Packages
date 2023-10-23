#include "generic_operations.hpp"

std::string GenericOperations::TypeConversions::convertDataTypeToString(int32_t data_type)
{
    if (data_type == static_cast<int>(RTL::RawDataType::yaw))   {return "yaw";} 
    if (data_type == static_cast<int>(RTL::RawDataType::pitch)) {return "pitch";}
    if (data_type == static_cast<int>(RTL::RawDataType::roll))  {return "roll";}
    if (data_type == static_cast<int>(RTL::RawDataType::x_pos)) {return "x_pos";}
    if (data_type == static_cast<int>(RTL::RawDataType::y_pos)) {return "y_pos";}
    if (data_type == static_cast<int>(RTL::RawDataType::z_pos)) {return "z_pos";}
    if (data_type == static_cast<int>(RTL::RawDataType::x_vel)) {return "x_vel";}
    if (data_type == static_cast<int>(RTL::RawDataType::y_vel)) {return "y_vel";}
    if (data_type == static_cast<int>(RTL::RawDataType::z_vel)) {return "z_vel";}
    return "Unsupported Data Type";
}