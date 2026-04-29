#include <iostream>
using namespace std;

class Base {
protected:
    int data;
public:
    void display() {
        cout << "I am base class display function" << endl;
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "I am derived class display function" << endl;
    }
};

int main() {
    Derived obj;
    obj.Base::display();   
    obj.display();         
    return 0;
}