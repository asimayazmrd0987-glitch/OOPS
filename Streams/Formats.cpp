#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    double pi = 3.14562;
    cout << fixed << setprecision(4) << pi << endl;
    cout << scientific << setprecision(2) << pi << "\n";
    cout << defaultfloat << pi << "\n";
    cout<<hexfloat << pi <<"\n";

    cout<<setw(12)<<left<<pi<<"\n";
    cout<<setw(12)<<right<<pi<<"\n";
    cout<<setw(15)<<right<<pi<<"\n";
    cout<<setw(12)<<right<<pi<<"\n";
    cout<<setw(12)<<left<<pi<<"\n";


    return 0;
}