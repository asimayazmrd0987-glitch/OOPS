#include<iostream>
#include<cstring>
using namespace std;

class hero{
    public:
    int health;
    char *name;

    hero operator=(const hero &d){
        if(this !=&d){
        delete name;
        name= new char(*(d.name));
    }
        return *this;
      
    }
    void print(){
        cout<<"Name: "<<this->name<<", ";
        cout<<"Health: "<<this->health<<endl;
    }

    void setHealth(int h){
        health = h;
    }

    void setName(const char n[]){
    name =new char [strlen(n) + 1];
    strcpy(name, n);
    }
};

int main(){
    hero h1;
    h1.setHealth(10);
    h1.setName("Sam");
    h1.print();
    
    hero h2(h1);
    h1.print();

}