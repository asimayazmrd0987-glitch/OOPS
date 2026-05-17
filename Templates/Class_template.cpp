#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
    T1 first;
    T2 second;

public:
    Pair(T1 t, T2 p) : first(t), second(p) {}
    T1 getfirst() const
    {
        return first;
    }
    T2 getsecond() const
    {
        return second;
    }
};

int main()
{
    Pair<string, int> student("Ali", 20);
    cout << student.getfirst() << " is " << student.getsecond() << " years old" << endl;

    Pair<double, double> point(12.3, -10.3);
    cout<< point.getfirst() << ", "<<point.getsecond() <<endl;
}