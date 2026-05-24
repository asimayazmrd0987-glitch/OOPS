#include <iostream>
using namespace std;

class Base {
public:
    virtual void func1() { cout << "Base::func1" << endl; }
    virtual void func2() { cout << "Base::func2" << endl; }
    void func3() { cout << "Base::func3 (non-virtual)" << endl; }
};

class Derived : public Base {
public:
    void func1() override { cout << "Derived::func1" << endl; }
    // func2 not overridden = uses Base's version via v-table
};

int main() {
    cout << "Size of Base: " << sizeof(Base) << " bytes" << endl;
    cout << "Size of Derived: " << sizeof(Derived) << " bytes" << endl;
    // On 64-bit systems, you'll see 8 or 16 bytes (the hidden v-pointer)
    
    Base* b = new Derived();
    b->func1();  // Derived::func1 (v-table lookup)
    b->func2();  // Base::func2 (inherited v-table entry)
    b->func3();  // Base::func3 (compile-time binding)
    
    delete b;
    return 0;
}