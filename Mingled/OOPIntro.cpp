#include <iostream>
using namespace std;

// CLASS (Blueprint)
class Car {
    // ATTRIBUTES (Data)
public:
    string color;
    int speed;
    
    // BEHAVIORS (Functions)
    void start() {
        cout << color << " car started!" << endl;
    }
    
    void accelerate(int amount) {
        speed += amount;
        cout << "Speed now: " << speed << endl;
    }
};

int main() {
    // OBJECTS (Actual cars created from blueprint)
    Car myCar;          // Create object
    myCar.color = "Red"; // Set attributes
    myCar.speed = 0;
    
    Car yourCar;
    yourCar.color = "Blue";
    yourCar.speed = 0;
    
    // Use behaviors
    myCar.start();           // "Red car started!"
    myCar.accelerate(50);    // "Speed now: 50"
    
    yourCar.start();         // "Blue car started!"
    
    return 0;
}