#include <iostream>
#include <cassert>


// Write a constexpr function template with a non-type template parameter 
// that returns the factorial of the template argument.
// The following program should fail to compile when it reaches factorial<-3>().


// define your factorial() function template here

template <int N>
constexpr int factorial()
{
    int result {1};
    static_assert(N >= 0);
    for (int i = 1; i <     ; i++)
    {
        result*= (i+1);
        //std::cout << "result: " << result << std::endl;
    }  
    return result;

}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);
    static_assert(factorial<6>() == 720);

    factorial<-3>(); // should fail to compile

    return 0;
}