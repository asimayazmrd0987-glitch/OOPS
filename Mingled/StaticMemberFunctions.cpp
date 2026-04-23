#include <iostream>
using namespace std;
class MathUtils {
public:
    static int inline add(int a, int b) {      // No 'this' pointer
        return a + b;
    }
    
    static int getPI() {                // Utility function
        return 3.14159;
    }
};

int main() {
    // Call without creating object
    int sum = MathUtils::add(5, 3);     // ✅ Direct class access
    double pi = MathUtils::getPI();     // ✅ Utility method
    cout << "Sum: " << sum << ", PI: " << pi << endl;
    
    MathUtils m;
    m.add(2, 7);   // ⚠️ Works but discouraged
    cout << "Sum: " << sum << ", PI: " << pi << endl;                     
}