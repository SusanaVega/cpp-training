#include <iostream>
#include <vector>
#include <limits> // for std::numeric_limits




// Write a function that takes two parameters: a std::vector and an index
template <typename T>
void printElement(const std::vector<T>& myVector, int index)
{
    std::cout << "SIZE: " << myVector.size() << std::endl;
    if (index < 0 || index >= (myVector.size()))
    {
        std::cout << "Invalid Index" << std::endl;
    }
    else
    {
        std::cout << "The element has value " << myVector[index] << std::endl;
    }
    

}

template <typename U>
void printArray(const std::vector<U>& myArray)
{
    std::size_t arrLenght {myArray.size()};

    for (size_t i = 0; i < arrLenght; i++)
    {
        std::cout << myArray[i] << ", ";
    }
    std::cout << std::endl;

}
// Write a function template to search the array for the value that the user entered. 
// If the value is in the array, return the index of that element. 
// If the value is not in the array, return an appropriate value.
template <typename V>
void search(const std::vector<V>& container, std::size_t num)
{
    bool flag {false};
    std::size_t lenght {container.size()};
    for (size_t i = 0; i < lenght; i++)
    {
        if (num == container[i])
        {
            std::cout << "The number " << num << " has index " << i << std::endl;
            flag = true;
            break;
        }        
    }
    if (!flag)
    {
        std::cout << "The number " << num << " was not found." << std::endl; 
    }    
}


int main()
{
    // //Q1 Define a std::vector using CTAD and initialize it with the first 5 positive square numbers (1, 4, 9, 16, and 25).
    // std::vector<int> v(3);
    // std::cout << "Enter 3 integers:";
    // std::cin >> v[0] >> v[1] >> v[2];
    // // std::cin >> v[1];
    // // std::cin >> v[2];
    // std::cout << std::endl << "The sum is: " << v[0] + v[1] + v[2] << std::endl;
    // std::cout << "the product is: " << v[0] * v[1] * v[2] << std::endl;

    // // Initialize a std::vector with the following values: 'h', 'e', 'l', 'l', 'o'. 
    // const std::vector<char> v{ 'h', 'e', 'l', 'l', 'o'}; 
    // std::cout << "The array has " << std::size(v) << " elements." << std::endl;
    // std::cout << v[1] << v.at();

    // Write a function that takes two parameters: a std::vector and an index

    // std::vector v1 { 0, 1, 2, 3, 4 };
    // printElement(v1, 2);
    // printElement(v1, 5);

    // std::vector v2 { 1.1, 2.2, 3.3 };
    // printElement(v2, 0);
    // printElement(v2, -1);

    //Write a short program that prints the elements of the following vector to the screen using a loop:

    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
    int num {};
    std::cout << "Enter a number between 1 and 9: ";
    while(true)
    {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter a number between 1 and 9: ";
        }
        else
        {
            break;
        }
        // To ignore everything up to and including the next ‘\n’ character, we call
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    printArray(arr); // use function template to print array
    search(arr,num);
    



    return 0;
}