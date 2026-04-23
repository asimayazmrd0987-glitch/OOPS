#include "Student.h"

Student::Student(string n, int a) {
    name = n;
    age = a;
}

void Student::display() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}
