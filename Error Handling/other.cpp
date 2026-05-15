#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

double safeDivide(double a, double b) {
    if (b == 0.0)
        throw invalid_argument("Division by zero is undefined");
    return a / b;
}
int getAge(int age) {
    if (age < 0 || age > 150)
        throw out_of_range("Age " + to_string(age) + " is not valid");
    return age;
}
int main() {
    try {
        cout << safeDivide(10.0, 0.0) << endl; // throws invalid_argument
        cout << getAge(-5)            << endl; }  // never reached
    catch (const invalid_argument& e) {          // most specific first!
        cout << "Invalid argument: " << e.what() << endl; }
    catch (const out_of_range& e) {
        cout << "Out of range: "     << e.what() << endl; }
    catch (const exception& e) {                 // catches any std::exception
        cout << "Standard error: "   << e.what() << endl; }
    catch (...) {                                // catches ANYTHING including non-std
        cout << "Unknown error occurred!" << endl; }
   
     cout << "Program continues normally." << endl;
    return 0;
}
