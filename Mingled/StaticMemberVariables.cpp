#include <iostream>
using namespace std;
class BankAccount {
public:
    static int totalAccounts;  // Shared by all objects
    int balance;               // Unique to each object
    
    BankAccount() {
        totalAccounts++;       // Increment shared counter
    }
};

// MUST define outside the class
int BankAccount::totalAccounts = 0;

int main() {
    BankAccount a1, a2, a3;
    cout << "Total accounts: " << BankAccount::totalAccounts << endl; //Access shared variable
    // All share: totalAccounts = 3
    // Each has: separate balance
}