#include <iostream>
using namespace std;

class Sample {
public:
    static int value;// This is declaration
};

int Sample::value = 100;// via scope esolution

int main() {
    cout << Sample::value << endl;

    Sample::value = 200;// i update it

    cout << Sample::value << endl;
}

