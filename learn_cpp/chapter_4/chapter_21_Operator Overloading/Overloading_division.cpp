#include <iostream>
using namespace std;

class Fraction
{
	private:
		int m_num{};
		int m_den{};
	public:
		Fraction(int num, int den)
			: m_num {num}, m_den {den}
			{}

	int getNum() const { return m_num; }
	int getDen() const { return m_den; }
	
	void print() const
	{
		cout << m_num << '/' << m_den << '\n';
	}
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, const int f2);
	friend Fraction operator*(const int f1, const Fraction& f2);

};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	int x{f1.m_num * f2.m_num};
	int y{f1.m_den * f2.m_den};

	return Fraction {x, y};
}

Fraction operator*(const Fraction& f1, const int f2)
{
	int x{f1.m_num * f2};
	return Fraction {x, f1.m_den};
}

Fraction operator*( const int f1, const Fraction& f2)
{
	int x{f2.m_num * f1};

	return Fraction {x , f2.m_den};
}


int main()
{
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    return 0;
}