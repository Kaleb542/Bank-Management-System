#include "BankAccount.h"

#include<iostream>
#include <string>
using namespace std;

BankAccount::BankAccount(int accountNumber, string accountType, double balance, User user) :accountNumber(accountNumber), accountType(accountType), balance(balance), user(user) {
	cout << "BankAccount Constructor. " << endl;
}

BankAccount::~BankAccount() {
	cout << "BankAccount Destructor. " << endl;
}

int BankAccount::getAccountNumber() {
	return accountNumber;
}

string BankAccount::getAccountType() {
	return accountType;
}

double BankAccount::getBalance() {
	return balance;
}

string BankAccount::getUser() {
	return user.getUsername();
}
