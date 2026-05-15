#include<iostream>
#include <stdexcept>
#include <string>
using namespace std;

// ───── Custom base exception ─────
class BankException : public runtime_error {.   int errorCode_;
public:
  BankException(const string& msg, int 
         code = 0)  : runtime_error(msg),  
                     errorCode_(code) {}
  int errorCode() const noexcept {
   return errorCode_ ; }
};

// ─── Specialized exceptions ─────
class InsufficientFundsException : public BankException {
    double balance_, amount_;
public:
    InsufficientFundsException(double bal, double amt):BankException("Insufficient funds: need $” + to_string(amt-bal) + " more", 1001"), balance_(bal), amount_(amt){}

  double shortfall() const { 
      return amount_ - balance_; }
};

class AccountLockedException : public BankException {
    string accountId_;
public:
   AccountLockedException(const string& id)
      :BankException("Account " + id + " is 
      locked", 1002), accountId_(id) {}
  string accountId() const { 
  return accountId_; }
};
// ─── Using the custom exceptions ────
class BankAccount {
    double balance_ = 500.0;
    bool locked_ = false;
    string id_ = "ACC-001";
public:
  void withdraw(double amount) {
    if (locked_)  
      throw AccountLockedException(id_);
    if (amount > balance_)
      throw InsufficientFundsException( 
                  balance_ , amount);
    
   balance_ -= amount;
   }
};
void BankAccount::withdraw(double amount) {
  if (locked_) 
   throw AccountLockedException(id_);
  if (amount > balance_)
   throw InsufficientFundsException( 
                     balance_, amount);
  
  balance_ -= amount;
  cout << "Withdrew $" << amount << ". 
          Balance: $" << balance_ << endl;
}
int main() {
  BankAccount acc;
  try {
       acc.withdraw(200.0);   // ✓ OK
       acc.withdraw(400.0);   // ✗
       throws InsufficientFundsException
                 } 
catch(const InsufficientFundsException& e) {   // Rich error data
  cout <<"ERROR ["<< e.errorCode() 
       << "]:" << e.what() << endl;
  cout << "Shortfall: $" << e.shortfall() 
       << endl;
} 


catch (const AccountLockedException& e) {
  cout << "LOCKED [" << e.errorCode() 
       << "]: " << e.what() << endl;
  cout << "Account ID: " << e.accountId() 
       << endl;
} 
catch (const BankException& e) {
  // Catches any bank error
  cout << "Bank error [" << e.errorCode() 
       << "]: " << e.what() << endl;
} 
catch (const exception& e) {
   cout << "Unexpected: " << e.what() << endl;
}
 
 return 0;
}


