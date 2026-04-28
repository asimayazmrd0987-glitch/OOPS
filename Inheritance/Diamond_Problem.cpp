#include<iostream>
using namespace std;

class A{
    public:
    void show(){
        cout<<"Hi!! i am here"<<endl;
    }
};
class B:public A{};
class C:public A{};
class D:public B, public C{};

int main(){
    D obj;
    // obj.show(); it won't compile bcz it has ambiguity
}