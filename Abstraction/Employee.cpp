#include<iostream>
using namespace std;
const int LEN=80;

class employee{
    private:
    char name[LEN];
    unsigned int number;
    public:
    void getdata(){
        cout<<"Enter name :";cin.get(name,LEN);cin.ignore();
        cout<<"Enter number :";cin>>number;
    }
    void putdata() const{
        cout<<"\n Name of Employee is :"<<name<<endl;
        cout<<"\n Number of employee is :"<<number<<endl; 
    }
};
class manager: private employee{
    private:
    char title[LEN];
    int dues;
    public:
    void getdata(){
        employee::getdata();
        cout<<"Enter title for manager :";cin.get(title,LEN);cin.ignore();
        cout<<"Enter dues of manager :";cin>>dues;cin.ignore();
    }
    void putdata() const{
        employee::putdata();
        cout<<"\n Title of manger is :"<<title<<endl;
        cout<<"\n Dues of manger is :"<<dues<<endl;
    }
};
class scientist:private employee{
    private:
    int pubs;
    public:
    void getdata(){
        employee::getdata();
        cout<<"Enter the publication :";cin>>pubs;
    }
    void putdata() const{
        employee::putdata();
        cout<<"\n Total Publications are :"<<pubs<<endl;
    }
};
class labour:private employee{
    public:
    // Fix: provide public wrappers
    void getdata() {
        employee::getdata();
    }
    void putdata() const {
        employee::putdata();
    }
};
 
int main(){
    // employee l;
    manager m;
    scientist s;
    labour e;
    m.getdata();
    s.getdata();
    e.getdata();

    m.putdata();
    s.putdata();
    e.putdata();
    return 0;
}//Fix the bug in it