#include "generic_operations.hpp"

void GenericOperations::Functional::repeatNTimes(int times, const std::function<void()>& performAction)
{
    int i = 0;
    while (i < times)
    {
        performAction();
        i++;
    }
}

float GenericOperations::Functional::reduce(std::deque<float>& streamValues, std::function<float(std::deque<float>&)> reductionFunction)
{
    return reductionFunction(streamValues);
}