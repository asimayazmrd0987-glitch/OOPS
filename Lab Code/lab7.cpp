// ============================================================
//   FRIEND FUNCTIONS & FRIEND CLASSES IN C++
//   5 Problems — Fully Solved and Explained
// ============================================================
#include <iostream>
#include <string>
using namespace std;
// ============================================================
//   PROBLEM 1
//   Class with private int a & b
//   Friend function: initializes and displays them
// ============================================================

// WHY FRIEND HERE:
// initialize() and display() are NOT members of Testing —
// they are standalone functions. Without 'friend', they
// cannot touch a.val and b.val. With friend, they can.
class Testing {
private:
    int a;
    int b;
public:
    // Grant access to these two standalone functions
    friend void initialize(Testing& obj, int x, int y);
    friend void display(const Testing& obj);
};
// Standalone function — receives object BY REFERENCE
// so it can modify the private members directly
void initialize(Testing& obj, int x, int y) {
    obj.a = x;   // allowed because of 'friend' declaration
    obj.b = y;
}
void display(const Testing& obj) {
    cout << "  a = " << obj.a << "\n";
    cout << "  b = " << obj.b << "\n";
}
void runProblem1() {
    cout << "\n=== PROBLEM 1: Friend function — init & display ===\n";

    Testing t;
    initialize(t, 42, 99);
    display(t);
}

// ============================================================
//   PROBLEM 2
//   Two separate classes, each with private data
//   One friend function accesses BOTH and returns the greater
// ============================================================

// KEY INSIGHT:
// A friend function can be declared in BOTH classes.
// It then has the spare key to both locked rooms.

// Forward declare ClassB so ClassA's friend declaration can reference it
class ClassB;

class ClassA {
private:
    int data;
public:
    ClassA(int val) : data(val) {}

    // Same function befriended in ClassA...
    friend int getGreater(const ClassA& a, const ClassB& b);
};

class ClassB {
private:
    int data;
public:
    ClassB(int val) : data(val) {}

    // ...and in ClassB
    friend int getGreater(const ClassA& a, const ClassB& b);
};

// This one function now holds keys to both classes
int getGreater(const ClassA& a, const ClassB& b) {
    if (a.data >= b.data) {
        cout << "  ClassA has greater value: " << a.data << "\n";
        return a.data;
    } else {
        cout << "  ClassB has greater value: " << b.data << "\n";
        return b.data;
    }
}

void runProblem2() {
    cout << "\n=== PROBLEM 2: Friend function comparing two classes ===\n";

    ClassA objA(75);
    ClassB objB(50);

    cout << "  ClassA data = 75, ClassB data = 50\n";
    int result = getGreater(objA, objB);
    cout << "  Greater value = " << result << "\n";

    // Swap values to test other branch
    ClassA objA2(30);
    ClassB objB2(80);
    cout << "\n  ClassA data = 30, ClassB data = 80\n";
    getGreater(objA2, objB2);
}


// ============================================================
//   PROBLEM 3
//   containerClass: private a & b, getter(), putter()
//   containedClass: friend class with setter() that reads
//                   containerClass private data
// ============================================================

// WHY FRIEND CLASS:
// When you declare 'friend class containedClass', ALL methods
// of containedClass get the spare key — not just one function.
// Use this when a whole class needs deep access.

class containedClass;   // forward declaration (needed below)

class containerClass {
private:
    int a;
    int b;

public:
    // getter = inputs from user (confusingly named in the question,
    // but we follow the spec: getter asks user for input)
    void getter() {
        cout << "  Enter value for a: ";
        cin >> a;
        cout << "  Enter value for b: ";
        cin >> b;
    }

    // putter = displays private data
    void putter() const {
        cout << "  a = " << a << "\n";
        cout << "  b = " << b << "\n";
    }

    // Entire containedClass gets access to our private members
    friend class containedClass;
};

class containedClass {
public:
    // setter() reads containerClass's private members
    // (possible because containedClass is a friend)
    void setter(const containerClass& obj) {
        cout << "  [containedClass::setter] Reading containerClass private data:\n";
        cout << "    a = " << obj.a << "\n";   // direct private access!
        cout << "    b = " << obj.b << "\n";
    }
};

void runProblem3() {
    cout << "\n=== PROBLEM 3: Friend class ===\n";

    containerClass box;
    cout << "  [containerClass::getter] Input values:\n";
    box.getter();

    cout << "  [containerClass::putter] Display via putter():\n";
    box.putter();

    containedClass inner;
    inner.setter(box);
}


// ============================================================
//   PROBLEM 4
//   Two classes with private data
//   Friend function takes both objects, adds their private
//   data, and stores result in a third object
// ============================================================

