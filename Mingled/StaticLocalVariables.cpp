#include<iostream>
using namespace std;
//Persist between function calls — initialized only once.
class Logger {
public:
    void log(const string& msg) {
        static int logCount = 0;    // Initialized once, persists
        logCount++;
        cout << "[" << logCount << "] " << msg << endl;
    }
};

int main() {
    Logger l;
    l.log("First");     // [1] First
    l.log("Second");    // [2] Second  (count persists)
    l.log("Third");     // [3] Third
}