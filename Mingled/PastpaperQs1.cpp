#include <iostream>
using namespace std;

class BankAccount {
private:
    int    accountNumber;
    double balance;

public:
    // Constructor — initializes account details
    // BankAccount(int accNum, double initialBalance) {
    //     accountNumber = accNum;
    //     balance       = initialBalance;
    // }
    BankAccount(int accNum, double initialBalance):accountNumber(accNum),
    balance(initialBalance){}

    // Deposit — adds amount to balance
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        balance += amount;
        cout << "Deposited Rs." << amount
             << " | New balance: Rs." << balance << "\n";
    }

    // Withdrawal — deducts amount if sufficient funds exist
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return;
        }
        balance -= amount;
        cout << "Withdrew Rs." << amount
             << " | New balance: Rs." << balance << "\n";
    }

    // Display account info
    void display() const {
        cout << "Account #" << accountNumber
             << " | Balance: Rs." << balance << "\n";
    }
};

int main() {
    // Create two account objects
    BankAccount acc1(1001, 5000.0);
    BankAccount acc2(1002, 12000.0);

    cout << "=== Account 1 ===\n";
    acc1.display();
    acc1.deposit(2000.0);
    acc1.withdraw(1500.0);
    acc1.withdraw(9000.0);   // insufficient funds test

    cout << "\n=== Account 2 ===\n";
    acc2.display();
    acc2.deposit(3000.0);
    acc2.withdraw(4000.0);

    return 0;
}
// ```

// **Output:**
// ```
// === Account 1 ===
// Account #1001 | Balance: Rs.5000
// Deposited Rs.2000 | New balance: Rs.7000
// Withdrew Rs.1500 | New balance: Rs.5500
// Insufficient funds.

// === Account 2 ===
// Account #1002 | Balance: Rs.12000
// Deposited Rs.3000 | New balance: Rs.15000
// Withdrew Rs.4000 | New balance: Rs.11000