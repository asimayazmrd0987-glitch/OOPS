#include <iostream>
using namespace std;
class Auditor;
class BankAccount
{
private:
    string owner;
    double balance;
    int accNumber;

public:
    BankAccount(string r, double d, int n) : owner(r), balance(d), accNumber(n) {}

    friend class Auditor;
};
class Auditor{
  void showOwner( BankAccount& a){
    cout<<"Owner is :"<<a.owner<<endl;
  }   
  void showBalance( BankAccount& a){
    cout<<"Balance is :"<<a.balance<<endl;
  }
  void showfullAudit(BankAccount& a){
    cout<<a.accNumber<<a.balance<<a.owner<<endl;
  }

};
int main(){
    BankAccount acc("Ali",90000.0,23);

    Auditor aud;
    aud.showBalance(acc);
    aud.showBalance(acc);
    aud.showfullAudit(acc);
    return 0;
}