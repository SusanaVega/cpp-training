#include <iostream>
#include <algorithm>
/*
Write a program that:

Asks the user how many names they wish to enter.
Dynamically allocates a std::string array.
Asks the user to enter each name.
Calls std::sort to sort the names (See 18.1 -- Sorting an array using selection sort and 17.9 -- Pointer arithmetic and subscripting)
Prints the sorted list of names.

*/


int main()
{
    std::cout << "How many names would you like to enter? ";
    std::size_t input{};
    std::cin >> input;
    std::string* array { new std::string [input]{} };

    auto begin {&array[0]};
    auto end {&array[0] + input};
    std::size_t element{};
    for (auto i{begin}; i != end; ++i)
    {
        std::cout << "Enter name #" << element << ": ";
        std::cin >> array[element];
        //std::cout << std::endl;
        element++;
    }

    std::sort(begin,end);

     for (size_t i {0}; i < input; i++)
     {
        std::cout << array[i] << std::endl;
     }
 
    
    delete[] array;
    return 0;
}