#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student { int id; char name[50]; float gpa; bool active; };
const string DB = "students.db";

// CREATE — add student
void addStudent(const Student& s) {
    ofstream f(DB, ios::binary|ios::app);
    f.write((char*)&s, sizeof(s));
}

// READ — find by id  (O(n) scan)
bool findStudent(int id, Student& out) {
    ifstream f(DB, ios::binary);
    Student s;
    while (f.read((char*)&s, sizeof(s)))
        if (s.id==id && s.active) { out=s; return true; }
    return false;
}

// UPDATE — update GPA (direct seek)
bool updateGPA(int id, float newGPA) {
    fstream f(DB, ios::binary|ios::in|ios::out);
    Student s; streampos p;
    while ((p=f.tellg()), f.read((char*)&s, sizeof(s)))
        if (s.id==id) { s.gpa=newGPA; f.seekp(p); f.write((char*)&s,sizeof(s)); return true; }
    return false;
}

// DELETE — soft delete (mark active=false)
bool deleteStudent(int id) {
    fstream f(DB, ios::binary|ios::in|ios::out);
    Student s; streampos p;
    while ((p=f.tellg()), f.read((char*)&s, sizeof(s)))
        if (s.id==id) { s.active=false; f.seekp(p); f.write((char*)&s,sizeof(s)); return true; }
    return false;
}

// LIST — all active students
void listStudents() {
    ifstream f(DB, ios::binary); Student s; int n=0;
    cout << "\nID   Name         GPA\n" << string(35,'-') << "\n";
    while (f.read((char*)&s, sizeof(s)))
      if (s.active) {printf("%-5d %-24s %.2f\n", s.id, s.name,s.gpa); n++; }
    cout << n << " student(s) found.\n";
}

int main() {
    addStudent({1,"Ali Khan",3.8f,true});
    addStudent({2,"Sara Baig",3.9f,true});
    addStudent({3,"Zain Mir",3.5f,true});
    listStudents();
    updateGPA(2, 3.95f);   cout << "Updated Sara's GPA.\n";
    deleteStudent(3);       cout << "Deleted Zain.\n";
    listStudents();
}
