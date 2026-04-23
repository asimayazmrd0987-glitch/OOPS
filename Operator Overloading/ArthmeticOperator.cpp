#include <iostream>
using namespace std;
#include <vector>
class Vector
{
public:
    int x, y;
    Vector(int x, int y) : x(x), y(y) {}

    Vector operator+(const Vector &v)
    {
        return Vector(x + v.x, y + v.y);
    }

    Vector operator-(const Vector &v)
    {
        return Vector(x - v.x, y - v.y);
    }
};

int main()
{
    Vector v1(3, 4), v2(1, 2);
    Vector v3 = v1 + v2; // x=4, y=6
    Vector v4 = v1 - v2; // x=2, y=2
    cout << "V3.x = " << v3.x << " " << "V3.y = " << v3.y << endl;
    cout << "V4.x = " << v4.x << " " << "V4.y = " << v4.y << endl;
}
