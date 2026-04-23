#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int* marks;
    
    // Constructor
    Student(string n, int m) {
        name = n;
        marks = new int(m);
        *marks = m;
        cout << "Constructor: " << name << endl;
    }
    
    // COPY CONSTRUCTOR (Deep Copy) ⭐
    Student(const Student& other) {
        name = other.name;
        marks = new int(*other.marks);  // NEW memory, copy value
        cout << "Copy Constructor: " << name << endl;
    }
    
    // COPY ASSIGNMENT OPERATOR (Deep Copy) ⭐
    Student& operator=(const Student& obj) {
        cout << "Copy Assignment: " << obj.name << endl;
        
        // Check self-assignment
        if (this != &obj) {
            // 1. Delete old memory
            delete marks;
            
            // 2. Allocate new memory
            marks = new int(*obj.marks);
            name = obj.name;
        }
        return *this;
    }
    
    // Destructor
    ~Student() {
        cout << "Destructor: " << name << endl;
        delete marks;
    }
};

int main() {
    Student s1("Ali", 85);
    Student s2 = s1;        // Calls COPY CONSTRUCTOR
    
    Student s3("Bob", 90);
    s3 = s1;                // Calls COPY ASSIGNMENT OPERATOR
    
    // Now s1, s2, s3 each have SEPARATE memory
    // No crash, no double delete!
    
    return 0;
}