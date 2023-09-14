#include <iostream>
using namespace std;

class BankAccount {
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

int main() {
    double initialBalance;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(initialBalance);

    double depositAmount, withdrawAmount;

    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "Enter withdrawal amount: ";
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    cout << "Current balance: " << account.getBalance() << endl;

    return 0;
}
