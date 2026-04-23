#include<iostream>
using namespace std;

class Rectangle{
   private:
   int length=0;
   int width=0;

   public:
   void setlength(int len){
    length=len;
   }
   int getlength(){
    return length;
   }

   void setwidth(int wid){
    width=wid;   
   }
   int getwidth(){
    return width;
   }

  int area(){
    return length*width;
  }
  friend void getArea(const Rectangle& r);

};
void getArea(const Rectangle& r){
   cout<<length<<endl;
   cout<<width<<endl;
}
int main(){
    Rectangle e;
    e.setlength(5);
    e.setwidth(2);
    // e.getlength():
    cout<<"The area is :"<<e.area()<<endl;
    cout<<getArea(setlength)<<endl;

    return 0;
}