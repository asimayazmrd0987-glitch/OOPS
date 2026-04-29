#include <iostream>
using namespace std;

class Person {
public:
    void Talk() {
        cout << "Person is talking." << endl;
    }
    void Walk() {
        cout << "Person is walking." << endl;
    }
    void Eat() {
        cout << "Person is eating." << endl;
    }
};
class Mathsteacher : public Person {
public:
    void TeachMaths() {
        cout << "Teaching mathematics." << endl;
    }
};
class Footballer : public Person {
public:
    void PlayFootball() {
        cout << "Playing football." << endl;
    }
};
class Businessman : public Person {
public:
    void RunBusiness() {
        cout << "Running business." << endl;
    }
};
int main() {
    cout << "= Maths Teacher =" << endl;
    Mathsteacher teacher;
    teacher.Talk();
    teacher.Walk();
    teacher.Eat();
    teacher.TeachMaths();

    cout << "\n= Footballer =" << endl;
    Footballer player;
    player.Talk();
    player.Walk();
    player.Eat();
    player.PlayFootball();

    cout << "\n= Businessman =" << endl;
    Businessman exec;
    exec.Talk();
    exec.Walk();
    exec.Eat();
    exec.RunBusiness();

    return 0;
}