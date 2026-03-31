#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
#include <vector>

using namespace std;

/*Create a struct Student that stores the name and points of a student.
Create an array of students and use std::max_element to find the student 
with the most points, then print that student’s name. 

NOTE: 
1. The Algorithm's Logic
Internally, std::max_element asks one specific question to decide if it should update the "current winner":
"Is the current winner less than the new element?"
If you answer true, the algorithm replaces the old winner with the new one.

2. What happens with > (The Logic Flip)
When you use a.points > b.points, you change the meaning of the answer:
The Comparison: It compares Albert (3) and Ben (5).
Your Lambda: It checks 3 > 5, which is false.
The Result: The algorithm thinks: "The lambda said false, so the current winner (Albert) is NOT less than the challenger (Ben)."
The Action: It keeps Albert as the winner.
As the loop continues, the algorithm will only update the winner if the next student has fewer points than the current winner. Consequently, you actually end up finding the minimum element (Francis with 1 point) instead of the maximum.


*/

struct Student
{
	string_view name;
	int points;
};


int main()
{
	constexpr array <Student, 8> array
	{
	{{"Albert", 3},
	 {"Ben", 5},
	 {"Christine", 2},
	 {"Dan", 8},
	 {"Enchilada", 4},
	 {"Francis", 1},
	 {"Greg", 3},
	 {"Hagrid", 5}}
	};
	

	auto index_max = max_element(array.begin(), 
								 array.end(),
								 [](const Student& a, const Student& b) {return a.points < b.points? true : false;});
	cout << "The student with most points is: " << index_max->name << '\n';
	//;
	return 0;
}