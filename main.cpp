#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "password.h"

using namespace std;

void logAction(const string &message)
{
    ofstream logFile("bank_log.txt", ios::app);

    if (logFile.is_open())
    {
        logFile << "LOG: " << message << endl;
        logFile.close();
    }
}

void Ispasswordright()
{
    int psw;
    cout << "Please enter the password: ";
    cin >> psw;
    if (psw == password)
    {
        logAction("------------------------------------------------");
        logAction("Password is correct. Access granted.");
        cout << "Password is correct. Access granted." << endl;
    }
    else
    {
        logAction("------------------------------------------------");
        for (int i = 0; i < 3; i++)
        {
            logAction("Incorrect password attempt: " + to_string(psw));
            cout << "Incorrect password. Please try again (you have " << 3 - i << " attempts left): ";
            cin >> psw;
            if (psw == password)
            {
                logAction("Password is correct. Access granted.");
                cout << "Password is correct. Access granted." << endl;
                break;
            }
            else if (i == 2)
            {
                logAction("Access denied due to incorrect password.");
                logAction("------------------------------------------------");
                throw runtime_error("Access denied due to incorrect password.");
            }
        }
    }
}

class Account
{
private:
    string accountowner;
    int accountnumber;
    double accountbalance;

public:
    Account(string accountowner, int accountnumber, double accountbalance)
    {
        this->accountowner = accountowner;
        this->accountnumber = accountnumber;
        this->accountbalance = accountbalance;
    }

    void showinfo()
    {
        cout << "Account Owner: " << accountowner << endl;
        cout << "Account Number: " << accountnumber << endl;
        cout << "Account Balance: " << accountbalance << " $ " << endl;
    }

    void deposit(double amount)
    {
        if (amount < 0)
        {
            logAction("Attempted to deposit a negative amount: " + to_string(amount));
            logAction("------------------------------------------------");
            throw runtime_error("Deposit amount cannot be negative. It's a suspicious process. The bank account is blocked.");
        }
        else
        {
            accountbalance += amount;
            cout << "Deposited: " << amount << " $ " << endl;
            cout << "New Balance: " << accountbalance << " $ " << endl;
            logAction("Deposited: " + to_string(amount) + " $  ||   New Balance: " + to_string(accountbalance) + " $");
        }
    }

    void withdraw(double amount)
    {
        if (amount < 0)
        {
            logAction("Attempted to withdraw a negative amount: " + to_string(amount));
            logAction("------------------------------------------------");
            throw runtime_error("Withdrawal amount cannot be negative. It's a suspicious process. The bank account is blocked.");
        }
        else if (amount > accountbalance)
        {
            logAction("Attempted to withdraw more than available balance: " + to_string(amount) + " $    ||   Available Balance: " + to_string(accountbalance));
            logAction("------------------------------------------------");
            throw runtime_error("Insufficient funds for withdrawal.");
        }
        else
        {
            accountbalance -= amount;
            cout << "Withdrew: " << amount << " $ " << endl;
            cout << "New Balance: " << accountbalance << " $ " << endl;
            logAction("Withdrew: " + to_string(amount) + " $    ||   New Balance: " + to_string(accountbalance) + " $");
        }
    }
};

int main()
{
    cout << "**** Welcome to the Bank Account Management System! ****" << endl;
    try
    {
        Ispasswordright();
    }
    catch (const exception &error)
    {
        cout << error.what() << endl;
        return 1;
    }
    Account account1("John Doe", 123456, 1000.50);
    cout << "Welcome to your account, " << "Mr. John Doe!" << endl;
    account1.showinfo();
    for (;;)
    {
        cout << "Enter your choice(you must enter 1, 2 or 3(exit)): " << endl;

        cout << "1. Deposit                                   2. Withdraw                  3. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            float amount1;
            cout << "Enter the amount you want to deposit: ";
            cin >> amount1;
            try
            {
                account1.deposit(static_cast<double>(amount1));
            }
            catch (const exception &error)
            {
                cout << error.what() << endl;
                return 1;
            }
        }
        else if (choice == 2)
        {
            float amount2;
            cout << "Enter the amount you want to withdraw: ";
            cin >> amount2;
            try
            {
                account1.withdraw(static_cast<double>(amount2));
            }
            catch (const exception &error)
            {
                cout << error.what() << endl;
                return 1;
            }
        }
        else if (choice == 3)
        {
            logAction("User exited the program.");
            logAction("------------------------------------------------");
            cout << "Exiting the program. Thank you for using the Bank Account Management System!" << endl;
            return 0;
        }

        else
        {
            logAction("Invalid choice. It's a suspicious process. The bank account is blocked.");
            logAction("------------------------------------------------");
            cout << "Invalid choice. It's a suspicious process. The bank account is blocked." << endl;
            return 1;
        }
    }
    return 0;
}
