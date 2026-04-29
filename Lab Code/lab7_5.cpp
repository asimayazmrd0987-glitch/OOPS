#include <iostream>
using namespace std;
class DB; 
class DM {
private:
    int meters, centimeters;
public:
    void input() {
        cout << "Enter meters and centimeters: ";
        cin >> meters >> centimeters;
    }
    void display() {
        cout << "Distance(DM): " << meters << " m " << centimeters << " cm\n";
    }
    friend DM add(DM d, DB b);
};
class DB {
private:
    int feet, inches;
public:
    void input() {
        cout << "Enter feet and inches: ";
        cin >> feet >> inches;
    }
    void display() {
        cout << "Distance (DB): " << feet << " ft " << inches << " in\n";
    }    
    friend DM add(DM d, DB b);
};
DM add(DM d, DB b) {    
    int total_cm_dm = d.meters * 100 + d.centimeters;// here convert DM → cm   
    int total_inches = b.feet * 12 + b.inches; //  here convert DB → cm
    int total_cm_db = total_inches * 2.54;    
    int total_cm = total_cm_dm + total_cm_db;//here is add
    DM result;//here is convert back → meters + cm
    result.meters = total_cm / 100;
    result.centimeters = total_cm % 100;
    return result;
}
int main() {
    DM d;
    DB b;
    d.input();
    b.input();
    DM result = add(d, b);
    result.display();
    return 0;
}