#include <iostream>
using namespace std;

class Calculator {
public:
    // Overloaded add() methods
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
    
    string add(string a, string b) {
        return a + b;
    }
};

int main() {
    Calculator calc;
    // cout << fixed << setprecision(2);
    cout << calc.add(5, 10) << endl;           // int
    cout << calc.add(2.5, 3.5) << endl;        // double
    cout << calc.add(1, 2, 3) << endl;         // 3 args
    cout << calc.add("Hello", "World") << endl; // string
    
    return 0;
}