#include <iostream>
using namespace std;

class Hero {                    // Capitalize class names (convention)
private:
    int health;
    int number;

public:
    // Default
    Hero() : health(12), number(0) {   // Member initializer list (better)
        cout << "Default constructor, this = " << this << endl;
    }
    
    // Parameterized
    Hero(int health, int number = 0) {  // Default parameter
        cout << "Parameterized constructor, this = " << this << endl;
        this->health = health;          // Use this for clarity
        this->number = number;
    }
    
    // Proper getter
    int getHealth() const {             // const = doesn't modify
        return this->health;            // explicit but optional
    }
    
    // Proper setter
    void setHealth(int health) {        // void = returns nothing
        this->health = health;          // actually modifies member!
    }
    
    // Print info
    void print() const {
        cout << "Health: " << health << ", Number: " << number 
             << " at " << this << endl;
    }
    
    // Destructor (good practice)
    ~Hero() {
        cout << "Destructor called for " << this << endl;
    }
};

int main() {
    cout << "=== Static Object ===" << endl;
    Hero h1(100, 5);        // Stack
    h1.print();
    
    cout << "\n=== Dynamic Object ===" << endl;
    Hero* h2 = new Hero(200, 10);   // Heap
    h2->print();            // Arrow operator for pointers
    
    cout << "\nAddress comparison:" << endl;
    cout << "&h1 = " << &h1 << endl;
    cout << "h2 = " << h2 << endl;
    
    delete h2;              // CRITICAL: Free memory
    
    return 0;
}