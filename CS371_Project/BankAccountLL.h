#ifndef BANKACCOUNTLL_H
#define BANKACCOUNTLL_H

#include "BankAccount.h"
#include "BankAccountNode.h"

#include <string>

	
class BankAccountLL 
{
protected:
	BankAccountNode* head;
	BankAccountNode* tail;

public:
	BankAccountLL();					// Default Constructor		- creates default bank account as first item
	~BankAccountLL();					// Destructor				- needs to traverse and delete

	void addAccount(BankAccount& acc);												// Adds account using an already created BankAccount
	void removeAccount(int accountNumber);												// Deletes account based on account number
	BankAccount getAccount(int accountNumber);											// Retrives account based on account number
};

#endif
