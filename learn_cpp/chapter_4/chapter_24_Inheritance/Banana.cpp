//Write an Apple class and a Banana class that are derived from a common Fruit class. Fruit should have two members: a name and a color.
#include <iostream>
#include <string>
class Fruit
{
    protected:
        std::string m_name {};
        std::string m_color {};
    public:
        Fruit(std::string_view color, std::string_view name)
        : m_color{color}, m_name{name}
        {
    
        }
        const std::string& getName() const { return m_name; }
        const std::string& getColor() const { return m_color; }
};

class Apple: public Fruit
{
    public:
        Apple(std::string_view color, std::string_view name = "apple"): Fruit{color, name}
        {
        }
        // std::string getName() const {return m_name;}
        // std::string getColor() const {return m_color;}
    


};

class Banana: public Fruit
{
    public:
        Banana(std::string_view color = "yellow", std::string_view name = "banana"): Fruit{color, name}
        {
        }
        // std::string getName() const {return m_name;}
        // std::string getColor() const {return m_color;}
};

class GrannySmith: public Apple
{
    public:
        GrannySmith():Apple{"green","granny smith apple"}{}

};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}