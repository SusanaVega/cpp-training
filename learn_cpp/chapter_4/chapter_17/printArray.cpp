#include <array>
#include <iostream>


template<typename T, std::size_t N>
void printArray(std::array<T,N> arr)
{
    std::cout << "The array ("; 
    for (auto i : arr)
    {
        std::cout << i;
        if ( i != arr.back())
        {
            std::cout << ", ";
        }
        
    }
    std::cout << ") has length " << arr.size() << std::endl;
    
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}