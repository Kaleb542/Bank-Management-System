#include "User.h"

#pragma once
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
private:
	int accountNumber;
	string accountType;
	double balance;
	User user;
	vector<string> transactions;
public:
	BankAccount(int accountNumber, string accountType, double balance, const User& user);
	~BankAccount();

	int getAccountNumber();
	string getAccountType();
	double getBalance();
	string getUser();

	void deposit(double amount);
	void withdraw(double amount);
	void addTransaction(string transaction);
	vector<string> getTransactions();
};

