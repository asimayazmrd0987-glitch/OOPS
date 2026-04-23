#include <iostream>
#include <stdlib.h>
using namespace std;

class Car
{
    static int totalCars;

public:
    Car()
    {
        totalCars++;
    }
    int howMany()
    {
        return totalCars;
    }
    ~Car()
    {
        totalCars--;
    }
};
int Car::totalCars = 0;
int main()
{
    Car toyota, suzuki, *mehran;
    cout << toyota.howMany() << ": Toyota Cars " << endl;
    cout << suzuki.howMany() << ": Suzuki Are " << endl;
    cout << mehran->howMany() << ": Mehrans Are " << endl;

    Car *honda = new Car;
    cout <<"Honda is :"<< honda->howMany() << endl;
    delete honda;
    cout << "Suzuki Are :" << suzuki.howMany() << endl;
    return 0;
}