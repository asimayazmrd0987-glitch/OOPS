#include<iostream>
using namespace std;
class Height{
   float inches;
   int feet;
   public:
   void set(int ft, float inch){
    feet=ft;
    inches=inch;
   }
   void get(){
    cout<<"== Enter your height =="<<endl;
    cout<<"Feet";cin>>feet;
    cout<<"Inches";cin>>inches;
   }
   void show(){
    cout<<"h1 height is "<<this->feet<<" feet and "<<this->inches<<" inches"<<endl;
    // cout<<this->inches<<endl;
   }
};
int main(int argc, const char** argv) {
  Height h1, h2;
  h1.set(5, 6);
  h2.get();

  cout<<"h1 is ";h1.show();
  cout<<"h2 is ";h2.show();
    return 0;
}