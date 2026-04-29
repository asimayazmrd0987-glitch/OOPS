#include<iostream>
using namespace std;

#include"01.h"

void display(testing obj){
    obj.a=5;
    obj.b=10;

    cout<<"a is :"<<obj.a<<endl;
    cout<<"b is :"<<obj.b<<endl;
}