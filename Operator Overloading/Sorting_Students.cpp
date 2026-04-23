#include <iostream>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    int roll;
    float gpa;
public:
    Student(string n, int r, float g) : name(n), roll(r), gpa(g) {}

    // Overload < to compare by GPA
    bool operator<(const Student& other) const {
        return gpa < other.gpa;   // smaller GPA considered "less"
    }

    void display() const {
        cout << name << " (Roll: " << roll << ", GPA: " << gpa << ")" << endl;
    }
};

int main() {
    Student students[] = {
        Student("Ali", 101, 3.5),
        Student("Sara", 102, 3.9),
        Student("Zain", 103, 3.2)
    };

    // Sort using built-in sort (which uses operator<)
    sort(students, students + 3);

    cout << "Students sorted by GPA:" << endl;
    for (int i = 0; i < 3; i++)
        students[i].display();
    return 0;
}