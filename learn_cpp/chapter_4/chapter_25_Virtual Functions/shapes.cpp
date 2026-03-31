#include <iostream>
#include <vector>
#include <algorithm> // for std::max


// Create an abstract class named Shape. This class should have three functions: 
// a pure virtual print function that takes and returns a std::ostream&,
// an overloaded operator<< and an empty virtual destructor.

// Derive two classes from Shape: a Triangle, and a Circle. 
// The Triangle should have 3 Points as members.

class Point
{
private:
    int m_x{};
    int m_y{};
public:
    Point(int x, int y):
    m_x{x}, m_y{y}
    {
    }
    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        return out << "Point(" << p.m_x << ", " << p.m_y << ')';
    }
};

class Shape
{
private:
    /* data */
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out,const Shape& p)
    {
        return p.print(out);
    }
    virtual ~Shape() = default;
};

class Triangle: public Shape
{
private:
    Point m_pointA;
    Point m_pointB;
    Point m_pointC;

public:
    Triangle (Point pointA, Point pointB, Point pointC):
    m_pointA{pointA}, m_pointB{pointB}, m_pointC{pointC}
    {
    }
    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_pointA << ", " << m_pointB << ", " << m_pointC << ")"; 
        return out;
    }
};

class Circle: public Shape
{
private:
    Point m_centerPoint;
    int m_radius;
public:
    Circle(Point centerPoint, int radius):
    m_centerPoint{centerPoint}, m_radius{radius}
    {
    }
    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_centerPoint << ", " << "radius " << m_radius << ")";
        return out;
    }
    int getRadius() const {return m_radius;}

};

/*
    std::unique_ptr SOLUTION
    const int getLargestRadius(std::vector<std::unique_ptr<Shape>>& v)
*/
const int getLargestRadius(std::vector<Shape*> v)
{
    int largestRadius{0};

    for (const auto &i : v)
    {
        // downcast a Shape* into a Circle*
        if (auto* d {dynamic_cast<Circle*>(i)})
        {
                largestRadius = std::max(largestRadius, d->getRadius());
        }
    }

    return largestRadius;
}

int main() 
{
    // Circle c{ Point{ 1, 2 }, 7 };
    // std::cout << c << '\n';

    // Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
    // std::cout << t << '\n';

    std::vector<Shape*> v
    {
        new Circle{Point{ 1, 2 }, 7},
        new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
        new Circle{Point{ 7, 8 }, 3}
    };

    /*
    std::unique_ptr SOLUTION
    std::vector<std::unique_ptr<Shape>> v;
    v.reserve(3);
    v.push_back(std::make_unique<Circle>(Point{1, 2}, 7));
    v.push_back(std::make_unique<Triangle>(Point{1, 2}, Point{3, 4}, Point{5, 6}));
    v.push_back(std::make_unique<Circle>(Point{7, 8}, 3));
    the last range loop should have to be removed because unique_ptr take cares of memory cleaning
    */

    // print each shape in vector v on its own line here
    // for each element 'i' (which is a Shape*)  in vector 'v' print its value (*i --> value  i --> address)
    for (const auto &i : v)
    {
        std::cout << *i << '\n';
    }
    
    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

    // delete each element in the vector here
    for (const auto *i : v)
    {
        delete i;
    }

    return 0;

}