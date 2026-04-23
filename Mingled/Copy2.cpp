#include <iostream>
using namespace std;

class test
{
public:
    int a;
    int f;
    test(int x)
    {
        x = a;
    }
    test(const test &t)
    {
        cout << " == Test Copy is Called == " << endl;
        a = t.a;
    }
};
void display(test &t)
{
    cout << t.a << endl;
    cout << t.f << endl;
}

int main()
{
    test t1(23);
    test t2 = t1;

    // cout<<t2.a<<endl;   //address of integer a
    display(t1);
}
