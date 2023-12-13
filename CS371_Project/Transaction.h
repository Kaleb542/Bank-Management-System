#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "BankAccount.h"
using namespace std;

class Transaction
{
private:
	BankAccount* account;
	vector<string> transactions;
public:
	Transaction(BankAccount* accountPtr);
	~Transaction();

	void deposit(double amount);
	void withdraw(double amount);
	string PrintAccountSummary();
};

#endif