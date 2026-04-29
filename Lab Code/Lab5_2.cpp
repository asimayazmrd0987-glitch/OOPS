#include <iostream>
using namespace std;
class Testing{
    private:
    int a=0;
    static int count;
    public:
    void  levelup() {
        a++;
          count++;
    }
    static void display(){
    cout<<"== We Are Going To Count the incremented a and count using static =="<<endl;
    cout<<"Count is "<<count<<endl;
    }
};
int Testing::count=0;
int main(){
    Testing t;
    t.levelup();
    t.levelup();
    t.levelup();

    t.display();
    return 0;
}




