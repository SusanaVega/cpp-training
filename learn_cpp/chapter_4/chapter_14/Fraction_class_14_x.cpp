#include <iostream>

// Convert Fraction from a struct to a class. Convert all of the functions to (non-static) member functions.

class Fraction
{
    public:
        const int getNum() const {return m_numerator;}
        const int getDen() const {return m_denominator;}

        void setNum(int num) {m_numerator = num;}
        void setDenom(int denom) {m_denominator = denom;}
        /*Making the constructor explicit prevents it from being used to create a Fraction via an implicit conversion with a single value. 
        This helps prevent nonsense like f1.multiply(true). f1.multiply(true) requires that true be implicitly converted to a Fraction. 
        Normally the compiler would use Fraction(int numerator=0, int denominator=1) for this, but if we make that constructor explicit, 
        it is not eligible to be used for implicit conversions. Since the compiler will then be unable to find a way to convert true into a Fraction, it will emit a compilation error.*/

        explicit Fraction (int num = 0, int den=1)
            : m_numerator{num}, m_denominator{den}
        {
        }

        void getFraction()
        {
            std::cout << "Enter a value for numerator: ";
            std::cin >> m_numerator;
            std::cout << "Enter a value for denominator: ";
            std::cin >> m_denominator;
            std::cout << '\n';

        }
    
    private:
        int m_numerator{0};
        int m_denominator{1};

};

const Fraction multiply (Fraction& F1, Fraction& F2)
{
    Fraction tempFrac;
    tempFrac.setNum(F1.getNum() * F2.getNum());
    tempFrac.setDenom(F1.getDen() * F2.getDen());
    return tempFrac;
}

void printFraction(const Fraction& f)
{
    std::cout << f.getNum() << '/' << f.getDen() << '\n';
}


int main()
{
    Fraction f1{};
    f1.getFraction();
    Fraction f2{}; 
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    printFraction(multiply(f1, f2));

    return 0;
}