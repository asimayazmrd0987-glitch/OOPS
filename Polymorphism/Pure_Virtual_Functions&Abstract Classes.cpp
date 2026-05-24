#include <iostream>
using namespace std;

// Abstract class = cannot instantiate directly
class Shape {
public:
    // Pure virtual function = 0
    virtual double area() = 0;      // Must implement in derived
    virtual double perimeter() = 0; // Must implement in derived
    
    virtual void draw() {
        cout << "Drawing a generic shape" << endl;
    }
    
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() override {
        return width * height;
    }
    
    double perimeter() override {
        return 2 * (width + height);
    }
    
    void draw() override {
        cout << "Drawing rectangle: " << width << "x" << height << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return PI * radius * radius;
    }
    
    double perimeter() override {
        return 2 * PI * radius;
    }
    
    void draw() override {
        cout << "Drawing circle with radius: " << radius << endl;
    }
};

int main() {
    // Shape s; // ERROR: abstract class
    
    Rectangle rect(10, 5);
    Circle circle(7);
    
    Shape* shapes[2];
    shapes[0] = &rect;
    shapes[1] = &circle;
    
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
        cout << "---" << endl;
    }
    
    return 0;
}