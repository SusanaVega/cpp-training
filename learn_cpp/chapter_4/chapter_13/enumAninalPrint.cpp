#include <iostream>
#include <string_view>
// Define an enum class named Animal that contains the following animals: pig, chicken, goat, cat, dog, duck
// Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement to return the name for that animal 
// as a std::string_view (or std::string if you’re using C++14)
// Write another function named printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on
// Make sure both functions have a default case that prints an error message.
// Call printNumberOfLegs() from main() with a cat and a chicken

enum class Animal
{
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal input)
{
    switch (input)
    {
       case Animal::pig:     return "pig";
       case Animal::chicken: return "chicken";
       case Animal::goat:    return "goat";
       case Animal::cat:     return "cat";
       case Animal::dog:     return "dog";
       case Animal::duck:    return "duck";
       default:              return "???";
       break;
    }

}

void printNumberOfLegs(Animal input)
{
    switch (input)
    {
       case Animal::pig:     std::cout << "A " << getAnimalName(input) << " has 4 " << " legs " << std::endl; break;
       case Animal::chicken: std::cout << "A " << getAnimalName(input) << " has 2 " << " legs " << std::endl; break;
       case Animal::goat:    std::cout << "A " << getAnimalName(input) << " has 4 " << " legs " << std::endl; break;
       case Animal::cat:     std::cout << "A " << getAnimalName(input) << " has 4 " << " legs " << std::endl; break;
       case Animal::dog:     std::cout << "A " << getAnimalName(input) << " has 4 " << " legs " << std::endl; break;
       case Animal::duck:    std::cout << "A " << getAnimalName(input) << " has 2 " << " legs " << std::endl; break;
       default:              std::cout << "???" << std::endl;
    }

}

int main ()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);
    return 0;
}