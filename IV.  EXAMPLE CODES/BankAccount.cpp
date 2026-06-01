#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {   // FIX 1: constructor to init balance
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : BankAccount(initialBalance) {    // FIX 2: pass balance up to parent
        interestRate = rate;               // FIX 3: initialize interestRate
    }

    void applyInterest() {                 // FIX 4: void, not double — it updates, not returns
        double interest = getBalance() * interestRate;
        deposit(interest);                 // FIX 5: actually add the interest
    }
};

int main() {
    SavingsAccount acc(1000, 0.05);  // 1000 balance, 5% interest
    acc.applyInterest();
    cout << acc.getBalance();        // should print 1050
}