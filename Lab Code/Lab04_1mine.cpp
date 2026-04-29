#include <iostream>
// #include "testing.h"
using namespace std;

using namespace std;
class testing{
   public:
   void constant()const {
   cout <<"== I am Constant =="<<endl;
   }

   void non_constant(){
    cout<<"== I am non Constant =="<<endl;
   }
};
int main()
{
    testing obj;
    const testing obj1;

    obj.constant();
    obj.non_constant();

    obj1.constant();
    /* // obj1.non_constant(); this will give error bcz we
    constant object can only call constant fuctions */
    return 0;
}