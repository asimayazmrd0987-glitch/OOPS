#include <iostream>
using namespace std;

class hero
{
private:
    int health;
    int number;

public:
    hero()
    {
        cout << "Constructor call " << endl;
    }
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
    // object statically created
    hero h1;
    // Dynamic call
    hero* b=new hero;
}