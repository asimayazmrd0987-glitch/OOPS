#include <iostream>
using namespace std;
enum posneg
{
    neg,
    pos
};

class Distance
{
protected:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {}
    Distance(int f, float in) : feet(f), inches(in) {}
    void getDistance()
    {
        cout << "Enter feet :" << endl;cin>>feet;
        cout << "Enter inches :" << endl;cin>>inches;
    }
    void getDisplay() const
    {
        cout << "Feet :" << feet << " Inches :" << inches << endl;
    }
};
class Disign : public Distance
{
private:
    posneg sign;
public:
    Disign() : Distance()
    {
        sign = pos;
    }
    Disign(int f, float in, posneg sg = pos) : Distance(f, in)
    {
        sign = sg;
    }
    void disDistance()
    {
        Distance::getDistance();
        char ch;
        cout << "Enter sign + or - :";
        cin >> ch;
        sign = (ch == '+') ? pos : neg;
    }
    void disDisplay() const
    {
        cout << ((sign == pos) ? "(+)" : "(-)");
        Distance::getDisplay();
    }
};
int main()
{
    Disign d1;
    d1.getDistance();
    d1.getDisplay();
    Disign c1(12, 23.1);
    Disign s1(13, 45.2, pos);
    
    // c1.getDistance();
    c1.disDisplay();
    s1.disDisplay();
        return 0;
}
