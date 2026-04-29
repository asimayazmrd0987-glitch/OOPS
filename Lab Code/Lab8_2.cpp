#include <iostream>
using namespace std;

class base
{
protected:
    int a, b, c, d;
    public : 
    base(){
        a=b=c=d=0;
        cout<<"I am the constructor of base class"<<endl;
    }
    base(int x){
        a=x; b=c=d=0;
        cout<<"I am the 1 argument constructor of base class, a ="<<a<<endl;

    }
    base(int z, int r){
        a=z,b=r; c=d=0;
    cout<<"I am the 2 argument constructor of base class a ="<<a<<" b ="<<b<<endl;

    }
    void display()
    {
        cout << "== I am Base class display function ==" << endl;
        cout<<"Values are a ="<<a<<" b ="<<b<<" c ="<<c<<" d ="<<d<<endl;
    }
    ~base(){
        cout<<"Base destructor called"<<endl;

    }
};

class derived : public base
{
    public:
    derived(): base(){
    cout<<"== Derived default constructor called =="<<endl;
    }
    derived(int x):base(x){
       cout << "Derived one-argument constructor called." << endl;
    }
    derived(int x, int y):base(x,y){
        cout << "Derived two-argument constructor called." << endl;
    }
    ~derived(){
        cout << "== Derived destructor called ==" << endl;
    }
};
int main(){
    derived obj;// constructor
    obj.display();

    derived obj2(10);
    obj2.display();

    derived obj3(20,30);
    obj3.display();

    return 0;
}