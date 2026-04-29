#include <iostream>
#include <string>
using namespace std;


class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        cin.ignore(); 
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;
public:
    void getdata() {
        Publication::getdata(); // Get base class data
        cout << "Enter page count: ";
        cin >> pageCount;
        cin.ignore();
    }

    void putdata() const {
        Publication::putdata(); // Display base class data
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};


class Tape : public Publication {
private:
    float playingTime;
public:
    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        cin.ignore();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book myBook;
    Tape myTape;

    cout << "=== Enter Book Details ===" << endl;
    myBook.getdata();

    cout << "\n=== Enter Tape Details ===" << endl;
    myTape.getdata();

    cout << "\n=== Book Information ===" << endl;
    myBook.putdata();

    cout << "\n=== Tape Information ===" << endl;
    myTape.putdata();

    return 0;
}