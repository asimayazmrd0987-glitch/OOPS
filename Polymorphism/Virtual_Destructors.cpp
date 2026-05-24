#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    
    // Without 'virtual' here, derived destructor NEVER runs
    // when deleted through base pointer = MEMORY LEAK
    virtual ~Base() { 
        cout << "Base destructor" << endl; 
    }
};

class Derived : public Base {
private:
    int* data;
    
public:
    Derived() {
        cout << "Derived constructor" << endl;
        data = new int[1000]; // Heap allocation
    }
    
    ~Derived() {
        cout << "Derived destructor (freeing memory)" << endl;
        delete[] data; // Critical cleanup
    }
};

int main() {
    cout << "=== Correct with virtual destructor ===" << endl;
    Base* obj = new Derived();
    delete obj;  // Both destructors run because of 'virtual'
    
    return 0;
}