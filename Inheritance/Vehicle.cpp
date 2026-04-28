#include<iostream>
#include<string>
using namespace std;

class vehicle{
    protected:
    string Brand;
    int speed;
    public:
    vehicle(string b, int s):Brand(b),speed(s){}
    void display(){
        cout<<"Brand is :"<<Brand<<endl;
        cout<<"Speed of a vehicle is :"<<speed<<endl;
    }
    };
    class Car: public vehicle{
        private:
        int doors;
        public:
        Car(string b, int s, int d):
        vehicle(b , s),doors(d){}
        void showDoors(){
            cout<<"Doors nos :"<<doors<<endl;
        }
    };
int main(){
    Car c1("Toyota", 200, 4);
    c1.display();
    c1.showDoors();
    return 0;    
}