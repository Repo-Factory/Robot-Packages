
#include "math_operations.hpp"
#include <cmath>

bool MathOperations::FloatOperations::areEqual(float float1, float float2, float epsilon)
{
    return (fabs(float1 - float2) < epsilon);
}

bool MathOperations::FloatOperations::areEqual(const std::vector<float>& current_state, const std::vector<float>& desired_state)
{
    #define ORIENTATION_TOLERANCE 4.0f
    #define POSITION_TOLERANCE 0.06f

    bool equal = true;
    for (std::vector<float>::size_type i = 0; i < 3; i++)
    {
        if (!MathOperations::FloatOperations::areEqual(current_state[i], desired_state[i], ORIENTATION_TOLERANCE)) //.05*current_state[i])
        {
            equal = false;
        }
    }
    for (std::vector<float>::size_type j = 3; j < 6; j++)
    {
        if (!MathOperations::FloatOperations::areEqual(current_state[j], desired_state[j], POSITION_TOLERANCE)) //.05*current_state[i])
        {
            equal = false;
        }
    }
    return equal;
}

float MathOperations::FloatOperations::medianOfLatestThreeElements(std::deque<float>& streamValues)
{
    if (streamValues.size() == 1)   return streamValues[0];
    if (streamValues.size() == 2)   return (streamValues[0] + streamValues[1]) / 2;
    
    float firstElement = streamValues[0];
    float secondElement = streamValues[1];
    float thirdElement = streamValues[2];

    if (firstElement > secondElement)   std::swap(firstElement, secondElement);
    if (firstElement > thirdElement)    std::swap(firstElement, thirdElement);
    if (secondElement > thirdElement)   std::swap(secondElement, thirdElement);
    return secondElement;
}