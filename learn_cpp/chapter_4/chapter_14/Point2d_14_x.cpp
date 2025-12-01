#include <iostream>
#include <cmath>

// Write a class named Point2d. 
// Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0.
// Provide a constructor and a print() function.
// Now add a member function named distanceTo() that takes another Point2d as a parameter
// Given two points (x1, y1) and (x2, y2), the distance between them can be calculated
// using the formula std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))
class Point2d
{
    public:
        const double xGetter() const {return m_x;}
        const double yGetter() const {return m_y;}

        Point2d() = default;

        Point2d(double x, double y)
            : m_x {x}, m_y {y}
        {
            std::cout << "Constructor was executed" << std::endl;
        }
        
        void print()
        {
            std::cout << "Point2d(" << xGetter() << ", " << yGetter() << ")" << std::endl;
        }
        
        double distanceTo(const Point2d& point) const
        {
            return sqrt((point.xGetter() - m_x)*(point.xGetter() - m_x) + (point.yGetter() - m_y)*(point.yGetter() - m_y));
        }

    private:
        double m_x{0.0};
        double m_y{0.0};
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    //Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}