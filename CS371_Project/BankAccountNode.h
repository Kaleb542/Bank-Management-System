#ifndef BANKACCOUNTNODE_H
#define BANKACCOUNTNODE_H

#include "BankAccount.h"

#include <string>


class BankAccountNode
{
protected:
	BankAccountNode* prev;
	BankAccountNode* next;
	BankAccount acc;

public:
	BankAccountNode();						// Default Constructor		- creates Node with empty BankAccount object
	BankAccountNode(BankAccount account);	// Parameter Constructor	- creates Node using BankAccount object
	~BankAccountNode();						// Destructor

	void setNext(BankAccountNode* n);	// Sets next node pointer
	void setPrev(BankAccountNode* p);	// Sets previous node pointer

	BankAccountNode* getNext();		// Returns pointer to the next node
	BankAccountNode* getPrev();		// Returns pointer to the previous node

	BankAccount getAccount();		// Returns BankAccount linked to node
};


#endif
