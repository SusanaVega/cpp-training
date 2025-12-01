#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
	if (stack.empty()) // if stack.size == 0
		std::cout << "Empty";

	for (auto element : stack)
		std::cout << element << ' ';

	// \t is a tab character, to help align the text
	std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size() << "\n";
}

int main()
{
	std::vector<int> stack{}; // empty stack
	stack.push_back(1);
	stack.push_back(2);
	stack.push_back(3);
	stack.push_back(4);
	printStack(stack);

	// stack.push_back(1); // push_back() pushes an element on the stack
	// printStack(stack);

	// stack.push_back(2);
	// printStack(stack);

	// stack.push_back(8);
	// printStack(stack);
	
    // stack.push_back(4);
	// printStack(stack);

    // stack.push_back(5);
	// printStack(stack);
    // stack.push_back(6);
    // stack.push_back(7);
    // stack.push_back(8);
    // stack.push_back(9);
    // printStack(stack);

	// std::cout << "Top: " << stack.back() << '\n'; // back() returns the last element

	// stack.pop_back(); // pop_back() pops an element off the stack
	// printStack(stack);

	// stack.pop_back();
	// printStack(stack);

	// stack.pop_back();
	// printStack(stack);

	return 0;
}