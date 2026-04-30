#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    ofstream ffile("input.txt",ios::app);
    if(!ffile){
        cerr<<"Error: File could not open"<<endl;
        return 1;
    }

    string name;
    int age;
    char choice ='y';
    while(choice=='Y' || choice=='y'){
        cout<<"Enter name: ";
        getline(cin,name);

        cout<<"Enter age :";
        cin>>age;

        ffile<<"Name :"<<name<<setw(15)<<" Age :"<<age<<setw(8)<<endl;

        cout<<"enter choice (y/n)";
        cin>>choice;
    }
    ffile.close();
    cout<<"Done!!";
    return 0;
}