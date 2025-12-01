#include <iostream>



// Step #1 Write a function template named add() that allows the users to add 2 values of the same type.
template <typename T>
T add (T x , T y)
{
    return x + y;
}

// Step #2: Write a function template named mult() that allows the user to multiply one value of any type (first parameter) and 
//          an integer (second parameter). The second parameter should not be a template type. 
//          The function should return the same type as the first parameter.

template <typename U>
U mult(U x , int y)
{
    return x * y;
}

//Step #3: Write a function template named sub() that allows the user to subtract two values of different types.
template <typename V, typename X>
auto sub(V x, X y)
{
    return x - y;
}

int main()
{
    //Step #1
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';
    //Step #2
    std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';
    //Step #3
    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}