#include<iostream>
#include<string>
#include <fstream>
#include <vector>
using namespace std;

class Student {
    int id;
    string name;
    double gpa;
    int year;

public:
    Student(int id_=0, string n="", double gpa_=0.0, int year_=0)
        : id(id_), name(n), gpa(gpa_), year(year_) {}

    friend ostream& operator<<(ostream& os, const Student& s){
        return os << s.id << "|" << s.name << "|" << s.gpa << "|" << s.year;
    }

    friend istream& operator>>(istream& is, Student& s){
        char pipe;
        return is >> s.id >> pipe >> s.name >> pipe >> s.gpa >> pipe >> s.year;
    }
};

void saveAll(const vector<Student>& v, const string& fname) {
    ofstream out(fname);
    if (!out) throw runtime_error("Cannot open: " + fname);
    for (const auto& s : v) out << s << "\n";
}

vector<Student> loadAll(const string& fname) {
    ifstream in(fname);
    if (!in) throw runtime_error("Cannot open: " + fname);
    
    vector<Student> result;
    Student s;
    while (in >> s) {   
        result.push_back(s);
    }
        if (!in.eof()) throw runtime_error("Bad record in file");
    
    return result;
}

void appendStudent(const Student& s, const string& fname) {
    ofstream out(fname, ios::app);  // True append, no rewrite!
    if (!out) throw runtime_error("Cannot open: " + fname);
    out << s << "\n";
}
int main(){
    vector<Student> roster{{101,"Ali",3.8,2}, 
                           {102,"Sara",3.9,3}};
    saveAll(roster, "roster.txt");

    appendStudent({103,"Zain",3.5,4}, "roster.txt");

    auto loaded = loadAll("roster.txt");
    for (const auto& s : loaded) cout << s << "\n";
    
}
