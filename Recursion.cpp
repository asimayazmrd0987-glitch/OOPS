#include <iostream>
using namespace std;
#include <iomanip>
using std::setw;
unsigned long factorial(unsigned long); // function prototype
int main()
{
    // Loop 10 times. During each iteration, calculate
    // factorial( i ) and display result.
    for (int i = 0; i <= 10; i++)
        cout << (2) << i << "! = " << factorial(i) << endl;
    return 0; // indicates successful termination

} // end main

// recursive definition of function factorial
unsigned long factorial(unsigned long number)
{
    // base case
    if (number <= 1)
        return 1;
    // recursive step
    else
        return number * factorial(number - 1);

} // end function factorial