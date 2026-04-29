#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Contact {
public:
    string name;
    string phone;

    Contact() {}
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
vector<Contact> loadContacts() {
    vector<Contact> contacts;
    ifstream file("contacts.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not open contacts.txt\n";
        return contacts;
    }

    string name, phone;
    while (file >> name >> phone) {
        contacts.emplace_back(name, phone);
    }

    file.close();
    return contacts;
}
void saveContacts(const vector<Contact>& contacts) {
    ofstream file("contacts.txt");

    if (!file.is_open()) {
        cerr << "Error: Could not write to contacts.txt\n";
        return;
    }

    for (const Contact& c : contacts) {
        file << c.name << " " << c.phone << "\n";
    }

    file.close();
}
void findPhone(const vector<Contact>& contacts) {
    string target;
    cout << "\nEnter name to search: ";
    cin >> target;

    bool found = false;
    for (const Contact& c : contacts) {
        if (c.name == target) {
            cout << "\nPhone number of " << c.name << ": " << c.phone << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nNo contact found with name: " << target << "\n";
}
void findName(const vector<Contact>& contacts) {
    string target;
    cout << "\nEnter telephone number to search: ";
    cin >> target;

    bool found = false;
    for (const Contact& c : contacts) {
        if (c.phone == target) {
            cout << "\nName for " << c.phone << ": " << c.name << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nNo contact found with number: " << target << "\n";
}
void updatePhone(vector<Contact>& contacts) {
    string target;
    cout << "\nEnter name whose number you want to update: ";
    cin >> target;

    bool found = false;
    for (Contact& c : contacts) {
        if (c.name == target) {
            cout << "Current number: " << c.phone << "\n";
            cout << "Enter new number: ";
            cin >> c.phone;
            saveContacts(contacts);
            cout << "Updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nNo contact found with name: " << target << "\n";
}
void displayAll(const vector<Contact>& contacts) {
    Contact::printHeader();
    for (const Contact& c : contacts) {
        c.display();
    }
    cout << string(35, '-') << "\n";
}
void printMenu() {
    cout << "\n========== CONTACT BOOK ==========\n";
    cout << "1. Show all contacts\n";
    cout << "2. Find phone number by name\n";
    cout << "3. Find name by phone number\n";
    cout << "4. Update a phone number\n";
    cout << "0. Exit\n";
    cout << "===================================\n";
    cout << "Enter choice: ";
}
int main() {
    vector<Contact> contacts = loadContacts();

    if (contacts.empty()) {
        cout << "No contacts loaded. Exiting.\n";
        return 1;
    }

    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: displayAll(contacts);      break;
            case 2: findPhone(contacts);       break;
            case 3: findName(contacts);        break;
            case 4: updatePhone(contacts);     break;
            case 0: cout << "\nGoodbye.\n";    break;
            default: cout << "\nInvalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}