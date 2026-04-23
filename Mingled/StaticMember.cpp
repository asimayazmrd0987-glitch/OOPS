#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int id;    
    // Static members
    static int nextId;      // Auto-increment ID
    static int totalStudents;
    
public:
    Student(string n) : name(n) {
        id = nextId++;
        totalStudents++;
    }    
    ~Student() {
        totalStudents--;
    }    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }    
    // Static methods
    static int getTotalStudents() {
        return totalStudents;
    }    
    static int getNextId() {
        return nextId;
    }
};
// Initialize static members
int Student::nextId = 1000;
int Student::totalStudents = 0;

int main() {
    cout << "Total students: " << Student::getTotalStudents() << endl;  // 0
    
    Student s1("Alice");
    Student s2("Bob");
    Student s3("Carol");
    
    s1.display();   // ID: 1000
    s2.display();   // ID: 1001
    s3.display();   // ID: 1002
    
    cout << "Total: " << Student::getTotalStudents() << endl;  // 3
    cout << "Next ID: " << Student::getNextId() << endl;       // 1003
    
    return 0;
}