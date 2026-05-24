#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function = runtime binding
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
    
    // Non-virtual = compile-time binding
    void move() {
        cout << "Animal moves" << endl;
    }
    
    // Virtual destructor (CRITICAL in polymorphic base classes)
    virtual ~Animal() {
        cout << "Animal destroyed" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {  // C++11 override keyword
        cout << "Dog barks: Woof!" << endl;
    }
    
    void move() {
        cout << "Dog runs" << endl;
    }
    
    ~Dog() {
        cout << "Dog destroyed" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows: Meow!" << endl;
    }
    
    ~Cat() {
        cout << "Cat destroyed" << endl;
    }
};

int main() {
    Animal* ptr;  // Base class pointer
    
    Dog dog;
    Cat cat;
    
    // Point to Dog object
    ptr = &dog;
    ptr->speak();  // Dog barks (runtime decision)
    ptr->move();   // Animal moves (compile-time, NOT virtual)
    
    // Point to Cat object
    ptr = &cat;
    ptr->speak();  // Cat meows (runtime decision)
    
    return 0;
}