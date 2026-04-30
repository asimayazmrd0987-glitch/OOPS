#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ofstream file1("overwrite.txt");
    file1<<"Have you watched Attack On Titans anime!!"<<endl;  // This REPLACES everything
    file1.close();

    ofstream file2("Append.txt", ios::app);
    file2<<"I like to help others"<<endl;  // This ADDS to the end
    file2.close();
    
    ofstream file3;
    file3.open("app.txt",ios::app);
    file3<<"Sorry for bothering "<<__TIME__<<endl;
    file3.close();

    cout<<"Success"<<endl;
    return 0;
}