/******************************************************
 * File: BankAccount.h
 *
 * A class representing a bank account, which stores the
 * account holder's name and current amount balance.
 */
#pragma once

#include <string>

using namespace std;

class BankAccount {
public:
    // Constructor
	BankAccount(string name, double amount);
    // Functions
    void deposit(double depositAmount);
    void withdraw(double withdrawlAmount);
    void transfer(double transferAmount, BankAccount& recipient);
    
    /* These functions are marked const because they don't change the
     * account.
     */
    // variables
    double getAmount() const;
    string getName() const;

private:
    /* TODO: Fill in these private member variables! */
    string name;
    double amount;
};
