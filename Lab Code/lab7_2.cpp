#include<iostream>
using namespace std;
class test_two;
class test_one{
    private:
    int a;
    friend void greaterData(test_one, test_two);    
    public:
    void getData(){
        cout<<"Enter a: "<<endl; cin>>a;
    }
};
class test_two{
     private:
     int b;
     friend void greaterData(test_one, test_two);
     public:
     void get(){
        cout<<"Enter b "<<endl; cin>>b;
     }     
};
 void greaterData(test_one t1, test_two t2){
        if(t1.a>t2.b){
            cout<<"Class test_one is greater"<<endl;
        }
        else{
            cout<<"Class test_two is greater"<<endl;
        }
     }
int main() {
    test_one t1;
    test_two t2;
    t1.getData();
    t2.get();
    greaterData(t1, t2);
    return 0;
}