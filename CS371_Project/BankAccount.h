#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "User.h"

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

	void setAccountNumber(int num);
	void setAccountType(string type);
	void setBalance(double balance);
	void setUser(User& user);

	void deposit(double amount);
	void withdraw(double amount);
	void addTransaction(string transaction);
	vector<string> getTransactions();
};

#endif
