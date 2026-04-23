#include <iostream>
using namespace std;
class Distance;
class Feet
{
    int feet;

public:
    Feet(int f) : feet(f) {}
    friend void adddistance(Feet , Distance );
};
class Distance
{
    int meter;

public:
    Distance(int m) : meter(m) {}
    friend void adddistance(Feet , Distance );
};
void adddistance(Feet f, Distance d)
{
    cout << f.feet <<" "<< d.meter<<endl;
}
int main()
{
    Feet c(12);
    Distance v(13);
    adddistance(c, v);

    return 0;
}