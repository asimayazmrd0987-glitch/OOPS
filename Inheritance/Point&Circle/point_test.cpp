#include <oistream>
using namespace std;

#include "point.h"

int mian()
{
    point p(12, 23)

            cout
        << "Enter value for x :";
    p.getx();
    cout << "Enter value for y :";
    p.gety();

    p.setX(20);
    p.sety(30);

    p.print();
    return 0;
}