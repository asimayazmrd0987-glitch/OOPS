/*
 * BEGINNER LEVEL: Basic Aliases in C++
 * 
 * What you'll learn:
 * - typedef and using for simple type aliases
 * - Basic references (variable nicknames)
 * - Basic pointers (memory addresses)
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ============================================
    // PART 1: Type Aliases (Giving new names to types)
    // ============================================
    
    // typedef: Old way to create alias (C-style)
    // Syntax: typedef existing_type new_name;
    typedef unsigned int uint;      // uint is now alias for unsigned int
    typedef long long bigNumber;    // bigNumber is alias for long long
    
    // Using the aliases
    uint age = 25;                  // Same as: unsigned int age = 25;
    bigNumber population = 8000000000LL;
    
    cout << "=== Type Aliases ===" << endl;
    cout << "Age (uint): " << age << endl;
    cout << "Population (bigNumber): " << population << endl;
    
    // 'using': Modern C++ way (C++11 and later)
    // Syntax: using new_name = existing_type;
    // This is clearer and preferred in modern code
    using Score = int;              // Score represents integer scores
    using Kilometer = double;       // Kilometer represents distance
    
    Score mathScore = 95;
    Kilometer distance = 150.5;
    
    cout << "Math Score: " << mathScore << endl;
    cout << "Distance: " << distance << " km" << endl;
    
    // ============================================
    // PART 2: References (&) - Variable Nicknames
    // ============================================
    
    // A reference is another name for an existing variable
    // It does NOT create new memory, just another way to access same data
    
    int original = 100;
    int& ref = original;            // ref is reference to original
    
    // Both names access SAME memory location
    cout << "\n=== References ===" << endl;
    cout << "original: " << original << endl;
    cout << "ref: " << ref << endl;
    cout << "Address of original: " << &original << endl;
    cout << "Address of ref: " << &ref << endl;  // Same address!
    
    // Changing reference changes original
    ref = 200;                      // This changes original too!
    cout << "After ref = 200:" << endl;
    cout << "original: " << original << endl;    // Now 200
    
    // Common use: Function parameters (avoid copying)
    // When we pass big objects to functions, copying is slow
    // Reference lets us work with original without copy
    
    // ============================================
    // PART 3: Pointers (*) - Storing Addresses
    // ============================================
    
    // Pointer is a variable that stores memory address
    // Unlike reference, pointer is a separate variable with its own memory
    
    int value = 50;
    int* ptr = &value;              // ptr stores address of value
                                    // & is "address of" operator
    
    cout << "\n=== Pointers ===" << endl;
    cout << "value: " << value << endl;
    cout << "&value (address): " << &value << endl;
    cout << "ptr (stores address): " << ptr << endl;
    cout << "*ptr (value at address): " << *ptr << endl;
    // * is "dereference" operator - gets value at stored address
    
    // Changing through pointer
    *ptr = 75;                      // Change value at address ptr stores
    cout << "After *ptr = 75:" << endl;
    cout << "value: " << value << endl;          // Now 75
    
    // Key difference from reference:
    // Pointer can be changed to point elsewhere
    int another = 999;
    ptr = &another;                 // Now ptr points to another
    cout << "After ptr = &another:" << endl;
    cout << "*ptr: " << *ptr << endl;            // 999
    cout << "value is " << value << endl;   
    
    return 0;
}