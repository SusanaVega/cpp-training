#include <iostream>
#include <vector>

// Write a function template to find the largest value in a std::vector.
// If the vector is empty, return the default value for the element type.

template <typename T>
T findMax(const std::vector<T>& myVector)
{
    std::size_t lenght{myVector.size()}; 
    if (lenght == 0)
    {
        return T{};
    }
    T max{myVector[0]};
    for (size_t i = 0; i < lenght; i++)
    {
        if(max < myVector[i])
        {
            max = myVector[i];
        }
        // else
        // {
        //     max = myVector[i+1];
        // }
    }
    
    return max;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';
    return 0;
}