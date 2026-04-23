#include <iostream>
using namespace std;

template <typename T>
class Box {
    T value;

public:
    void set(T v) {
        value = v;
    }

    T get() {
        return value;
    }
};

int main() {
    Box<int> b1;
    b1.set(10);
    cout << b1.get() << endl;

    Box<double> b2;
    b2.set(3.14);
    cout << b2.get() << endl;
}
