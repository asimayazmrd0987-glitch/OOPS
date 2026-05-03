#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
    ifstream file("Data.txt"); //mere reads
    int n;
    file>>n;
    // file<<"HI";

    if(file.good())  cout<<"ok: "<<n<<"\n";
    if(file.bad())   cout<<"Hardware Error "<<"\n";
    if(file.eof())   cout<<"File is ended"<<"\n";
    if(file.fail())  cout<<"Fatal Error"<<"\n";

    if(!file)   cout<<"File not opening"<<"\n";
    if(file)    cout<<"OKAY!!"<<"\n";

    return 0;
}