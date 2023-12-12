#include "BankAccountNode.h"

#include <string>
#include <iostream>

using namespace std;

BankAccountNode::BankAccountNode() {
	next = nullptr;
	prev = nullptr;
	acc = BankAccount();
}
BankAccountNode::BankAccountNode(BankAccount account) {
	next = nullptr;
	prev = nullptr;
	acc = account;
}
BankAccountNode::~BankAccountNode() {
	cout << "BankAccountNode deleted." << endl;
}

void BankAccountNode::setNext(BankAccountNode* n) {	next = n; }
void BankAccountNode::setPrev(BankAccountNode* p) { prev = p; }

BankAccountNode* BankAccountNode::getNext() { return next; }
BankAccountNode* BankAccountNode::getPrev() { return prev; }

BankAccount BankAccountNode::getAccount() { return acc; }