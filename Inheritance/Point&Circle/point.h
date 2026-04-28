#ifndef POINT_H
#define POINT_H

class point
{
public:
    point(int x = 0, int y = 0);

    void setx(int);
    int getx(int) const;

    void sety(int);
    int gety(int) const;

    void print() const;

private:
    int x;
    int y;
}
#endif
