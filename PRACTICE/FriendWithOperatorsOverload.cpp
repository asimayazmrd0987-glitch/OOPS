#include <iostream>
using namespace std;
class Vector2D
{
private:
    double x, y;

public:
    Vector2D(double x, double y) : x(x), y(y) {}

    friend ostream &operator<<(ostream &os, const Vector2D &v);

    friend Vector2D operator+(const Vector2D &a, const Vector2D &b);
};

ostream &operator<<(ostream &os, const Vector2D &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

Vector2D operator+(const Vector2D &a, const Vector2D &b)
{
    return Vector2D(a.x + b.x, a.y + b.y);
}
int main()
{
    Vector2D v1(23, 2);
    Vector2D v2(2, 4);
    Vector2D v3 = v1 + v2;
    cout << "v1 :" << v1 << "v2 :" << v2 << "v3 :" << v3 << endl;
    return 0;
}