#include <iostream>
using namespace std;

class hero
{
private:
    int health;
    int number;

public:

    int getnumber(int a)
    {
        return a;
    }
    int sethealth(int b)
    {
        return b;
    }
};

int main()
{
    // static allocation
    hero h1;
    cout << "The health is " << h1.sethealth(12) << endl;
    cout << "The number is " << h1.getnumber(22) << endl;

    // dynamic allocation
    hero *b = new hero;
    cout << "The health is " << (*b).sethealth(21) << endl;
    cout << "The number is " << (*b).getnumber(43) << endl;

    cout << "The health is " << b->sethealth(21) << endl;
    cout << "The number is " << b->getnumber(43) << endl;
}