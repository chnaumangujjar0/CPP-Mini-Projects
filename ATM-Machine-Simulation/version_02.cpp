#include <iostream>
#include <vector>
using namespace std;

class ATM
{
public:
    string name;
    int pin;
    double balance;
    int accountNumber;

    ATM(string name, int pin, double balance, int accountNumber)
        : name(name), pin(pin), balance(balance), accountNumber(accountNumber) {}

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

class UserSystem
{
private:
    vector<ATM> users;

public:
    void createAccount(string name, int pin, double balance, int accountNumber)
    {
        users.push_back(ATM(name, pin, balance, accountNumber));
        cout << "\nAccount created successfully!";
        cout << "\nAccount Number: " << accountNumber;
    }

    ATM* login(int accountNumber, int pin)
    {
        for (ATM &u : users)
        {
            if (u.accountNumber == accountNumber)
            {
                if (u.checkLogin(pin))
                {
                    return &u;
                }
                else
                {
                    return nullptr;
                }
            }
        }
        cout << "\nAccount not found!";
        cout << "\nPlease login again or create a new account.";
        return nullptr;
    }
    
};

int main()
{
    UserSystem system;

    ATM* currentUser = nullptr;

    int accountNumber = 1000;
    bool isLoggedIn = false;
    int attempts = 0;

    while (true)
    {
        // LOGIN / SIGNUP LOOP
        while (!isLoggedIn)
        {
            int choice;
            cout << "\n1. Login";
            cout << "\n2. Sign Up";
            cout << "\n3. Exit";
            cout << "\nEnter Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                int acc, pin;

                while (attempts < 3 && !isLoggedIn)
                {
                    cout << "\nEnter Account Number: ";
                    cin >> acc;

                    cout << "\n Enter PIN: ";
                    cin >> pin;

                    currentUser = system.login(acc, pin);

                    if (currentUser != nullptr)
                    {
                        isLoggedIn = true;
                        cout<<"\n Welcome "<<currentUser->name;
                    }
                    attempts++;


                    
                }
                break;
            }

            case 2:
            {
                string name;
                int pin;
                double balance;

                cout << "\nEnter Name: ";
               cin.ignore();
               getline(cin,name);

                cout << "Enter PIN: ";
                cin >> pin;
                while(pin < 1000 || pin > 9999){
                    cout<<"\n Enter Pin : ";
                    cin>>pin;
                    cout<<"\n PIN must be exactly 4 digits.";
                }
                cout << "Enter Balance: ";
                cin >> balance;

                accountNumber++;
                system.createAccount(name, pin, balance, accountNumber);
                cout << "\nYou can now login using your account number.";
                break;
            }

            case 3:
                cout << "\nExited!";
                return 0;

            default:
                cout << "\nInvalid choice!";
            }

            if (attempts >= 3)
            {
                cout << "\nToo many failed attempts!";
                return 0;
            }
        }

        cout << "\n--- You are Logged In ---";

        // MENU LOOP
        while (isLoggedIn)
        {
            int choice;
            double amount;

            cout << "\n1. Check Balance";
            cout << "\n2. Withdraw";
            cout << "\n3. Deposit";
            cout << "\n4. Change PIN";
            cout << "\n5. Logout";
            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                currentUser->displayBalance();
                break;

            case 2:
                cout << "\nEnter amount: ";
                cin >> amount;
                currentUser->withdrawBalance(amount);
                break;

            case 3:
                cout << "\nEnter amount: ";
                cin >> amount;
                currentUser->depositBalance(amount);
                break;

            case 4:
            {
                int newPin;
                cout << "\nEnter new PIN: ";
                cin >> newPin;
                currentUser->changePin(newPin);
                break;
            }
            case 5:
                isLoggedIn = false;
                attempts = 0;
                currentUser = nullptr;
                cout << "\nLogged out!";
                break;
            default:
                cout << "\nInvalid choice!";
            }
        }
    }
}