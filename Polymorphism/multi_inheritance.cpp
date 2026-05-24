#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string n) : name(n) {
        cout << "Person constructor: " << name << endl;
    }
};

// 'virtual' inheritance prevents duplicate Person base
class Student : virtual public Person {
public:
    Student(string n) : Person(n) {
        cout << "Student constructor" << endl;
    }
};

class Employee : virtual public Person {
public:
    Employee(string n) : Person(n) {
        cout << "Employee constructor" << endl;
    }
};

// Without 'virtual' above, this would have TWO Person copies
class WorkingStudent : public Student, public Employee {
public:
    // Must initialize Person directly when using virtual inheritance
    WorkingStudent(string n) : Person(n), Student(n), Employee(n) {
        cout << "WorkingStudent constructor" << endl;
    }
};

int main() {
    WorkingStudent ws("Alice");
    
    // Without virtual inheritance, ws.name would be ambiguous
    cout << "Name: " << ws.name << endl; // Works perfectly
    
    return 0;
}