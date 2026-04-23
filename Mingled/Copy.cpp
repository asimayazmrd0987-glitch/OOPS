#include <iostream>
using namespace std;

class Student
{
public:
    int age;

    // Normal constructor
    Student(int x)
    {
        age = x;
        cout<<"Call Constructor"<<endl;
    }
   // Copy constructor
    Student(const Student &f)// we use the reference &, to avoid infinite recursion/ extra copy
    {                        //const is used to avoid modification of original object
        age = f.age;          
        cout<<"Copy constructor called "<<endl;
    }
};

int main()
{
    Student s1(20);  // Normal object
    Student s2 = s1; // Copy constructor called

    cout << "Age = "<< s2.age<<endl;
    int z=4;
    cout<<z++<<endl;//first z is printed 4 and then is incremented, becomes 5
    cout<<++z<<endl;// here that 5 is now incremented ->6 and then print

    return 0;
}
