#include <iostream>
using namespace std;

class Pair {
private:
    int a, b;
public:
    Pair(int x = 0, int y = 0) : a(x), b(y) {}
    bool operator<(const Pair& oop) const {
        return (a + b) < (oop.a + oop.b);
    }
    void display() const {
        cout << "(" << a << ", " << b << ")";
    }
};
int main() {
    Pair p1(5, 3), p2(2, 7);

    cout << "p1 = "; p1.display();  cout << ", p2 = "; p2.display();
    cout << endl;

    if (p1 < p2)
        cout << "p1 is less than p2 by addition " << endl;
    else
        cout << "p1 is not less than p2 by addition " << endl;
    return 0;
}
