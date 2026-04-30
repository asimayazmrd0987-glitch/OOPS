#include<iostream>
#include<fstream>
using namespace std;

struct Employee
{
    char name[40];
    float salary;
    int id;
    int department;
};

void writeEmployee(const Employee& emp, const string& filename){
    ofstream fileout(filename, ios::binary | ios::app);
    if(!fileout){cerr<<"Error: File not opened"; return ;}
    fileout.write(reinterpret_cast<const char*>(&emp),sizeof(Employee));
    cout<<"Employee"<<emp.name<<"saved .\n";
}

void readAllEmployee(const string& filename){
    ifstream fin(filename, ios::binary);
    if(!fin){cerr<<"File not opened !!";return;}

Employee emp;
int count=0;
while(fin.read(reinterpret_cast< char*>(&emp),sizeof(Employee))){
    cout<<"ID: "<<emp.id
    <<" Name: "<<emp.name
    <<" Department: "<<emp.department
    <<" Salary: "<<emp.salary<<endl;
    count++;
}
cout<<count<<"Record read "<<endl;}

int main(){
    Employee e1={"Asim" ,120001.0f, 12, 3,};
    Employee e2={"Tahir", 220001.0f, 13, 2};

    writeEmployee(e1,"employees.bin");
    writeEmployee(e2,"employees.bin");

    cout<<string(30,'-')<<endl;

    readAllEmployee("employees.bin");
}