#include "BankAccount.h"

#include<iostream>
#include<iomanip>
#include<sstream>
#include <string>
using namespace std;

BankAccount::BankAccount(int accountNumber, string accountType, double balance, const User& user) :accountNumber(accountNumber), accountType(accountType), balance(balance), user(user) {
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

void BankAccount::setAccountNumber(int num) {
	accountNumber = num;
}
void BankAccount::setAccountType(string type) {
	accountType = type;
}
void BankAccount::setBalance(double balance) {
	this->balance = balance;
}
void BankAccount::setUser(User& user) {
	this->user = user;
}

stringstream BankAccount::deposit(double amount) {
	stringstream dep;
	balance += amount;

	// Transaction log
	dep << fixed << setprecision(2) << "Deposit: +" << amount;
	return dep;
}

stringstream BankAccount::withdraw(double amount) {
	stringstream wd;
	if (amount > balance) {
		cout << "You have insufficient funds. ";
		wd << "Insufficient funds for transaction.";
	}
	else {
		balance -= amount;

		// Transaction log
		wd << fixed << setprecision(2) << "Withdraw: -" << amount;
	}
	return wd;
}
