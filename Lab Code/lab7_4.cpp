#include <iostream>
using namespace std;
class Test {
private:
    int num;
public:
    void setValue(int n) {
        num = n;
    }
    friend int add(Test t1, Test t2);
};
int add(Test t1, Test t2) {
    return t1.num + t2.num;
}
int main() {
    Test t1, t2;
    t1.setValue(10);
    t2.setValue(20);
    cout << "Sum = " << add(t1, t2)<<endl;
    return 0;
}