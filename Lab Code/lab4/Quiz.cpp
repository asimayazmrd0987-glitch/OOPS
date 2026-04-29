#include <iostream>
using namespace std;
class state
{
public:
    state()
    {
        cout << " Call Constructor " << endl;
    }

    ~state()
    {
        cout << " Call Destructor " << endl;
    }
};
void call(){
    state t;
}
int main(){
 call();
 call();
}