#include <iostream>

// Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.
// Write a function to read in a Fraction from the user, and use it to read-in two fraction objects
// Write another function to multiply two Fractions together and return the result as a Fraction
// Write another function that prints a fraction.
struct Fraction
{
    int numerator;
    int denominator;
};

Fraction getFraction()
{
    Fraction tempFraction {};
    std::cout << "Enter a value for the numerator: " << std::endl;
    std::cin >> tempFraction.numerator; 
    std::cout << "Enter a value for the denominator: " << std::endl;
    std::cin >> tempFraction.denominator;
    std::cout << std::endl;
    return tempFraction; 
}

Fraction multiplication (const Fraction& a, const Fraction& b)
{
    Fraction fractionProduct {};
    fractionProduct.numerator = a.numerator * b.numerator;
    fractionProduct.denominator = a.denominator * b.denominator;
    return fractionProduct;
}

void PrintValues (const Fraction& printFraction)
{
    std::cout << "Your fraction multiplied together: " << printFraction.numerator << "/" << printFraction.denominator << std::endl;
}

int main()
{
    Fraction aFraction {getFraction()};
    Fraction bFraction {getFraction()};
    PrintValues(multiplication(aFraction,bFraction));
    return 0;
}