#include<iostream>
using namespace std;

int main(){

    int a, b;
    cout<<"Enter value for a & b"; cin>>a>>b;
    try{
        if(b==0)
        throw b;
        cout<<"Result ="<<a/b<<endl;
    }
    catch(int x){
        cout<<"Division by zero is not allowed it's infinity bro !!"<<endl;
    }
    return 0;
}
