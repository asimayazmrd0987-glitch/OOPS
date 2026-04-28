#include<iostream>
using namespace std;

class Animal
{
private:
    string name;
public:
    Animal(string n):name(n){
        cout<<"Animal built :"<<name<<endl;
    }
    ~Animal(){
        cout<<"Animal destroyed :"<<name<<endl;
    }
};

class Dog : public Animal{
    string breed;
    public:
    Dog(string n, string b):Animal(n),breed (b){
        cout<<"Dog built"<<endl;
    }
    ~Dog(){
        cout<<"Dog Destroyed "<<endl;
    }
};
int main(){
    Dog d1("Rad", "Labrador");
    return 0;
}
