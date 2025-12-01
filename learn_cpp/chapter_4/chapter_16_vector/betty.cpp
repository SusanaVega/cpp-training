#include <iostream>
#include <vector>
#include <string_view>
// Define a std::vector with the following names: “Alex”, “Betty”, “Caroline”, “Dave”, “Emily”, “Fred”, “Greg”, and “Holly”. 
// Ask the user to enter a name. 
// Use a range-based for loop to see if the name the user entered is in the array.
// create a function template (not a normal function) called isValueInArray() that takes two parameters: a std::vector, and a value.
// The function should return true if the value is in the array, and false otherwise. 
template <typename T, typename U>
bool isValueInArray(const std::vector<T>& myVector, U& value)
{
    bool found {false};
    for (const auto& i : myVector)
    {
        if (value == i)
        {       
            found = true;
        }
    }
    return found;
}
int main()
{
    const std::vector<std::string> name {"Alex","Betty","Caroline","Dave","Emily","Fred","Greg","Holly"};
    std::string input{};
    std::cout << "Enter a name: ";
    std::cin >> input;

    bool found{};
    found = isValueInArray(name, input);

    found ? (std::cout << input << " was found") : (std::cout << input << " was not found");
    return 0;
}