#include<iostream>
#include<fstream>
#include<stdexcept>
using namespace std;

class FileGuard{
    fstream File_;
    public:
    FileGuard(const string& name):File_(name, ios::in | ios::out | ios::app){
        if(!File_.is_open())
        throw runtime_error("Cannot open:"+ name);
        cout<<"File opened"<<endl;
    }
    ~FileGuard(){
        File_.close();
        cout<<"File closed"<<endl;
    }
};
void processline(){
    throw runtime_error("Bad Format");
}
void parseINI(){
    FileGuard fg("config.ini");
    processline();
}

int main(){
    try{
        parseINI();
    }
    catch(const exception& e){
        cout<<e.what();
    }
}