#include <iostream>
#include <vector>
#include <string_view>
// Write a program that pushes and pops values, and outputs the following sequence:

void printVector (const std::vector<int>& myVector)
{
    if (myVector.empty()) 
    {
        std::cout << "(Stack: empty)";
    }
    else
    {
        std::cout << "Stack: ";
        for(auto i: myVector)
        {
            std::cout << i << " ";
        }
    }

}
void pushNPrint(std::vector<int>& myVector, const int& pushedVal)
{
    myVector.push_back(pushedVal);
    std::cout << "Push " << pushedVal << "  ";
    printVector(myVector);
    std::cout << std::endl;
}

void popNPrint(std::vector<int>& myVector)
{
    myVector.pop_back();
    std::cout << "Pop     ";
    printVector(myVector);
    std::cout << std::endl;

}

int main()
{
    std::vector<int> arr{};
    pushNPrint(arr,1);
    pushNPrint(arr,2);
    pushNPrint(arr,3);
    popNPrint(arr);
    pushNPrint(arr,4);
    popNPrint(arr);
    popNPrint(arr);
    popNPrint(arr);
    std::vector vec{2,4,6,8,10};
    const std::vector a {1.2,3.4,5.6,7.8};
    using namespace std::literals::string_view_literals;
    const std::vector str{ "Alex"sv, "Brad"sv, "Charles"sv,"Dave"sv};
    std::vector num{12};
    std::vector<int> v(12);
    std::cout << num[0];
    return 0;
}