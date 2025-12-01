#include <iostream>
#include <vector>
#include <cassert>

// Create a program-defined enum (inside a namespace) containing the names of the following animals: chicken, dog, cat, elephant, duck, and snake.
// Define an array with an element for each of these animals and use an initializer list to initialize each element to hold the number of legs that animal has.
// Assert that the array has the correct number of initializers.
namespace data
{
    enum Animals
    {
        chicken,     //0
        dog,         //1
        cat,         //2
        elephant,    //3
        duck,        //4
        snake,       //5
        max_animals, //6
    };
    const std::vector legs{2,4,4,4,2,0};
}

int main()
{

    // Ensure the number of test scores is the same as the number of students
    assert(std::size(data::legs) == data::max_animals);
    std::cout << "the elephant has " << data::legs[data::elephant] << " legs";
    return 0;
}

