#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Weapon {
public:
    virtual void attack() = 0;
    virtual ~Weapon() = default;
};

class Sword : public Weapon {
public:
    void attack() override {
        cout << "Swinging sword! Slash!" << endl;
    }
};

class Bow : public Weapon {
public:
    void attack() override {
        cout << "Shooting arrow! Thwip!" << endl;
    }
};

class Staff : public Weapon {
public:
    void attack() override {
        cout << "Casting fireball! Fwoosh!" << endl;
    }
};

int main() {
    // vector<<unique_ptr<<Weapon>> = polymorphic container
    // No manual delete needed, no memory leaks
    vector<<unique_ptr<<Weapon>> inventory;
    
    inventory.push_back(make_unique<Sword>());
    inventory.push_back(make_unique<Bow>());
    inventory.push_back(make_unique<<Staff>());
    
    cout << "=== Combat Test ===" << endl;
    for (auto& weapon : inventory) {
        weapon->attack(); // Runtime dispatch
    }
    
    // Weapons auto-destruct here in reverse order
    return 0;
}