#include <iostream>
using namespace std;

enum Day { Monday, Tuesday, Wednesday, Thursday, Friday };

int main() {
    Day today = Wednesday;

    switch(today) {
        case Monday:
            cout << "Start of week";
            break;

        case Wednesday:
            cout << "Mid week";
            break;

        case Friday:
            cout << "Weekend coming!";
            break;

        default:
            cout << "Normal day";
    }
}