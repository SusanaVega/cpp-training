#include <iostream>

long *memo; // Declaring memo as a pointer to long

long fib(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }

    if (n <= 1) {
        memo[n] = n;
    } else {
        memo[n] = fib(n - 1) + fib(n - 2);
    }

    return memo[n];
}

int fibRecursive(int n) {
    if (n == 1 || n == 0) {
        return n;
    }
    
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n = 10;
    memo = new long[n + 1]; // Allocating memory for memo

    for (int i = 0; i <= n; ++i) {
        memo[i] = -1; // Initializing memoization array with -1
    }

    // Print the Fibonacci number at position n multiple times without using a loop
    std::cout << "Fibonacci number at position " << n << " is: " << fib(n) << std::endl;
    std::cout << "Fibonacci number at position " << n << " is: " << fib(n) << std::endl;
    std::cout << "Fibonacci number at position " << n << " is: " << fib(n) << std::endl;
    std::cout << "Fibonacci number at position " << n << " is: " << fib(n) << std::endl;
    std::cout << "Fibonacci number at position " << n << " is: " << fib(n) << std::endl;
    std::cout << "Fibonacci-Recurive number at position " << n << " is: " << fibRecursive(n) << std::endl;


    delete[] memo; // Free allocated memory

    return 0;
}