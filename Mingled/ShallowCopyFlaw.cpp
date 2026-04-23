#include<iostream>
#include<cstring>
using namespace std;

class hero{
    public:
    int health;
    char *name;

    hero(){
        cout<<"Constructor Called"<<endl;
        // char name [20];
    }
    void print(){
        cout<<"Name: "<<name<<", ";
        cout<<"Health: "<<this->health<<endl;
    }

    void setHealth(int h){
        health = h;
    }

    void setName(const char n[]){
    name =new char [strlen(n) + 1];
    strcpy(name, n);
    }
    ~hero(){
        delete[] name;
        cout<<"== Destructor Called =="<<endl;
    }
};

int main(){
    hero h1;
    h1.setHealth(10);
    h1.setName("Football");
    
    hero h2(h1);
    
    cout<<"== Before =="<<endl;
    h1.print();
    h2.print();// shallow copy happens here;

    h1.name[0]='D';
    cout<<"== After =="<<endl;
    h1.print();
    h2.print();
}