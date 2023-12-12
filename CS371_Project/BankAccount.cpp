#include "BankAccount.h"

#include<iostream>
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

void BankAccount::deposit(double amount) {
	balance += amount;
	addTransaction("Deposit: +" + to_string(amount));
}

void BankAccount::withdraw(double amount) {
	if (amount > balance) {
		cout << "You have insufficient funds. ";
	}
	else {
		balance -= amount;
		addTransaction("Withdrawal: -" + to_string(amount));
	}
}

void BankAccount::addTransaction(string transaction) {
	transactions.push_back(transaction);
}

vector<string> BankAccount::getTransactions() {
	return transactions;
}
