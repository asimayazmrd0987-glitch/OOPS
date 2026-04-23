#include <iostream>
using namespace std;

class Counter
{
public:
    int count;
    Counter(int c = 0) : count(c) {}
    // Prefix ++c  (no argument)
    Counter operator++()
    {
        // count++;
        return Counter(++count);
    }
    // Postfix c++  (dummy int argument tells C++ it's postfix)
    Counter operator++(int)
    {
        // Counter temp = *this;  // save old value
        // count++;
        return Counter(count++); // return old value
    }
    void display()
    {
        cout << count << endl;
    }
};
int main()
{
    Counter c1(5);
    Counter c2;
    ++c1; // count = 6
    c2 = ++c1;
    c1++; // count = 7
    c2.display();
    c1.display();
}
// ## The Rules — What You Can & Can't Do

// | ✅ Can do | ❌ Can't do |
// |---|---|
// | Change what the operator *does* | Change the number of operands |
// | Use almost any operator | Create brand new operators (e.g. `**`) |
// | Overload for your own classes | Overload for built-in types (`int`, `float`) |
// | — | Overload `::` `.` `.*` `?:` |

// ## Quick Cheat Sheet
// ```
// operator+     →  a + b
// operator-     →  a - b
// operator*     →  a * b
// operator/     →  a / b
// operator==    →  a == b
// operator!=    →  a != b
// operator<     →  a < b
// operator>     →  a > b
// operator++    →  ++a  or  a++
// operator--    →  --a  or  a--
// operator<<    →  cout << a
// operator>>    →  cin >> a
// operator[]    →  a[i]
// operator=     →  a = b  (assignment)