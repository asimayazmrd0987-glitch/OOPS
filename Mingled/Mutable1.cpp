#include <iostream>
using namespace std;

class Counter
{
public:
    string name;
    string author;
    mutable int accessCount ;
    Counter(string _name, string _author) : author(_author), name(_name) {}
    void setIt() const
    {
        accessCount++;
        cout<<"Name :"<<name<<endl;
    }
};
int main(){
    const Counter c1("Adam","HAHAHA");
    c1.setIt();
    return 0;
}
