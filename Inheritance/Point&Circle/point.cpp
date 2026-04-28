#include <iostream>
using namespace std;

#include "point.h"

point::point(int xval, int yval)
{
    x = xval;
    y = yval;
}
void point::setx(int xval)
{
    x = xval;
}
int point ::getx() const
{
    return x;
}
void point::sety(int yval)
{
    y = yval;
}
int point::gety() const
{
    return y;
}
void point::print() const
{
    cout << "x :" << x << " y :" << y << endl;
}
