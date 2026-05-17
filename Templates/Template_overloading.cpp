#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxVal(T a, T b)
{ // generic template
    cout << "[template] ";
    return (a > b) ? a : b;
}

// Non-template overload for const char*
const char *maxVal(const char *a, const char *b)
{
    cout << "[non-template] ";
    return (strcmp(a, b) > 0) ? a : b; // compare strings correctly!
}

// Template overload for pointer types
template <typename T>
T *maxVal(T *a, T *b)
{
    cout << "[pointer template] ";
    return (*a > *b) ? a : b;
}

int main()
{
    cout << maxVal(3, 5) << "\n";             // uses generic template (T=int)
    cout << maxVal(3.14, 2.72) << "\n";       // uses generic template (T=double)
    cout << maxVal("apple", "mango") << "\n"; // uses const char* non-template!
    int x = 10, y = 20;
    cout << *maxVal(&x, &y) << "\n"; // uses pointer template
}

// Overload Resolution Priority:
// 1. Non-template exact match
// 2. Template specialization exact match
// 3. Template with deduction
