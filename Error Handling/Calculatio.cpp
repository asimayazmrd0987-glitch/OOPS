#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

// Custom exceptions for calculator
class CalcException       : public runtime_error {
public: CalcException(const string& m) : runtime_error(m) {}
};
class DivByZeroException  : public CalcException {
public: DivByZeroException() : CalcException("Division by zero") {}
};
class NegativeSqrtException: public CalcException {
public: NegativeSqrtException(double v)
    : CalcException("Square root of negative: " + to_string(v)) {}
};
class LogNonPositiveException: public CalcException {
public: LogNonPositiveException(double v)
    : CalcException("Log of non-positive: " + to_string(v)) {}
};

class SafeCalculator {
public:
    static double divide(double a, double b) {
        if (b == 0) throw DivByZeroException();
        return a / b;
    }
    static double squareRoot(double x) {
        if (x < 0) throw NegativeSqrtException(x);
        return sqrt(x);
    }
    static double logarithm(double x) {
        if (x <= 0) throw LogNonPositiveException(x);
        return log(x);
    }
    static double power(double base, int exp) noexcept {
        return pow(base, exp);    // Always safe
    }
};

int main() {
    auto test = [](const string& op, auto fn) {
        try { cout << op << " = " << fn() << endl; }
        catch (const CalcException& e)  { cout << "[Calc] " << e.what() << endl; }
        catch (const exception& e)      { cout << "[Err]  " << e.what() << endl; }
    };
    test("10/2",   []{ return SafeCalculator::divide(10, 2); });
    test("10/0",   []{ return SafeCalculator::divide(10, 0); });   // throws
    test("sqrt(9)",[]{ return SafeCalculator::squareRoot(9); });
    test("sqrt(-4)",[]{ return SafeCalculator::squareRoot(-4); }); // throws
    test("log(0)", []{ return SafeCalculator::logarithm(0); });    // throws
    test("2^10",   []{ return SafeCalculator::power(2, 10); });
}
