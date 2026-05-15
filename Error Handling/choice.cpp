#include<iostream>
using namespace std;

int main(){

    try{
    int choice;
    cout<<"Enter the choice";
    cin>>choice;

    if(choice==1)
    throw 10;
    
    else if(choice==2)
    throw 5.5;

    else
    throw 'A';
    }

    catch(int x){
        cout<<"Integer exception"<<endl;
    }
    catch(double y){
        cout<<"Double exception"<<endl;
    }
    catch(char z){
        cout<<"Character exception"<<endl;
    }
    return 0;
}