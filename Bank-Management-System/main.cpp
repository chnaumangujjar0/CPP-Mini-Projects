#include <iostream>
#include <vector>
using namespace std;

class BankAccount
{
public:
    string name;
    int accountNumber;
    double balance;

    BankAccount(string name, int accountNumber, double balance)
        : name(name), accountNumber(accountNumber), balance(balance) {}

    double deposit(double balance)
    {
        double deposit;
        cout << "\nEnter Amount for deposit: ";
        cin >> deposit;

        if (deposit <= 0)
        {
            cout << "\nInvalid amount for deposit";
            return balance;
        }

        balance += deposit;
        cout << "\nAmount deposited successfully!";
        cout << "\nYour current balance is " << balance;
        return balance;
    }

    double withdraw(double balance)
    {
        double withdrawAmount;
        cout << "\nEnter amount for withdraw: ";
        cin >> withdrawAmount;

        if (withdrawAmount > balance || withdrawAmount <= 0)
        {
            cout << "\nInvalid withdraw amount!";
            return balance;
        }

        balance -= withdrawAmount;
        cout << "\nAmount withdrawn successfully!";
        cout << "\nYour current balance is " << balance;
        return balance;
    }
};

// Create Account
void createAccount(vector<BankAccount> &account, int accountNumber)
{
    string name;
    double balance;

    cout << "\nEnter Name: ";
    cin >> name;

    cout << "Enter balance: ";
    cin >> balance;

    while (balance <= 0)
    {
        cout << "Invalid balance! Enter again: ";
        cin >> balance;
    }

    account.push_back(BankAccount(name, accountNumber, balance));

    cout << "\n=== Your Account Details ===";
    cout << "\nName: " << name;
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nBalance: " << balance << endl;
}

// Login Check
bool checkLogin(vector<BankAccount> &account, int number)
{
    for (BankAccount &s : account)
    {
        if (s.accountNumber == number)
        {
            return true;
        }
    }
    return false; 
}

int main()
{
    vector<BankAccount> account;

    int accountNumber = 0;
    int number;

    // LOGIN / SIGNUP LOOP
    while (true)
    {
        int mainchoice;

        cout << "\n1. Login";
        cout << "\n2. Sign Up";
        cout << "\nEnter choice: ";
        cin >> mainchoice;

        if (mainchoice == 1)
        {
            cout << "\nEnter Account Number: ";
            cin >> number;

            if (checkLogin(account, number))
            {
                break;
            }
            else
            {
                cout << "\nAccount not found!";
            }
        }
        else if (mainchoice == 2)
        {
            accountNumber++;
            createAccount(account, accountNumber);
        }
        else
        {
            cout << "\nInvalid choice!";
        }
    }

    cout << "\n--- You are Logged In ---";

    // MAIN MENU LOOP
    while (true)
    {
        int choice;

        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Check Balance";
        cout << "\n4. Logout";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (BankAccount &b : account)
            {
                if (b.accountNumber == number)
                {
                    b.balance = b.deposit(b.balance);
                }
            }
            break;

        case 2:
            for (BankAccount &b : account)
            {
                if (b.accountNumber == number)
                {
                    b.balance = b.withdraw(b.balance);
                }
            }
            break;

        case 3:
            for (BankAccount &b : account)
            {
                if (b.accountNumber == number)
                {
                    cout << "\nBalance = " << b.balance;
                }
            }
            break;

        case 4:
            cout << "\nLogged Out!\n";
            return 0;

        default:
            cout << "\nInvalid choice!";
        }
    }
}