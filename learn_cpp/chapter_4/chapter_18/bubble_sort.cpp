#include <iostream>
/*
A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. At this point, the last element in the array will be sorted.
C) Repeat the first two steps again until the array is sorted.

*/


int main()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    int lenght {static_cast<int>(std::size(array))};
    //  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable

    for(int i {0}; i < lenght-1; ++i)
    {
        //int first{0};
        for (int j {0}; j < lenght-1; ++j)
        {
           // int second{j};
            if (array[j] > array[j+1])
            {
                std::swap(array[j],array[j+1]);
            }         
        }
    }

    for(auto &&i: array)
    {
        std::cout << i << " ";
    }
 

    return 0;
}