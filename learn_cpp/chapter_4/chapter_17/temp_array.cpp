#include <iostream>
#include <array>


int main ()
{
    std::array<double,365> temp {};
    std::array<char,5> hello {'h','e','l','l','o'};
    std::cout << hello[1] << std::endl;
    std::string hola {"hola"};
    std::cout << "lenght: " << hola.length() << std::endl;
    std::cout << hello[1] << hello.at(1) << std::get<1>(hello);
    return 0;
}