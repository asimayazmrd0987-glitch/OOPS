#include <iostream>
using namespace std;

class Test {
private:
    int len;
    int width;

public:
    // Two-argument constructor
    Test(int l, int w) {
        len = l;
        width = w;
    }

    // Display function
    void display() const {
        cout << "Length: " << len << endl;
        cout << "Width: " << width << endl;
    }

    // Constant function to calculate area
    int getArea() const {
        return len * width;
    }
};

int main() {
    Test obj(10, 5);   // Object creation

    obj.display();

    cout << "Area: " << obj.getArea() << endl;

    return 0;
}


// 🔎 Why getArea() is const?

// Because it does not modify any data members — it only reads values and returns the result.