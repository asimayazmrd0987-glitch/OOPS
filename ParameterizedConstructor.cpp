#include <iostream>
using namespace std;

class hero
{
private:
    int health;
    int number;

public:
    // default
    inline hero()
    {
        cout << "Constructor call " << endl;
    }
    // parameterized constructor
    inline hero(int health)
    {
        cout << " === this -> is === " << this << endl;
        this->health = health;
    }
};

int main()
{
    // object statically created
    hero h1(10);
    cout << "The address is " << &h1 << endl;

    // Dynamic call
    hero *b = new hero(10);
    delete b;
}
