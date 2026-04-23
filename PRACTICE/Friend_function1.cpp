#include<iostream>
using namespace std;

class BankAccount{
    private:
    string owner;
    double balance;
    
    public:
    BankAccount(string name, double amount):// constructor 9 argument 0
    owner(name), balance(amount) {}

    friend void printDetail(const BankAccount& acc);
};
void printDetail(const BankAccount& acc){
    cout<<"Owner is "<<acc.owner<<endl;
    cout<<"Balance is "<<acc.balance<<endl;
}

int main(){
    BankAccount acc("Abdul",9000.0);
    printDetail(acc);
    return 0;
}

