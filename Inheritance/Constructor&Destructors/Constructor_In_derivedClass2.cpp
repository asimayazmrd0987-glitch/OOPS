#include<iostream>
using namespace std;

class Base{
    protected:
    int count;
    public:
    Base(): count(0){}
    Base(int c):count(c){}
    unsigned int getCount() const{
        return count;
    }
    Base operator ++(){
    return Base(++count);
    }
};
class Derived: public Base{
    protected:
    int member;
    public:
    Derived():Base(),member(0){}
    Derived(int m):Base(m),member(m){}
    Derived operator --(){
        return Derived(--count);
    }
};
int main(){
    Derived obj;
    Derived obj2;
    cout<<obj.getCount()<<endl;
    cout<<obj2.getCount()<<endl;
    ++obj; ++obj; ++obj;
    cout<<obj.getCount()<<endl;
    --obj;
    cout<<obj.getCount()<<endl;
}