#include "Transaction.h"
#include "BankAccount.h"

#include<iostream>
#include<iomanip>
#include<sstream>
#include <string>
#include <vector>
using namespace std;

Transaction::Transaction(BankAccount* accountPtr) :account(accountPtr) {
	cout << "Transaction Constructor. " << endl;
}

Transaction::~Transaction() {
	cout << "Transaction Destructor. " << endl;
}

void Transaction::deposit(double amount) {
	string transaction = account->deposit(amount).str();
	transactions.push_back(transaction);
}

void Transaction::withdraw(double amount) {
	string transaction = account->withdraw(amount).str();
	transactions.push_back(transaction);
}

string Transaction::PrintAccountSummary() {
	stringstream summary;
	summary << "\nTransaction History for Account #" << account->getAccountNumber() << ":\n";

	for (const string& transaction : transactions) {
		summary << fixed << setprecision(2) << transaction + "\n"; // transaction is a string so setprecision does not work. leaving this here in case this changes
	}
	summary << fixed << setprecision(2) << "Current Balance: $" << account->getBalance() << "\n\n";
	return summary.str();
}
