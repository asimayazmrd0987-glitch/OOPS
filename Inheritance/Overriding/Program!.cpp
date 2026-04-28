#include <iostream>
using namespace std;

class stack
{
protected:
    enum
    {
        MAX = 3
    };
    int st[MAX];
    int top;

public:
    stack() { top = -1; }//index is 0
    void push(int var)
    {
        st[++top] = var;//increment top
    }
    int pop()
    {
        return st[top--];//return top
    }
};
class stack2 : public stack
{
public:
    void push(int var)
    {
        if (top >= MAX - 1)
        {
            cout << "Error stack is full" << endl;
            exit(1);
        }
        stack::push(var);
    }
    int pop()
    {
        if (top < 0)
        {
            cout << "Error stack is empty " << endl;
            exit(1);
        }
        return stack::pop();
    }
};
int main()
{
    stack2 s;//stack() constructor runs & top = -1
    s.push(10);//if (top >= MAX - 1) ===> -1 >= 2 → false and also top -1 become 0
    s.push(15);
    s.push(12);
    s.pop();
    return 0;
}