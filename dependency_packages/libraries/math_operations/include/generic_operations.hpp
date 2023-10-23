#ifndef GENERIC_OPERATIONS_H
#define GENERIC_OPERATIONS_H

#include <robot_libraries/robot_types.hpp>

namespace GenericOperations
{
    namespace Functional
    {
        void repeatNTimes(int times, const std::function<void()>& performAction);
        float reduce(std::deque<float>& streamValues, std::function<float(std::deque<float>&)> reductionFunction);
    }

    namespace TypeConversions
    {
        std::string convertDataTypeToString(int32_t data_type);
    }
}

#endif