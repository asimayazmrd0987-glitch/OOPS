#include <iostream>
using namespace std;

class Testing {
public:
    // Const member function
    void constant() const {
        cout << "This is a constant member function." << endl;
    }

    // Non-const member function
    void non_constant() {
        cout << "This is a non-constant member function." << endl;
    }
};

int main() {
    Testing obj1;           // Non-constant object
    const Testing obj2;     // Constant object

    cout << "Calling from non-constant object:\n";
    obj1.constant();        // Allowed
    obj1.non_constant();    // Allowed

    cout << "\nCalling from constant object:\n";
    obj2.constant();        // Allowed
    // obj2.non_constant(); // ❌ Not Allowed (will give error)

    return 0;
}



// ✅ Task 1
// 🔹 Concept Used:

// const member function

// const object vs non-const object

// Rules of calling functions with const objects

// 🔸 Important Rule:

// A const object can only call const member functions.

// A non-const object can call both const and non-const functions.