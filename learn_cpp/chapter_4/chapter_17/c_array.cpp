#include <iostream>
#include <cstring>


void printString(const char str[])
{
    const char* begin {str};
    const char* end {str + std::strlen(str)};

    for(; begin <= end ; --end)
    {
        std::cout << "\'" << *end << "\'  ";
    }
}

int main()
{
    constexpr char str[]{"Hello, world!"};
    printString(str);
    std::cout << std::endl<< "Size of int: " << sizeof(int) << " bytes\n";
    return 0;
}