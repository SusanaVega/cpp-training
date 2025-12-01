#include<iostream>
#include <string_view>

// Write a class named Ball. 
// Ball should have two private member variables, one to hold a color, and one to hold a radius.
// Also write a function to print out the color and radius of the ball.
class Ball
{
    public:
    Ball (std::string_view color, double radio)
        :m_color {color}, m_radio {radio} 
    {

    }
    const std::string& getColor() const {return m_color;}
    double getRadio() const {return m_radio;}

    private:
    std::string m_color {};
    double m_radio {};
};

void print(const Ball& ball2Print)
{
    std::cout << "Ball(" << ball2Print.getColor() << ", " << ball2Print.getRadio() << ")" << std::endl;
}

int main ()
{
    Ball blue { "blue", 10.0 };
	print(blue);

	Ball red { "red", 12.0 };
	print(red);
    return 0;
}