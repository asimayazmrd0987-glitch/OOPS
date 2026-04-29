#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Contact {
private:
    string name;
    string phone;

public:
    Contact(const string& n, const string& p) : name(n), phone(p) {}

    void display() const {
        cout << left  << setw(20) << name
             << right << setw(15) << phone
             << "\n";
    }

    static void printHeader() {
        cout << "\n";
        cout << left  << setw(20) << "Name"
             << right << setw(15) << "Telephone No."
             << "\n";
        cout << string(35, '-') << "\n";
    }
};

int main() {
    ifstream file("contacts.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open contacts.txt\n";
        return 1;
    }

    vector<Contact> contacts;
    string name, phone;

    while (file >> name >> phone) {
        contacts.emplace_back(name, phone);
    }

    file.close();

    Contact::printHeader();
    for (const Contact& c : contacts) {
        c.display();
    }

    cout << string(35, '-') << "\n\n";
    return 0;
}