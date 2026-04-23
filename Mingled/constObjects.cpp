// constObj.cpp constant Distance objects
#include <iostream>
using namespace std;
class Distance // English Distance class
{
private:
    int feet;
    float inches;
public:
    // 2-arg constructor
    Distance(int ft, float in) : feet(ft), inches(in)
    {
    }
    /*   void getDist() const, we cannot use it bcz on line 27 we are send two arguments to it
    so it won't receive it bcz of const */
    void getDist() // user input; non-const function
    {
        cout << "\nEnter feet:";
        cin >> feet;
        cout << "Enter inches:";
        cin >> inches;
    }
    void showDist() const // display distance; const function
    {
        cout << feet << "\'-" << inches << '\"';
    }
};
int main()
{
    const Distance football(300, 0);
    // football.getDist(); 	// ERROR: getDist() not const
    cout << "football = ";
    football.showDist(); // OK
    cout << endl;
    return 0;
}
