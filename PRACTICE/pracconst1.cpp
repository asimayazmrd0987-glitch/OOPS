#include <iostream>
using namespace std;

class student
{
public:
    string name;
    int age;
     student(string n, int a):name(n), age(a){}
    void displayName() const
    {
        cout << name << endl;
    }
    void displayage(int a)
    {
        age = a;
    }
};
int main()
{
    const student s1("Ali", 20);
    s1.displayName();
    // s1.displayage(12);
    return 0;
}