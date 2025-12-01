// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>

bool isPrime(int x)
{
    if ((x == 0) || (x == 1)){
        return false;
    }
    else{
        bool result = true;
        for(int i = x-1; i > 1; i--){
            //std::cout << "value of i: " << i << std::endl;
            if ((x % i) == 0){
                result = false;
                break;
            }
            else{
                result = true;
            }            
        }
        result ? std::cout << "Success!" : std::cout << "Not a Prime number";
        return result;
    }
    //return false;
    // write this function using a for loop
}

int main()
{
    assert(!isPrime(0)); // terminate program if isPrime(0) is true
    assert(!isPrime(1));
    assert(isPrime(2));  // terminate program if isPrime(2) is false
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}