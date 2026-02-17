#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    cout << maxValue(5, 9) << endl;
    cout << maxValue(3.2, 7.8) << endl;
}
