#include <iostream>
using namespace std;

// -------- STACK DEMO --------
void stackDemo() {
    cout << "\n===== STACK DEMO =====\n";

    int x = 10;   // stored in stack
    int y = 20;   // stored in stack

    cout << "Value of x: " << x << endl;
    cout << "Address of x (stack): " << &x << endl;

    cout << "Value of y: " << y << endl;
    cout << "Address of y (stack): " << &y << endl;

    cout << "Stack variables are auto-deleted when function ends.\n";
}

// -------- HEAP DEMO --------
void heapDemo() {
    cout << "\n===== HEAP DEMO =====\n";

    int* p = new int;  // allocate on heap
    *p = 50;

    cout << "Value in heap: " << *p << endl;
    cout << "Address in heap: " << p << endl;

    delete p; // free memory

    cout << "Heap memory freed using delete.\n";
}

// -------- BUFFER DEMO --------
void bufferDemo() {
    cout << "\n===== BUFFER DEMO =====\n";

    char buffer[20]; // buffer (temporary storage)

    cout << "Enter a word (max ~19 chars): ";
    cin >> buffer;

    cout << "You entered: " << buffer << endl;
    cout << "Buffer address: " << (void*)buffer << endl;

    cout << "Buffer stores temporary data like input/output.\n";
}

int main() {
    cout << "=== MEMORY DEMONSTRATION PROGRAM ===\n";

    // Stack
    stackDemo();

    // Heap
    heapDemo();

    // Buffer
    bufferDemo();

    cout << "\nProgram finished.\n";
    return 0;
}
