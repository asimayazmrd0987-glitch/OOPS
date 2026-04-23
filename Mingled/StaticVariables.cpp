#include <iostream>
using namespace std;

class Employee {
private:
    int    id;
    string name;
public:
    // Static variable — declared here, ONE copy shared by all objects
    static int totalEmployees;
    // Static variable — shared constant (company name)
    static string companyName;
    // Constructor — increments the shared counter every time
    // an object is created
    Employee(int i, string n) : id(i), name(n) {
        totalEmployees++;
    }
    // Destructor — decrements counter when object is destroyed
    ~Employee() {
        totalEmployees--;
    }
    // Static member function — can access static members only
    // Called on the class, not on an object
    static void showTotal() {
        cout << companyName << " has "
             << totalEmployees << " employee(s)\n";
        // Cannot access id or name here — those are per-object members
    }
    void display() const {
        cout << "Employee #" << id
             << " | " << name
             << " | Company: " << companyName << "\n";
    }
};
// ── Definition + initialization OUTSIDE the class ──────────────
// This is where actual memory is allocated
int    Employee::totalEmployees = 0;
string Employee::companyName    = "TechCorp";

int main() {
    Employee::showTotal();   // TechCorp has 0 employee(s)
    Employee e1(1, "Asim");
    Employee e2(2, "Ali");
    Employee::showTotal();    // TechCorp has 2 employee(s)

    {
        Employee e3(3, "Sara");
        Employee::showTotal();   // TechCorp has 3 employee(s)
    }
    // e3 goes out of scope here — destructor fires, counter decrements

    Employee::showTotal();    // TechCorp has 2 employee(s)

    e1.display();
    e2.display();

    return 0;
}
// ```

// **Output:**
// ```
// TechCorp has 0 employee(s)
// TechCorp has 2 employee(s)
// TechCorp has 3 employee(s)
// TechCorp has 2 employee(s)
// Employee #1 | Asim | Company: TechCorp
// Employee #2 | Ali  | Company: TechCorp
// ```

// ## Memory Picture — Why This Matters
// ```
// Memory:

// e1 → [ id:1, name:"Asim" ]  ─┐
// e2 → [ id:2, name:"Ali"  ]   ├──▶ [ totalEmployees: 2 ]  ← ONE copy
// e3 → [ id:3, name:"Sara" ]  ─┘    [ companyName: "TechCorp" ]