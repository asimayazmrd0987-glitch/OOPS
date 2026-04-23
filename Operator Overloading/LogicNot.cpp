#include <iostream>
using namespace std;

class StringWrapper {
private:
    char* str;
public:
    StringWrapper(const char* s = "") {
        // simplistic constructor for demonstration
        str = new char[100];
        strcpy(str, s);
    }
    ~StringWrapper() { delete[] str; }

    // Overload logical NOT (!)
    bool operator!() const {
        return (str == nullptr || str[0] == '\0');
    }
};

int main() {
    StringWrapper s1("Hello");
    StringWrapper s2("");

    if (!s1)
        cout << "s1 is empty\n";
    else
        cout << "s1 is not empty\n";

    if (!s2)
        cout << "s2 is empty\n";
    else
        cout << "s2 is not empty\n";

    return 0;
}