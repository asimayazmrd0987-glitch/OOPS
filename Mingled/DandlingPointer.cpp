#include <iostream>
using namespace std;

class MyString
{
private:
    char *str; // dynamically allocated
    int len;

public:
    MyString(const char *s)
    {
        len = strlen(s);
        str = new char[len + 1]; // allocate memory
        strcpy(str, s);
    }
    ~MyString()
    {
        delete[] str; // free memory }
    };
    int main()
    {
        MyString s1("Hello");
        MyString s2 = s1; // default copy constructor (shallow copy)
        cout<<s1.len<<" "<<s2.len;
    }
// Three Serious Problems 
// ❌ Double Deletion (Dangling Pointer) ``` 
// s1 destroyed → deletes memory at address X 
// s2 destroyed → tries to delete same address X again 
//                    → CRASH / undefined behavior
// 2. ❌ Unintended Modification
// s2.str[0] = 'Y'; // meant to change only s2 
//                     // but s1 is ALSO changed! (same memory)
// 3. ❌ Memory Leak / Corruption
// s2 = s1; // s2's original memory is never freed 
//             // → memory leak
