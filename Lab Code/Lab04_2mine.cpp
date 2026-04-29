#include<iostream>
using namespace std;

class test{
    private:
    int len='l';
    int width='w';

    public:
    test(int l, int w){
        len=l;
        width=w;

    }
    void display() const{
        cout<<"The len is "<<len<<endl;
        cout<<"The Width is "<<width<<endl;
    }
    int getArea()const{
        return len*width;
    }
};
int main(){
    test  obj(12,14);
    obj.display();
    cout<<"Area is "<<obj.getArea()<<endl;

}