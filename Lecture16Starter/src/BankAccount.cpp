#include "BankAccount.h"
#include "error.h"
using namespace std;

// Identify  the constructor.
BankAccount::BankAccount(string name, double amount){
    /* TODO: Fill in this method! */
    this->name = name;
    this->amount = amount;
}

void BankAccount::deposit(double depositAmount){
    /* TODO: Fill in this method! */
    if (depositAmount < 0) {
        error("Can't have negative money!")
    }
    amount += depositAmount;
}

void BankAccount::withdraw(double withdrawlAmount){
    /* TODO: Fill in this method! */
    if (withdrawlAmount < 0) {
        error("Can't have negative money!")
    }

    if (withdrawlAmount > amount) {
        error("Not enough money!")
    }
    
    amount -= withdrawlAmount;
}

void BankAccount::transfer(double transferAmount, BankAccount& recipient){
    /* TODO: Fill in this method! */
    withdraw(transferAmount);
    recipient.deposit(transferAmount);
}

/* These methods can be marked const because they don't modify the
 * contents of the bank account.
 */

double BankAccount::getAmount() const {
    /* TODO: Fill in this method! */
    return amount;
}

string BankAccount::getName() const {
    /* TODO: Fill in this method! */
    return name;
}
