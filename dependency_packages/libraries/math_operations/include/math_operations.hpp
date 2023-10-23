#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include <vector>
#include <memory>
#include <deque>
#include <robot_libraries/robot_types.hpp>

namespace MathOperations
{
    namespace FloatOperations
    {
        bool areEqual(float float1, float float2, float epsilon);
        bool areEqual(const std::vector<float>& current_state, const std::vector<float>& desired_state);
        float medianOfLatestThreeElements(std::deque<float>& streamValues);
    }

    namespace ControlOperations
    {
        std::vector<float> normalizeCtrlVals(const std::vector<float>& ctrl_vals);
        bool equalToZero(const std::vector<int>& thrustVect);
        int calculateTotalSlew(std::deque<std::vector<int>>& slew_buffer);
        std::vector<float> convertFromStateToVector(const RTL::RobotState& state);
        std::vector<float> getErrors(const std::vector<float>& current_state, const std::vector<float>& desired_state);
        std::vector<float> ctrlValsToThrusts(const RTL::matrix_t& thrust_mapper, const std::vector<float>& ctrl_vals);
    }
}

#endif