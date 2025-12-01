#include <iostream>
#include <typeinfo>
//#include <cstdint> // for fixed-width integers

double readValues(){
    std::cout << "Enter a double value: " << std::endl;
    double x{};
    std::cin >> x;
    return x;
}

char readOperator(){
    std::cout << "Enter operator (+, -, * or /): " << std::endl;
    char oper{};
    std::cin >> oper;
    return oper;
}

int main()
{
    std::cout << "Program started\n";
    double x{};
    x = readValues();
    double y{};
    y = readValues();
    char oper = readOperator();
    std::cout << "Type of oper: " << typeid(decltype(oper)).name() << std::endl;
    std::cout << "oper: " << oper << std::endl;
    if (oper == '+')
    {
      std::cout << x << " + " << y << " is " << x+y << std::endl;
    }
    else if (oper == '-')
    {
        std::cout << x << " - " << y << " is " << x-y << std::endl;
    }
    else if (oper == '*')
    {
        std::cout << x << " * " << y << " is " << x*y << std::endl;
    }
    else if (oper == '/')
    {
        std::cout << x << " / " << y << " is " << x/y << std::endl;
    }
    else
    {
        std::cout <<"Operation not handled by the program";
    }
 
    return 0;
}