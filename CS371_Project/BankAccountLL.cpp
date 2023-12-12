#include "BankAccountLL.h"

#include<iostream>
#include<string>

using namespace std;

// Constructors and Destructor
BankAccountLL::BankAccountLL() {
	head = nullptr;
	tail = nullptr;
}

BankAccountLL::~BankAccountLL() {
	BankAccountNode* curr = head;
	BankAccountNode* del = head;

	while (curr) {
		del = curr;
		curr = curr->getNext();
		delete del;
	}
}

// Methods
void BankAccountLL::addAccount(BankAccount& acc) {
	BankAccountNode* node = new BankAccountNode(acc);
	
	// Special Case for first node - nullptr errors
	if (head == nullptr) {
		head = node;
		node->setNext(nullptr);
		node->setPrev(nullptr);
		cout << "Account " << acc.getAccountNumber() << " has been added.";
		return;
	}

	BankAccountNode* curr = head;
	BankAccountNode* next = curr->getNext();

	while (next) {
		curr = next;
		next = curr->getNext();
		cout << curr->getAccount().getAccountNumber() << endl;
	}
	node->setNext(nullptr);
	node->setPrev(curr);

	curr->setNext(node);

	cout << "Account " << acc.getAccountNumber() << " has been added." << endl;
}

void BankAccountLL::removeAccount(int accountNumber) {
	BankAccountNode* curr = head;
	BankAccount acc = curr->getAccount();

	// Iterate through list to find number
	while (acc.getAccountNumber() != accountNumber && curr) {
		curr = curr->getNext();
		acc = curr->getAccount();
	}
	
	// Transfer pointers for previous/next nodes to each other and delete current
	if (acc.getAccountNumber() == accountNumber) {
		curr->getNext()->setPrev(curr->getPrev());
		curr->getPrev()->setNext(curr->getNext());
		delete curr;
	}
	else {
		cout << "Did not find account " << accountNumber << " in the list. Unable to delete." << endl;
	}
}

BankAccount BankAccountLL::getAccount(int accountNumber) {
	BankAccountNode* curr = head;
	BankAccount acc = curr->getAccount();

	// Iterate through list to find number
	while (acc.getAccountNumber() != accountNumber && curr) {
		curr = curr->getNext();
		if (curr) { acc = curr->getAccount(); } // to avoid nullptr errors
	}

	if (acc.getAccountNumber() == accountNumber) {
		return acc;
	}
	else {
		cout << "Did not find account " << accountNumber << endl;
		return BankAccount();
	}
}
