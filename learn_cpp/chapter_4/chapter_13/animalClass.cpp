#include <iostream>
using namespace std;
class Animal {
public:
    virtual void speak() { cout << "Animal makes a sound..." << endl; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Dog barks: Woof!" << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Cat meows: Meow!" << endl; }
};

void makeAnimalSpeak(Animal &a) { a.speak(); }

int main() {
    Dog dog;
    Cat cat;
    Animal a;
    makeAnimalSpeak(dog);  // Output: Dog barks: Woof!
    makeAnimalSpeak(cat);  // Output: Cat meows: Meow!
    makeAnimalSpeak(a);  // Output: Cat meows: Meow!
    return 0;
}