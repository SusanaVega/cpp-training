#include <iostream>
#include <vector>
#include <cassert>


// The rules of the game are simple: 
// Starting at 1, and counting upward, replace any number divisible only by three with the word “fizz”, 
// any number only divisible by five with the word “buzz”, 
// and any number divisible by both 3 and 5 with the word “fizzbuzz”.

void fizzbuzz(int input)
{
    bool flag{false};
    for(int i{1}; i <= input; i++)
    {
        flag = false;
        if (i%3 == 0)
        {
            std:: cout << "fizz";
            flag = true;
        }
        if(i%5 == 0)
        {
            std:: cout << "buzz";
            flag = true;
        }
        if(i%7 == 0)
        {
            std:: cout << "pop";
            flag = true;
        }
        if(flag == false)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

int main()
{
    //std::cout << "1%3:" << 1%3 << " 1%5:" << 1%5 << " 3%3:" << 3%3;
    fizzbuzz(150);
    return 0;
}