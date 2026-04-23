#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int* marks;  // POINTER to dynamic memory
    
    // Constructor
    Student(string n, int m) {
        name = n;
        marks = new int(m);  // Allocate memory
        *marks = m;
        cout << name << " created with marks: " << *marks << endl;
    }
    
    // NO copy constructor → C++ makes SHALLOW copy!
    
    // Destructor
    ~Student() {
        cout << name << " destroyed, freeing " << *marks << endl;
        delete marks;  // Free memory
    }
};

int main() {
    Student s1("Ali", 85);
    Student s2 = s1;  // SHALLOW COPY! Both point to same memory!
    
    cout << "s1 marks: " << *s1.marks << endl;
    cout << "s2 marks: " << *s2.marks << endl;
    
    // When main() ends:
    // 1. s2 destructor runs → deletes memory
    // 2. s1 destructor runs → tries to delete SAME memory again!
    // 💥 CRASH: Double free error!
    
    return 0;
}