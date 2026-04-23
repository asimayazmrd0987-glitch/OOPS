#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Equality operator
    bool operator==(const Date& other) const {
        return (day == other.day && month == other.month && year == other.year);
    }

    // Inequality operator
    bool operator!=(const Date& other) const {
        return !(*this == other);   // reuse ==
    }
};

int main() {
    Date d1(15, 8, 2025), d2(15, 8, 2025), d3(16, 8, 2025);
    cout << (d1 == d2) << endl;   // 1 (true)
    cout << (d1 != d3) << endl;   // 1 (true)
    return 0;
}