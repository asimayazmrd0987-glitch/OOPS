#include<iostream>
using namespace std;

class A{
    private: int pria;
    protected: int prob;
    public: int pubc;
};
class B: public A{
    public: 
    void func(){
        int a
        a=pria;
        a=prob;
        a=pubc;
    }
};
class C: private B{
    public: 
    int a;
    a=pria;
    a=prob;
    a=pubc;
};

int main(){
    int a;
    B obj;
    a=obj.prob;   //not okay
    a=b=obj.pubc; // okay
}
