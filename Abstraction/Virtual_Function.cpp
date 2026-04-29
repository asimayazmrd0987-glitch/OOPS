#include<iostream>
using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout<<"Animal Sound"<<endl;
    }
};
class Dog: public Animal{
    void speak() override{
        cout<<"Woof"<<endl;
    }
};
class cat: public Dog{
    void speak() override{
        cout<<"Meow \n"<<endl;
    }
};
int main(){
    Animal* animal[3];
    animal[0] = new Animal();
    animal[1] = new Dog();
    animal[2] = new cat();
    
    for(int i=0; i<3; i++){
    animal[i]->speak();();// Calls correct version at RUNTIME!
 //same call syntax, different behavior — “polymorphic call”

    }
}