#include<iostream>
using namespace std;

class A{
    public:
    void show(){
        cout<<"Class A "<<endl;
    }
};
class B{
    public:
    void show(){
        cout<<"Class B "<<endl;
    }
};
class C:public A, public B{};
int main(){
    C obj;
    obj.A::show();// It outs Class A
    obj.B::show();// It outs Class B
}
// By using scope resolution(::) the ambiguity is cleared 