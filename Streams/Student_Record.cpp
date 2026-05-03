#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

class Student{
    int id;
    string name;
    double gpa;
    int year;
    public:
    Student(int id_=0, string n="", double gpa_=0.0, int year_=0):id(id_),name(n),gpa(gpa_), year(year_){}

    friend ostream& operator<<(ostream& os, const Student& s){
        return os<<s.id<<" | "<<s.name<<" | "<<s.gpa<<" | "<<s.year;
    }

    friend istream& operator>>(istream& is, Student& s){
        char pipe;
        return is>>s.id>>pipe>>s.name>>pipe>>s.gpa>>pipe>>s.year;
    }

    void print() const{
        cout<<"ID: "<<id<<" Name: "<<name<<" GPA: "<<gpa<<" Year: "<<year<<"\n";
    }
};

int main(){
    vector<Student> student{{1,"Asim",3.6,2},{2,"Tahir",3.2,2},{3,"Ikhtisham",3.60,2}};
    ofstream out("student_Record.txt");
    for(const auto& s: student) out << s <<"\n";

    ifstream in("student_Record.txt");
    Student s;

    while(in>>s) s.print();
}

