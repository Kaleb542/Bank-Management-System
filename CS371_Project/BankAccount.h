#include "User.h"

#pragma once
#include <string>
using namespace std;

class BankAccount
{
private:
	int accountNumber;
	string accountType;
	double balance;
	User user;
public:
	BankAccount(int accountNumber, string accountType, double balance, User user);
	~BankAccount();

	int getAccountNumber();
	string getAccountType();
	double getBalance();
	string getUser();
};

