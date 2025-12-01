#include<iostream>
#include <string_view>

// Write a class named Ball. 
// Ball should have two private member variables
// one to hold a color (default value: black), and one to hold a radius (default value: 10.0).
// Add 4 constructors, one to handle each case below:
// Ball def{};
// Ball blue{ "blue" };
// Ball twenty{ 20.0 };
// Ball blueTwenty{ "blue", 20.0 };

class Ball
{
    public:
        // Ball()
        // { 
        //     print();
        // }
        // Ball(std::string_view color)
        //     : Ball {color, default_radius}
        // {
        //     print();
        // }
        Ball(double radius)
            : Ball {default_color, radius}
        {
            //print();
            // We don't need to call print() here since it will be called by
		    // the constructor we delegate to
        }
        Ball(std::string_view color = default_color, double radius = default_radius)
            : m_color {color}, m_radius {radius}
        {
            print();
        }

        const std::string& getColor() {return m_color;}
        const double getRadius() {return m_radius;}
        void print()
        {
            std::cout <<  "Ball(" << getColor() << ", " << getRadius() << ")" << std::endl;
        }


    private:
        static constexpr std::string_view default_color {"black"}; 
        static constexpr double default_radius {10.0};
        std::string m_color {default_color};
        double m_radius {default_radius};

// Why must it be static?
// - Non-static members belong to an instance of a class, which means they don’t exist until an object is created.
// - Default arguments must be evaluated at compile time, but non-static members are initialized when an object is instantiated—too late for default argument resolution.
// - Making it static ensures default_color belongs to the class itself, rather than any particular object, allowing it to be used at compile time.
// Why must it be constexpr?
// - constexpr ensures that the value is a constant expression, meaning it can be evaluated at compile time.
// - Since std::string_view is just a lightweight reference, it must point to a constant expression (like a string literal) to ensure it remains valid.


};

int main ()
{
    //Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };
    return 0;
}