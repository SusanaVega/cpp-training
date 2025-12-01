#include <iostream>
//#include <typeinfo>
//#include <cstdint> // for fixed-width integers
#include <cmath> // for pow

double fallenCalc(double time, double height){
    const double gravity { 9.8 };
    double fallen_calculation = height - (gravity * (std::pow(time,2)))/2;
    if (fallen_calculation < 0) {
        return 0.0;
    }
    else{
        return fallen_calculation;
    }
}

void printMsg(double time, double height){
    if (height == 0.0){
        std::cout<< "At " << time << " seconds, the ball is on the ground" << std::endl;
    }
    else{
        std::cout<< "At " << time << " seconds, the ball is at height: " << height << " meters" << std::endl;
    }
    
}

int main()
{
    std::cout << "Enter the height of the tower in meters: ";
    double height{};
    std::cin >> height;
    printMsg(0, fallenCalc(0,height));
    printMsg(1, fallenCalc(1,height));
    printMsg(2, fallenCalc(2,height));
    printMsg(3, fallenCalc(3,height));
    printMsg(4, fallenCalc(4,height));
    printMsg(5, fallenCalc(5,height));
    return 0;
}