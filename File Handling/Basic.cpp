#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream outFile("Data.txt");

    outFile <<"Hello Viewers"<<endl;
    outFile<<"Here in my coding you will learn a lot of things"<<endl;
    outFile<<"Stay Tune"<<endl;

    outFile.close();
    
    cout<<"file written Successfully "<<endl;

    return 0;
}