#include<iostream>
#include<string>
using namespace std;

class Type{
    string dimension;
    string grade;
    public:
    Type(){
        dimension = "0";
        grade = "0";
    }
    // Type():dimension(N/A),grade(N/A){}
    Type(string d, string g):dimension(d), grade(g){}
    void getType(){
        cout<<"Enter the dimension :";cin>>dimension;
        cout<<"Enter the grade :"; cin>>grade;
    }
    void showType() const{
        cout<<"Dimension is :"<<dimension<<endl;
        cout<<"Grade is :"<<grade<<endl;
    }
};
class Distance{
    private:
    int feet;
    float inches;
    public:
    Distance (){
        feet=0;
        inches=0.0f;
    }
    Distance(int f, float in):feet(f),inches(in){}
    void getDist(){
        cout<<"Enter feet :"<<feet;cin>>feet;
        cout<<"Enter inches in decimals :";cin>>inches;
    }
    void showDist() const{
        cout<<"Feet are :"<<feet<<endl;
        cout<<"Inches are :"<<inches<<endl;
    }
};
class Lumber: public Distance, public Type{
    private:
    int quantity;
    double prize;
    public:
    Lumber():quantity(0), prize(0.0){}
    Lumber(string d, string g, int qa, double pr,int f, float in):quantity(qa),prize(pr),Distance(f, in),
    Type(d, g){}
    void getLumber(){
        Type::getType();
        Distance::getDist();
        cout<<"Enter quantity :";cin>>quantity;
        cout<<"Enter prize :";cin>>prize;
    }
    void showLumber() const{
         Type::showType();
         Distance::showDist();
        cout<<"Quantity is :"<<quantity<<endl;
        cout<<"Prize is $:"<<prize*quantity<<endl; 
    }
};
int main(){
 Lumber l1;
 cout<<"L1 data is :";
 l1.getLumber();
 Lumber stud("2x4","const",8,0.1,200,4.45f);
 cout<<"L1 is :";
 l1.showLumber();
 cout<<"Studs is :"; 
 stud.showLumber();
 return 0;
}