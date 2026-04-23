#include<iostream>
using namespace std;
class Student {
public:
    int marks;
    Student(int m) : marks(m) {}

    bool operator==(const Student& s) {
        return marks == s.marks;
    }

    bool operator<(const Student& s) {
        return marks < s.marks;
    }
};

int main() {
    Student s1(80), s2(80), s3(90);

    cout << (s1 == s2)<<endl;  // 1 (true)  ✅
    cout << (s1 == s3)<<endl;  // 0 (false) ✅
    cout << (s1 < s3)<<endl;   // 1 (true)  ✅
}
