#include<iostream>
using namespace std;

class Animal{
    protected:
    string name;
    int age;
    public:
    Animal(string n, int a):name(n),age(a){}
    void speak(){
        cout<<name <<" Can Speak "<<endl;
    }
    void eat(){
        cout<<name<< " Can Eat "<<endl;
    }
    void getData(){
        cout<<"Name is :"<<name<<endl;
        cout<<"Age is :"<<age<<endl;
    }
};
class Dog : public Animal{
    private:
    string breed;
    public:
        Dog(string n, int a,string b): Animal(n , a), breed(b){}
    void fetch(){
        cout<<name<<" Can Fetch things "<<endl;
    }
};
int main(){
    Dog d("Tazakay",12,"Labrador");
    d.getData();
    d.speak();
    d.eat();
    d.fetch();
    return 0;
}