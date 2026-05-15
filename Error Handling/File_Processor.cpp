#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class FileException : public runtime_error {
    string filename_;
public:
    FileException(const string& msg, const string& fn)
        : runtime_error(msg + ": " + fn), filename_(fn) {}
    string filename() const { return filename_; }
};

class ParseException : public runtime_error {
    int lineNum_;
public:
    ParseException(const string& msg, int line)
        : runtime_error("Line " + to_string(line) + ": " + msg), lineNum_(line) {}
    int lineNumber() const { return lineNum_; }
};

struct Record { string name; int age; double salary; };

vector<Record> loadCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open())
        throw FileException("Cannot open file", filename);

    vector<Record> records;
    string line;
    int lineNum = 0;

    while (getline(file, line)) {
        ++lineNum;
        if (line.empty() || line[0] == '#') continue;   // skip comments

        istringstream ss(line);
        Record r;
        string ageStr, salStr;

        if (!getline(ss, r.name,  ',') ||
            !getline(ss, ageStr,  ',') ||
            !getline(ss, salStr,  ','))
            throw ParseException("Expected 3 columns", lineNum);

        try {
            r.age    = stoi(ageStr);
            r.salary = stod(salStr);
        } catch (const invalid_argument&) {
            throw ParseException("Non-numeric age or salary", lineNum);
        } catch (const out_of_range&) {
            throw ParseException("Value too large", lineNum);
        }

        if (r.age < 18 || r.age > 100)
            throw ParseException("Age " + ageStr + " out of [18,100]", lineNum);
        if (r.salary < 0)
            throw ParseException("Negative salary", lineNum);

        records.push_back(r);
    }
    return records;
}

int main() {
    try {
        auto records = loadCSV("employees.csv");
        cout << "Loaded " << records.size() << " records.\n";
        for (auto& r : records)
            cout << r.name << ", age " << r.age << ", $" << r.salary << "\n";
    }
    catch (const FileException&  e) { cerr << "[FILE]  " << e.what() << "\n"; }
    catch (const ParseException& e) { cerr << "[PARSE] " << e.what() << "\n"; }
    catch (const exception&      e) { cerr << "[ERROR] " << e.what() << "\n"; }
}