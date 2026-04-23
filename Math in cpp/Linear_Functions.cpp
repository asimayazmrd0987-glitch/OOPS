#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes
void standardLinear();
void linearTransformation();
void linearCombination();
void distancePointToLine();
void slopeIntercept();

int main() {
    int choice;
    char continueProg = 'y';
    
    cout << "=== LINEAR FUNCTIONS CALCULATOR ===" << endl;
    
    while (continueProg == 'y' || continueProg == 'Y') {
        cout << "\nChoose a Linear Function Type:" << endl;
        cout << "1. Standard Linear Equation (y = mx + c)" << endl;
        cout << "2. Slope-Intercept Form Calculator" << endl;
        cout << "3. Linear Transformation (2D Matrix)" << endl;
        cout << "4. Linear Combination (ax + by)" << endl;
        cout << "5. Distance from Point to Line" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter your choice (0-5): ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                standardLinear();
                break;
            case 2:
                slopeIntercept();
                break;
            case 3:
                linearTransformation();
                break;
            case 4:
                linearCombination();
                break;
            case 5:
                distancePointToLine();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
        cout << "\nDo you want to continue? (y/n): ";
        cin >> continueProg;
    }
    
    return 0;
}

// 1. Standard Linear Function: y = mx + c
void standardLinear() {
    double m, c, x, y;
    
    cout << "\n--- Standard Linear Equation (y = mx + c) ---" << endl;
    cout << "Enter slope (m): ";
    cin >> m;
    cout << "Enter y-intercept (c): ";
    cin >> c;
    cout << "Enter x value: ";
    cin >> x;
    
    y = m * x + c;
    
    cout << fixed << setprecision(2);
    cout << "f(" << x << ") = " << m << "(" << x << ") + " << c << " = " << y << endl;
    cout << "Output: y = " << y << endl;
}

// 2. Slope-Intercept with two points
void slopeIntercept() {
    double x1, y1, x2, y2, m, c, x, y;
    
    cout << "\n--- Slope-Intercept from Two Points ---" << endl;
    cout << "Enter Point 1 (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter Point 2 (x2 y2): ";
    cin >> x2 >> y2;
    
    // Calculate slope (m)
    if (x2 - x1 == 0) {
        cout << "Error: Vertical line (undefined slope)!" << endl;
        return;
    }
    
    m = (y2 - y1) / (x2 - x1);
    c = y1 - m * x1;  // y-intercept
    
    cout << "Linear Equation: y = " << m << "x + " << c << endl;
    
    cout << "Enter x to calculate y: ";
    cin >> x;
    y = m * x + c;
    
    cout << "f(" << x << ") = " << y << endl;
}

// 3. Linear Transformation: T(x,y) = (ax + by, cx + dy)
void linearTransformation() {
    double x, y, a, b, c, d, x_new, y_new;
    
    cout << "\n--- Linear Transformation T(x,y) = (ax + by, cx + dy) ---" << endl;
    cout << "Enter matrix elements [a b; c d]:" << endl;
    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;
    cout << "c: "; cin >> c;
    cout << "d: "; cin >> d;
    
    cout << "Enter input vector (x y): ";
    cin >> x >> y;
    
    x_new = a * x + b * y;
    y_new = c * x + d * y;
    
    cout << "T(" << x << ", " << y << ") = (" << x_new << ", " << y_new << ")" << endl;
    
    // Check if transformation is linear (determinant)
    double det = a * d - b * c;
    cout << "Determinant: " << det << " (Non-zero = invertible)" << endl;
}

// 4. Linear Combination: z = a*x + b*y
void linearCombination() {
    double a, b, x, y, z;
    
    cout << "\n--- Linear Combination ( like z = ax + by) ---" << endl;
    cout << "Enter coefficients a and b: ";
    cin >> a >> b;
    cout << "Enter variables x and y: ";
    cin >> x >> y;
    
    z = a * x + b * y;
    
    cout << z << " = " << a << "(" << x << ") + " << b << "(" << y << ")" << endl;
    cout << "Result: " << z << endl;
}

// 5. Distance from Point (x0,y0) to Line Ax + By + C = 0
void distancePointToLine() {
    double A, B, C, x0, y0, distance;
    
    cout << "\n--- Distance from Point to Line ---" << endl;
    cout << "Enter line coefficients (like A B C for Ax + By + C = 0):" << endl;
    cout << "A: "; cin >> A;
    cout << "B: "; cin >> B;
    cout << "C: "; cin >> C;
    
    cout << "Enter point coordinates (x0 y0): ";
    cin >> x0 >> y0;
    
    // Distance formula: |Ax0 + By0 + C| / sqrt(A² + B²)
    distance = abs(A * x0 + B * y0 + C) / sqrt(A * A + B * B);
    
    cout << fixed << setprecision(4);
    cout << "Distance = |" << A << "(" << x0 << ") + " << B << "(" << y0 
         << ") + " << C << "| / √(" << A << "² + " << B << "²)" << endl;
    cout << "Distance = " << distance << endl;
}