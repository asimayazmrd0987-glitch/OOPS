#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3};
    int *p=arr;
    cout<<*p++<<endl;
    cout<<*++p<<endl;// see copy.cpp program
   return 0;
}
