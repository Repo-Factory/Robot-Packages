#include "math_operations.hpp"
#include "vector_operations.hpp"
#include <cmath>

std::vector<float> MathOperations::ControlOperations::normalizeCtrlVals(const std::vector<float>& ctrl_vals)
{
    std::vector<float> normalized{0,0,0,0,0,0};
    
    float vectorTotal = abs(ctrl_vals[0]) + abs(ctrl_vals[3]) + abs(ctrl_vals[4]); // yaw, x, y
    float nonVectorTotal = abs(ctrl_vals[1]) + abs(ctrl_vals[2]) + abs(ctrl_vals[5]); // roll, pitch, z

    normalized[0] = ctrl_vals[0];
    normalized[1] = ctrl_vals[1];
    normalized[2] = ctrl_vals[2];
    normalized[3] = ctrl_vals[3];
    normalized[4] = ctrl_vals[4];
    normalized[5] = ctrl_vals[5];

    if (vectorTotal > 1)
    {
        normalized[0] = ctrl_vals[0] / vectorTotal;
        normalized[3] = ctrl_vals[3] / vectorTotal;
        normalized[4] = ctrl_vals[4] / vectorTotal;
    }
    if (nonVectorTotal > 1)
    {
        normalized[1] = ctrl_vals[1] / nonVectorTotal;
        normalized[2] = ctrl_vals[2] / nonVectorTotal;
        normalized[5] = ctrl_vals[5] / nonVectorTotal;
    }

    if (vectorTotal == 0)
    {
        normalized[0] = 0;
        normalized[3] = 0;
        normalized[4] = 0;
    }

    if (nonVectorTotal == 0)
    {
        normalized[1] = 0;
        normalized[2] = 0;
        normalized[5] = 0;
    }

    return normalized;
}

bool MathOperations::ControlOperations::equalToZero(const std::vector<int>& thrustVect)
{
    bool equal = true;
    for (int thrust : thrustVect)
    {
        if (thrust > 1) {equal = false;}
    }
    return equal;
}

int MathOperations::ControlOperations::calculateTotalSlew(std::deque<std::vector<int>>& slew_buffer)
{
    int slew_rate = 0;
    for (size_t i = 0; i < slew_buffer.size() - 1; i++)
    {   
        std::vector<int> difference = VectorOperations::abs(slew_buffer[i]) - VectorOperations::abs(slew_buffer[i+1]);
        slew_rate += abs(VectorOperations::sum(difference));
    }
    return slew_rate;
}

std::vector<float> MathOperations::ControlOperations::convertFromStateToVector(const RTL::RobotState& state)
    {
    return std::vector<float> {
        state.orientation.yaw, state.orientation.pitch, state.orientation.roll, state.position.x_pos,  state.position.y_pos, state.position.z_pos
    };
}

std::vector<float> MathOperations::ControlOperations::getErrors(const std::vector<float>& current_state, const std::vector<float>& desired_state) 
{
    return desired_state - current_state;
}    

std::vector<float> MathOperations::ControlOperations::ctrlValsToThrusts(const RTL::matrix_t& thrust_mapper, const std::vector<float>& ctrl_vals)
{
    return thrust_mapper * ctrl_vals;
}