#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    Counter(int v = 0):value(v){}

    Counter& operator++() {
        ++value;
        return *this;
    }
    Counter operator++(int) {
        Counter temp = *this;  
        ++(*this);             
        return temp;           
    }
    Counter& operator--() {
        --value;
        return *this;
    }
    Counter operator--(int) {
        Counter temp = *this;
        --(*this);
        return temp;
    }
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c(5);

    cout << "Initial: ";
    c.display();

    ++c;
    cout << "After ++c we will get : ";
    c.display();

    c++;
    cout << "After c++ we will get : ";
    c.display();

    --c;
    cout << "After --c we will get : ";
    c.display();

    c--;
    cout << "After c-- we will get : ";
    c.display();
    return 0;
}