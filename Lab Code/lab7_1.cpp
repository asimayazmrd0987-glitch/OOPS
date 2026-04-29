#include<iostream>
using namespace std;    

class testing{
    private:
    int a,b;
    public:

 friend void display(testing);

};
void display(testing obj){
    obj.a=5;
    obj.b=10;

    cout<<"a is :"<<obj.a<<endl;
    cout<<"b is :"<<obj.b<<endl;}
int main(){
    testing obj;
    display(obj);

    return 0;
}