#include <iostream>
using namespace std;

inline int square(int x) { //👉 inline is only a request to compiler
    return x * x;          //👉 Compiler may ignore it
}

int main() {
    cout << square(5) << endl;    //direct 5*5
    cout << square(10) << endl;   //direct 10*10
}
/*    When To Use 
✔ Small functions
✔ Frequently called functions
✔ Simple logic */