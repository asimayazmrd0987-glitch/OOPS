#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<" Base Class "<<endl;
    }
};
class Derived: public Base{
    public:
    Derived(): Base(){
        cout<<" Derived Class "<<endl;
    }
};

int main(){
    Derived obj;
}
// the base class constructor is triggered first and then
// the derived class constructor is called.