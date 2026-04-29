#include <iostream>
using namespace std;
class containedClass; 
class containerClass {
private:
    int a, b; 
public:
    void getter() {
        cout << "Enter values of a and b: ";
        cin >> a >> b;
    }
    void putter() {
        cout << "a = " << a << ", b = " << b << endl;
    }
    friend class containedClass;
};
class containedClass {
public:
    void setter(containerClass obj) {
        cout << "== Accessing the private data of containedClass using friend class:== \n";
        cout << "a = " << obj.a << ", b = " << obj.b << endl;
    }};
int main() {
    containerClass c;
    containedClass c1;
    c.getter();
    c.putter();
    c1.setter(c); 
    return 0;
}