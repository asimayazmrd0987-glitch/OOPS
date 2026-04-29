#include <iostream>
using namespace std;

class count
{
private:
    static int object;

public:
    count()
    {
        object++;
    }
    static void display()
    {
        cout << "So! Count of the objects are = " << object << endl;
    }
};
int count::object=0;
int main()
{
    count a1, b2, c3;
    count::display();
}
