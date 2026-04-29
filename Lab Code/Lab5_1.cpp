#include <iostream>
using namespace std;

class Test {
private:
    static int objectCount;

public:
    Test() {
        objectCount++;
    }

    static void showCount() {
        cout << "Objects created = " << objectCount << endl;
    }
};

int Test::objectCount = 0;

int main() {
    Test a1, a2, a3,s2;

    Test::showCount();
}
