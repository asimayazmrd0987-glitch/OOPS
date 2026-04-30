#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream outfile("open.txt");
    if(!outfile){
        cerr<<"Error: file could not open"<<endl;
        return 1;
    }
    outfile<<"Data is read Successfully"<<endl;
    outfile.close();

    if(outfile.good()){
        outfile<<"That's good"<<endl;
    }
    return 0;
}