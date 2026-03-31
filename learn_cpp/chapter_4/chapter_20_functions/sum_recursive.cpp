/*
Write a recursive function that takes an integer as input and returns the sum 
of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15). 
Print the answer for input 93427 (which is 25). 
Assume the input values are positive.
*/

#include <iostream>
using namespace std;
int sum(int n)
{
	//base case //normal case
	cout << "n: " << n << endl;
	if (n <= 9) 
	{
		return n;
	}
	return sum(n / 10) + (n % 10);


}
int main()
{
	cout  << "Final: " << sum(8) << endl;
	return 0;
}