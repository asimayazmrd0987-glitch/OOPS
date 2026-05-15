#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// ─── Domain exceptions ─────────────────────────────────────────────────
class StudentException     : public runtime_error {
    string studentId_;
public:
    StudentException(const string& msg, const string& id)
        : runtime_error(msg), studentId_(id) {}
    string studentId() const { return studentId_; }
};
class InvalidGradeException: public StudentException {
    double grade_;
public:
    InvalidGradeException(double g, const string& id)
        : StudentException("Grade " + to_string(g) +
                           " out of [0,100] for " + id, id), grade_(g) {}
    double grade() const { return grade_; }
};
class StudentNotFoundException : public StudentException {
public:
    StudentNotFoundException(const string& id)
        : StudentException("Student not found: " + id, id) {}
};

// ─── Student record ─────────────────────────────────────────────────────
struct Student {
    string id, name;
    vector<double> grades;

    void addGrade(double g) {
        if (g < 0 || g > 100)
            throw InvalidGradeException(g, id);
        grades.push_back(g);
    }
    double average() const {
        if (grades.empty())
            throw StudentException("No grades for " + id, id);
        double sum = 0;
        for (double g : grades) sum += g;
        return sum / grades.size();
    }
};

// ─── Grade book ─────────────────────────────────────────────────────────
class GradeBook {
    vector<Student> students_;
public:
    void addStudent(Student s) { students_.push_back(s); }

    Student& findStudent(const string& id) {
        for (auto& s : students_)
            if (s.id == id) return s;
        throw StudentNotFoundException(id);
    }
    void printReport() {
        for (auto& s : students_) {
            try {
                cout << s.name << " (" << s.id << "): avg = "
                     << s.average() << endl;
            } catch (const StudentException& e) {
                cout << "[WARN] " << e.what() << endl;   // partial failure OK
            }
        }
    }
};

int main() {
    GradeBook gb;
    gb.addStudent({"S001","Ali",{}});
    gb.addStudent({"S002","Sara",{}});

    try {
        gb.findStudent("S001").addGrade(85);
        gb.findStudent("S001").addGrade(92);
        gb.findStudent("S001").addGrade(110);  // throws InvalidGradeException
    }
    catch (const InvalidGradeException& e) {
        cerr << "Invalid grade " << e.grade() << " for " << e.studentId() << endl;
    }
    try { gb.findStudent("S999"); }             // throws StudentNotFoundException
    catch (const StudentNotFoundException& e) {
        cerr << "Lookup failed: " << e.what() << endl;
    }
    gb.printReport();
}
