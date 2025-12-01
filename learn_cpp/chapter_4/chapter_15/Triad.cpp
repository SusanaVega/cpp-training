#include <iostream>
// Write a class template named Triad that has 3 private data members with independent type template parameters. 
// The class should have a constructor, access functions, and a print() member function that is defined outside the class.
template <typename T, typename U, typename V>
class Triad
{
    public:
    Triad (T data1, U data2, V data3)
        : m_data1{data1}, m_data2{data2}, m_data3{data3}
    {
    
    }

    const T& first() const {return m_data1;}
    const U& second() const {return m_data2;}
    const V& third() const {return m_data3;}

    void print() const; 

    private:
        T m_data1;
        U m_data2;
        V m_data3;

};
template <typename T, typename U, typename V>
void Triad<T, U, V>::print() const
{
    std::cout << "[" << m_data1 << ", "<< m_data2 << ", " << m_data3 << "]";
}

int main()
{
    Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

// If we remove the const from the print() function declaration and definition, 
// the program will no longer compile. Why not?

// t2 is a const object, so only const member functions can be invoked on t2. If we make print() a non-const member function, then t2 is not allowed to call it. 
// This is because a non-const member function could conceivably modify the implicit object, 
// which would be a violation of the constness of the const object (t2 in this case).

    using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';
    return 0;
}