// PATTERN: friend function that operates on two objects
// and writes back into a result object.
// Think of it like: result = operator+(a, b) — this is
// exactly how operator overloading works internally in C++.

class Number {
private:
    int value;

public:
    Number(int v = 0) : value(v) {}

    void display(const string& label) const {
        cout << "  " << label << " = " << value << "\n";
    }

    // Grant access to addObjects
    friend Number addObjects(const Number& x, const Number& y);
};

// Takes two objects, accesses their private 'value',
// returns a NEW Number object containing the sum
Number addObjects(const Number& x, const Number& y) {
    return Number(x.value + y.value);   // direct private access
}

void runProblem4() {
    cout << "\n=== PROBLEM 4: Friend function — addition of private data ===\n";

    Number n1(25);
    Number n2(35);
    Number n3 = addObjects(n1, n2);

    n1.display("n1");
    n2.display("n2");
    n3.display("n1 + n2");
}


// ============================================================
//   PROBLEM 5
//   DM: stores distance in meters + centimeters
//   DB: stores distance in feet + inches
//   Friend function adds DM + DB
//   Result can be displayed as DM or DB
// ============================================================

// CONVERSION CONSTANTS:
//   1 foot  = 30.48 cm
//   1 inch  = 2.54  cm
//   1 meter = 100   cm

// Forward declare DB so DM can reference it in friend declaration
class DB;

class DM {
private:
    int meters;
    int centimeters;   // always 0-99

public:
    DM(int m = 0, int cm = 0) : meters(m), centimeters(cm) {}

    void input() {
        cout << "  Enter meters: ";      cin >> meters;
        cout << "  Enter centimeters: "; cin >> centimeters;
    }

    void display() const {
        cout << "  Distance = " << meters << " m  "
             << centimeters << " cm\n";
    }

    // Convert everything to centimeters (common unit)
    double toCentimeters() const {
        return meters * 100.0 + centimeters;
    }

    // Build DM from raw centimeters
    static DM fromCentimeters(double totalCm) {
        int m  = (int)(totalCm / 100);
        int cm = (int)(totalCm) % 100;
        return DM(m, cm);
    }

    friend DM   addAsDM(const DM& dm, const DB& db);
    friend DB   addAsDB(const DM& dm, const DB& db);
};

class DB {
private:
    int feet;
    int inches;   // always 0-11

public:
    DB(int f = 0, int i = 0) : feet(f), inches(i) {}

    void input() {
        cout << "  Enter feet:   "; cin >> feet;
        cout << "  Enter inches: "; cin >> inches;
    }

    void display() const {
        cout << "  Distance = " << feet << " ft  "
             << inches << " in\n";
    }

    // Convert to centimeters (common unit)
    double toCentimeters() const {
        return feet * 30.48 + inches * 2.54;
    }

    // Build DB from raw centimeters
    static DB fromCentimeters(double totalCm) {
        int totalInches = (int)(totalCm / 2.54);
        int ft  = totalInches / 12;
        int in  = totalInches % 12;
        return DB(ft, in);
    }

    friend DM   addAsDM(const DM& dm, const DB& db);
    friend DB   addAsDB(const DM& dm, const DB& db);
};

// STRATEGY:
// 1. Convert both objects to a common unit (centimeters)
// 2. Add the totals
// 3. Convert result back to the desired unit

DM addAsDM(const DM& dm, const DB& db) {
    double totalCm = dm.toCentimeters() + db.toCentimeters();
    return DM::fromCentimeters(totalCm);
}

DB addAsDB(const DM& dm, const DB& db) {
    double totalCm = dm.toCentimeters() + db.toCentimeters();
    return DB::fromCentimeters(totalCm);
}

void runProblem5() {
    cout << "\n=== PROBLEM 5: DM + DB distance addition ===\n";

    DM d1;
    DB d2;

    cout << "\n  Enter DM (meters + centimeters):\n";
    d1.input();
    cout << "\n  Enter DB (feet + inches):\n";
    d2.input();

    cout << "\n  You entered:\n";
    cout << "  DM: "; d1.display();
    cout << "  DB: "; d2.display();

    DM resultDM = addAsDM(d1, d2);
    DB resultDB = addAsDB(d1, d2);

    cout << "\n  Result as meters + centimeters:\n  ";
    resultDM.display();

    cout << "\n  Result as feet + inches:\n  ";
    resultDB.display();
}


// ============================================================
//   MAIN — runs all 5 problems
// ============================================================
int main() {
    runProblem1();
    runProblem2();

    // Problems 3 and 5 need user input
    // Comment them in when running interactively
    // runProblem3();

    runProblem4();

    // runProblem5();

    cout << "\n";
    return 0;
}
