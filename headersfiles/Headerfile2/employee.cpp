#include"employee.h"

employee::employee(string n,int m){
    name = n;
    age = m;

}
void employee:: display(){
    cout<<"Age is = "<<age<<endl;
    cout<<"Name is = "<<name<<endl;
}