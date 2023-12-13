#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "BankAccount.h"
using namespace std;

class Transaction
{
private:
	BankAccount account;
public:
	Transaction(const BankAccount& account);
	~Transaction();

	void deposit(double amount);
	void withdraw(double amount);
	void PrintAccountSummary();
};

#endif