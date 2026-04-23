#include <iostream>
using namespace std;

class Demo {
public:
    int *ptr;

    Demo(int val) {
        ptr = new int(val); //ptr=5
    }

    // Deep Copy Constructor
    Demo(const Demo &d){
     ptr = new int(*(d.ptr));
    }
    ~Demo() {
        delete ptr;
    }
};

int main() {
    Demo d1(5);
    Demo d2 = d1;   // Now safe
    cout<<d1.ptr<<endl;

    return 0;
}
