#include<iostream>
using namespace std;

class A{
    private: int a;
    protected: int b;
    public: int c;
};
class B: public A{
    public: int d;
};

int main(){
    B obj;
    obj.c; // c and d can be accessed bcz these are public 
    obj.d;
    // obj.a; these cannot be accessed by the object of the derived class(obj), because these are protected 
    // obj.b; and private
}