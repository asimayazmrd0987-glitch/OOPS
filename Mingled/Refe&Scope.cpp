#include<iostream>
using namespace std;

int& fun(){
    int x = 12;
    return x;
}
int main(){
    int& ref = fun();
    cout<< ref <<endl; // here x is dead because fun() is ended
    return 0;
}
