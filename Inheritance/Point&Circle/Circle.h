// #include <iostream>
// using namespace std;
#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class circle : public point
{
    circle(int x = 0, int y = 0, double z = 0.0);

    void setRadius(double);   // set radius
    double getRadius() const; // return radius

    double getDiameter() const;      // return diameter
    double getCircumference() const; // return circumference
    double getArea() const;          // return area
    void print() const;              // output Circle2 object
private:
    double radius; // Circle2's radius
}
#endif
