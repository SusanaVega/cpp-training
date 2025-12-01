#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>



void fizzBuzz(int num)
{
    static const std::vector<int> array {3, 5, 7, 11, 13, 17, 19};
    static const std::vector<std::string_view> word { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    //check that array sizes match
    assert(std::size(array) == std::size(words) && "fizzbuzz: array sizes don't match");
    bool flag{};
    std::size_t lenght{array.size()};
    for (int i{1} ; i <= num; i++)
    {
        flag = false;
        for (size_t j{0}; j < lenght; j++)
        {
            if (i%array[j]==0)
            {
                std::cout << word[j];
                flag=true;
            }
        }
        if (flag == false)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }


}

int main()
{
    fizzBuzz(21);
    return 0;
}