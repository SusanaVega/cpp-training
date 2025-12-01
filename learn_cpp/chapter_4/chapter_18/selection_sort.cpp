#include <iostream>

/*
1. Starting at array index 0, search the entire array to find the smallest value
2. Swap the smallest value found in the array with the value at index 0
3. Repeat steps 1 & 2 starting from the next index
*/



int main()
{
    int array[5] {30, 50, 20, 10, 40};
    constexpr int lenght {static_cast<int>(std::size(array))};
    
    for (int i{0}; i < lenght; i++)
    {
        int index {i};
        for (int j{i+1}; j < lenght; j++)
        {
            if (array[index] < array[j])
            {
                index = j;
            }
        }
        std::swap(array[i],array[index]);
    }

    for (auto &&i : array)
    {
        std::cout << i << " ";
    }
    
    
    return 0;
}