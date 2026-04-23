#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
using namespace std;

class employee{
    private:
    string name;
    int age;

    public:
    employee(string n,int m);
     void display();
};
#endif