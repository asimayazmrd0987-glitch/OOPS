#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    ofstream fout("report.txt");
    fout<<"=== Sales Report ==="<<endl;
    fout<<"Date:29/04/2026"<<endl;

    fout<<left<<setw(15)<<"Product"
    <<right <<setw(8)<<"Price"
    <<right<<setw(5)<<"Qty"
    <<"\n";
    fout<<string(30,'-')<<"\n";

    fout<<left<<setw(15)<<"Laptop"
    <<right<<setw(8)<<fixed<<setprecision(2)<<75000
    <<right<<setw(5)<<5;

    //ofstream app("log.txt", ios::app);
    fout.close();
    cout<<"Report is ready"<<endl;
    return 0;

}