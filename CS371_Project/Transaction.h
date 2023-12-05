#pragma once
#include <string>
using namespace std;

class Transaction
{
private:
	//string transactions[10][10][10];
	//int transactionNumber;
public:
	// *Add constructor and destructor*
	// *Add getter functions for private data members*

	void deposit(double amount);
	void withdraw(double amount);
	void PrintAccountSummary();
};

