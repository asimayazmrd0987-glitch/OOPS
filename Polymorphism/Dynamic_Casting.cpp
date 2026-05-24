#include <iostream>
#include <typeinfo>
using namespace std;

class Animal {
public:
    virtual void speak() {} // Must have at least 1 virtual for RTTI
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof" << endl; }
    void fetch() { cout << "Dog is fetching" << endl; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Meow" << endl; }
    void climb() { cout << "Cat is climbing" << endl; }
};

int main() {
    Animal* zoo[3];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Dog();
    
    for (int i = 0; i < 3; i++) {
        // dynamic_cast checks actual type at runtime
        if (Dog* d = dynamic_cast<Dog*>(zoo[i])) {
            cout << "Index " << i << " is a Dog: ";
            d->fetch();
        }
        else if (Cat* c = dynamic_cast<<Cat*>(zoo[i])) {
            cout << "Index " << i << " is a Cat: ";
            c->climb();
        }
        
        // typeid alternative
        cout << "Type name: " << typeid(*zoo[i]).name() << endl;
        cout << "---" << endl;
    }
    
    // Cleanup
    for (int i = 0; i < 3; i++) delete zoo[i];
    
    return 0;
}