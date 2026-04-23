#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;
public:
    // Constructor
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {}

    // Overloading binary + operator
    // Left operand  = *this
    // Right operand = rhs (the parameter)
    Distance operator+(const Distance& rhs) const {
    int totalInches = (feet * 12 + inches)+ (rhs.feet * 12 + rhs.inches);
    // Distance operator+(const Distance& rsh){

    //     return Distance(feet*12+inches+rsh.feet +rsh.inches)
    // }
        // convert back to feet and inches
        return Distance(totalInches / 12, totalInches % 12);
    }
    // Overloading binary == operator
    bool operator==(const Distance& rhs) const {
        return (feet == rhs.feet) && (inches == rhs.inches);
    }

    void display() const {
        cout << feet << " feet " << inches << " inches\n";
    }
};

int main() {
    Distance d1(5, 9);    // 5 feet 9 inches
    Distance d2(3, 6);    // 3 feet 6 inches

    cout << "d1 = "; d1.display();
    cout << "d2 = "; d2.display();

    // Uses our overloaded + operator
    // Calls: d1.operator+(d2)
    Distance d3 = d1 + d2;
    cout << "d1 + d2 = "; d3.display();
    // 5*12+9 = 69 inches
    // 3*12+6 = 42 inches
    // total  = 111 inches = 9 feet 3 inches

    // Uses our overloaded == operator
    cout << "d1 == d2? " << (d1 == d2 ? "Yes" : "No") << "\n";
    return 0;
}
// ```

// **Output:**
// ```
// d1 = 5 feet 9 inches
// d2 = 3 feet 6 inches
// d1 + d2 = 9 feet 3 inches
// d1 == d2? No