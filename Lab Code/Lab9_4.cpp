#include <iostream>
using namespace std;

class father {
protected:
    int age;
public:
    father(int x) {
        age = x;
    }
    virtual void iam() {
        cout << "I am father, my age is " << age << endl;
    }
    virtual ~father() {} 
};

class son : public father {
public:
    son(int x) : father(x) {}
    void iam() override {
        cout << "I am son, my age is " << age << endl;
    }
};

class daughter : public father {
public:
    daughter(int x) : father(x) {}
    void iam() override {
        cout << "I am daughter, my age is " << age << endl;
    }
};

int main() {
    father f(45);
    son s(20);
    daughter d(18);
    cout << "Direct calls:" << endl;
    f.iam();
    s.iam();
    d.iam();
    cout << "\n= Polymorphism using base pointer =:" << endl;
    father* ptr;
    ptr = &s;
    ptr->iam(); 
ptr = &d;
    ptr->iam();   

    return 0;
}