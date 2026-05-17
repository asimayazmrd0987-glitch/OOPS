#include <iostream>
#include <string>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

double length(double a, double b)
{
    return a + b;
}

string nax(string a, string b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << max(6, 2) << endl;

    cout << length(12.1, 2.8) << endl;

    cout << nax("Asim", "Ali") << endl;

    return 0;
}

