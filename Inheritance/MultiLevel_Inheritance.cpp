#include<iostream>
using namespace std;

class LivingBeing{
    public:
    void Breath(){
        cout<<"Breath"<<endl;
    }
};
class Animal:public LivingBeing{
    public:
    void eat(){
        cout<<"Eat"<<endl;
    }
    void move(){
        cout<<"Move"<<endl;
    }
};
class Mammals:public Animal{
    public:
    nurseYoung(){
        cout<<"Young Nurse"<<endl;
    }
};
class Dog:public Mammals{
    public:
    void fetch(){
        cout<<"Fetch"<<endl;
    }
};
int main(){
    Dog d;
    d.Breath();
    d.eat();
    d.fetch();
    d.move();
    d.nurseYoung();
    return 0;
}
// Dog inherits ALL methods:
// breathe(), eat(), move(),
// nurseYoung(), bark(), fetch()