#include <iostream>
using namespace std;

class ATM
{
private:
    int pin;
    double balance;

public:
    ATM(int pin, double balance) : pin(pin), balance(balance) {}

    bool checkLogin(int enteredPin)
    {
        if (enteredPin == pin)
        {
            cout << "\nAccess granted!";
            return true;
        }
        else
        {
            cout << "\nAccess denied, wrong PIN.";
            return false;
        }
    }

    void displayBalance() const
    {
        cout << "\nYour Current Balance is " << balance;
    }

    void depositBalance(double deposit)
    {
        if (deposit <= 0)
        {
            cout << "\nEnter valid amount for deposit.";
            return;
        }

        balance += deposit;
        cout << "\nDeposit successful!";
        cout << "\nCurrent balance: " << balance;
    }

    void withdrawBalance(double withdraw)
    {
        if (withdraw <= 0)
        {
            cout << "\nEnter valid amount!";
            return;
        }

        if (withdraw > balance)
        {
            cout << "\nInsufficient Balance!";
            return;
        }

        balance -= withdraw;
        cout << "\nAmount Withdrawn Successfully!";
        cout << "\nCurrent balance: " << balance;
    }

    void changePin(int newPin)
    {
        if (newPin < 1000 || newPin > 9999)
        {
            cout << "\nPIN must be 4 digits.";
            cout << "\nYour PIN is not changed. Try again!";
            return;
        }

        pin = newPin;
        cout << "\nYour PIN updated successfully!";
    }
};

int main()
{
    ATM atm(5271, 10000);

    bool isLoggedIn = false;
    int pin;
    double amount;
    int attempts = 0;

    while (true)
    {
        // Login Loop
        while (!isLoggedIn)
        {
            int choice;
            cout << "\n1. Login";
            cout << "\n2. Exit";
            cout << "\nEnter Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                while (attempts < 3 && !isLoggedIn)
                {
                    cout << "\nEnter PIN: ";
                    cin >> pin;
                    isLoggedIn = atm.checkLogin(pin);
                    attempts++;
                }
                break;

            case 2:
                cout << "\nExited!";
                return 0;

            default:
                cout << "\nInvalid choice!";
                break;
            }

            if (attempts >= 3)
            {
                cout << "\nYou have run out of attempts.";
                cout << "\nTry again later.";
                return 0;
            }
        }

        // Menu Loop
        while (isLoggedIn)
        {
            int choice;
            cout << "\n1. Check Balance";
            cout << "\n2. Withdraw Balance";
            cout << "\n3. Deposit Balance";
            cout << "\n4. Change PIN";
            cout << "\n5. Logout";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                atm.displayBalance();
                break;

            case 2:
                cout << "\nEnter amount to withdraw: ";
                cin >> amount;
                atm.withdrawBalance(amount);
                break;

            case 3:
                cout << "\nEnter amount to deposit: ";
                cin >> amount;
                atm.depositBalance(amount);
                break;

            case 4:
            {
                int newPin;
                cout << "\nEnter new PIN: ";
                cin >> newPin;
                atm.changePin(newPin);
                break;
            }

            case 5:
                isLoggedIn = false;
                attempts = 0;
                cout << "\nLogged out!";
                break;

            default:
                cout << "\nInvalid choice!";
                break;
            }
        }
    }
}