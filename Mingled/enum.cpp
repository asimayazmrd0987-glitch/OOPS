#include <iostream>
using namespace std;

enum daysofweek{Mon,Tue,Thu,Fri,Sat,Sun};

int main(){
    daysofweek day1, day2;
    day1=Mon;
    day2=Sun;
    int diff= day2 - day1;
    cout<<"Diff is :"<<diff<<endl;
    if (day1<day2)
    {
        cout<<day2<<endl;
    }
    return 0;
}
//It is a user-defined data type used to assign names to constant integer values.