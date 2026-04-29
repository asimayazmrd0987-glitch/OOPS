#include <iostream>
using namespace std;
class Counter {
public:
    virtual void click() = 0;     
    virtual int get() const = 0;  
    virtual void set(int val) = 0;
    virtual ~Counter() {}
};
class MyCounter : public Counter {
private:
    int count;
public:
    MyCounter() : count(0) {}
    void click() override {
        ++count;
    }
    int get() const override {
        return count;
    }
    void set(int val) override {
        count = val;
    }
};
int main() {
    MyCounter c;
    Counter* ptr = &c;         
ptr->set(10);
    cout << "Initial value: " << ptr->get() << endl;
 ptr->click();
    ptr->click();
    cout << "After two clicks: " << ptr->get() << endl;
     return 0;
}