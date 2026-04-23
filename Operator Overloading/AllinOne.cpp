#include <iostream>
using namespace std;

class Vec2
{
public:
    int x, y;
    Vec2(int x = 0, int y = 0) : x(x), y(y) {}
    Vec2 operator+(const Vec2 &rsh) const
    {
        return Vec2(x + rsh.x, y + rsh.y);
    }
    Vec2 &operator+=(const Vec2 &rsh)
    {
        x += rsh.x;
        y += rsh.y;
        return *this;
    }

    Vec2 operator*(double scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }
    bool operator==(const Vec2 &rsh) const
    {
        return (x == rsh.x && y == rsh.y);
    }
    friend ostream &operator<<(ostream &os, const Vec2 &v)
    {
        os << v.x << " , " << v.y;
        return os;
    }
};
int main()
{
    Vec2 v1(12, 14);
    Vec2 v2(1, 3);
    Vec2 v3 = v1 + v2;
    cout << v3 << endl;
    v3 += v2;
    cout << v3 << endl;
    Vec2 v4;
    v4=v1 * 2;
    cout << v4 << endl;
    return 0;
}