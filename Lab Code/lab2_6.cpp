#include <iostream>
using namespace std;

class Number
{
private:
    int data;
public:
    Number() : data(0) {}
    Number(int d) : data(d) { }
    void insert()
    {
        cout << "Enter a number: ";
        cin >> data;}
    Number &operator--()
    {
        --data;
        return *this;}
    void display() const
    {
        cout<< data << endl;
    }
};
int main()
{
    Number n1;   
    n1.insert(); 
cout << "The value that user gave is : ";    n1.display();
    --n1; 
    cout << "After -- or decrement the value become : ";    n1.display();

    return 0;
}
