#include <iostream>

int main()
{
    int x=20, y=35;
    x= y++ + x++;
    printf("x=%d\ny=%d\n\n",x,y);
    y= ++y + ++x;
    printf("x=%d\ny=%d\n",x,y);


    short value{ 7 }; // &value = 0012FF60
	short otherValue{ 3 }; // &otherValue = 0012FF54

	short* ptr{ &value };

	std::cout << &value << '\n'; //0012FF60
	std::cout << value << '\n';//7
	std::cout << ptr << '\n'; //0012FF60
	std::cout << *ptr << '\n'; //7
	std::cout << '\n';

	*ptr = 9; // value = 9

	std::cout << &value << '\n'; //0012FF60
	std::cout << value << '\n';  //9
	std::cout << ptr << '\n'; //0012FF60
	std::cout << *ptr << '\n'; //9
	std::cout << '\n';

	ptr = &otherValue; //0012FF54

	std::cout << &otherValue << '\n'; //0012FF54
	std::cout << otherValue << '\n'; // 3
	std::cout << ptr << '\n'; //0012FF54
	std::cout << *ptr << '\n'; // 3
	std::cout << '\n';

	std::cout << sizeof(ptr) << '\n'; //4
	std::cout << sizeof(*ptr) << '\n'; //2

    return 0;
}

predictable, undefined, or possibly undefined
Assume that any objects mentioned are of a type that the pointer can point to.

2a) Assigning the address of an object to a non-const pointer //predictable

Show Solution

2b) Assigning nullptr to a pointer //predictable

Show Solution

2c) Dereferencing a pointer to a valid object //predictable

Show Solution

2d) Dereferencing a dangling pointer // undefined

Show Solution

2e) Dereferencing a null pointer //predictable  ***undefined

Show Solution

2f) Dereferencing a non-null pointer // predictable  **possibly undefined

Show Solution




