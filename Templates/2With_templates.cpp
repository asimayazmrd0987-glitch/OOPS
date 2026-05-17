#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << maximum(23.1, 12.9) << endl;
    cout << maximum(45, 99) << endl;
    cout << maximum("ASIM", "Tahir")<<endl;

    int i = maximum<int>(10,20);   //explicitly
    cout<<i<<endl;

    auto r1= maximum(12 , 13);         //implicitly
    cout<<r1<<endl;

    return 0;
}
