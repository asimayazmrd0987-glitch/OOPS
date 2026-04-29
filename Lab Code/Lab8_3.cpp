#include<iostream>
#include<string>
using namespace std;

class student_1{
   private:
   string name;
   int age;
   string gender;
   public:
   void getData(){
    cout<<"Enter name of the Student : ";cin>>name;
    cout<<"Enter age of the Student : ";cin>>age;
    cout<<"Enter gender of the Student : ";cin>>gender;
   }
   void display(){
    cout<<"Name of the Student is :"<<name<<endl;
    cout<<"Age of the Student is :"<<age<<endl;
    cout<<"Gender of the Student is :"<<gender<<endl;
   }
};
class student_2: public student_1{
    private:
    float totalMarks;
    float percentage;
    float grade;
    public:
    void get(){
        cout<<"Enter the total Marks : ";cin>>totalMarks;
        cout<<"Enter the Percentage : ";cin>>percentage;
        cout<<"Enter the Grade : ";cin>>grade;
    }
    void put(){
        cout<<"The total Marks are :"<<totalMarks<<endl;
        cout<<"Percentage is :"<<percentage<<endl;
        cout<<"Grades are :"<<grade<<endl;
    }    
};
int main(){
    student_2 s1;
    s1.getData();
    s1.get();
    s1.display();
    s1.put();
    return 0;
}