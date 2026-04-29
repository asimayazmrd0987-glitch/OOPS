#include <iostream>
using namespace std;
class Shape {
protected:
    float dim1, dim2;   
public:
virtual float area() = 0;
      void getDimensions() {
        cout << "Enter first dimension: ";
        cin >> dim1;
             cout << "Enter second dimension: ";
        cin >> dim2;
    }
            virtual ~Shape() {}  
};
     class Rectangle : public Shape {
public:
    float area() override {
        return dim1 * dim2;
    }
};
class Triangle : public Shape {
public:
    float area() override {
        return 0.5f * dim1 * dim2;
    }
};
int main() {
    Rectangle rect;
    Triangle tri;
    cout << "=== Rectangle ===" << endl;
    rect.getDimensions();                 
    cout << "Area of rectangle: " << rect.area() << endl;
    cout << "\n=== Triangle ===" << endl;
    tri.getDimensions();                  
    cout << "Area of triangle: " << tri.area() << endl;
    return 0;
}