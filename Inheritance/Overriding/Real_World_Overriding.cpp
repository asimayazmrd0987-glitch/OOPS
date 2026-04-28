#include<iostream>
#include<string>
using namespace std;


class shape{
    public:
    virtual void draw(){
        cout<<" Draw Shape "<<endl;
    }
    virtual float area(){
        return 0.0f;
    }
};
class circle:public shape{
    protected:
    float radius;
    public:
    circle(float f=0):radius(f){}
    void draw(){
        cout<<" Draw Circle "<<endl;
    }
    float area(){
        return 3.14f* radius * radius;
    }    
};
class Rectangle:public shape{
   private:
   float length, width;
   public:
   Rectangle(float l, float w):length(l),width(w){}
   void draw(){
    cout<<"Draw Rectangle "<<endl;
   }
   float area(){
    return length*width;
   }
};
int main(){
//    shape s1;   s1.draw();
//    circle c1;   c1.draw();
//    Rectangle r1;   r1.draw();
//    s1.area();
//    c1.draw()
shape* ptr= new circle(5);
ptr->draw();
cout<<ptr->area()<<endl;
ptr = new Rectangle(3,4);
ptr->draw();
cout<<ptr->area()<<endl;
delete ptr;

return 0;
}