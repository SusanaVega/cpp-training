// Create a Fruit base class that contains two private members: a name (std::string), and a color (std::string). 
// Create an Apple class that inherits Fruit. Apple should have an additional private member: fiber (double)
// Create a Banana class that also inherits Fruit. Banana has no additional members.
#include <iostream>
#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};
public:	
    Fruit(std::string_view name, std::string_view color)
    : m_name{name}, m_color{color}
    {
    }
    std::string_view const getName() const{return m_name;}
    std::string_view const getColor() const{return m_color;}
};

class Apple: public Fruit
{
private:
    double m_fiber{};
public:
    Apple(std::string_view name, std::string_view color, double fiber)
        :Fruit{name, color}, m_fiber{fiber}
        {
        }
        double getFiber() const {return m_fiber;}
};
std::ostream& operator<<(std::ostream& out, const Apple& apple)
        {
            out << "Apple" << "(" << apple.getName() << ", " << apple.getColor() << ", " << apple.getFiber() << ")";
            return out;
        }

        class Banana: public Fruit
{
private:
public:
    Banana(std::string_view name, std::string_view color)
        :Fruit{name, color}
        {
        }
};
std::ostream& operator<<(std::ostream& out, const Banana& banana)
{
    out << "Banana" << "(" << banana.getName() << ", " << banana.getColor() << ")";
    out << std::endl;
    return out;
}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}

