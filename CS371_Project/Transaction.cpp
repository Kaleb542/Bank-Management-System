#include "Transaction.h"
#include "BankAccount.h"

#include<iostream>
#include<iomanip>
#include<sstream>
#include <string>
#include <vector>
using namespace std;

Transaction::Transaction(BankAccount& account) :account(account) {
	cout << "Transaction Constructor. " << endl;
}

Transaction::~Transaction() {
	cout << "Transaction Destructor. " << endl;
}

void Transaction::deposit(double amount) {
	account.deposit(amount);
}

void Transaction::withdraw(double amount) {
	account.withdraw(amount);
}

string Transaction::PrintAccountSummary() {
	stringstream summary;
	summary << "\nTransaction History for Account #" << account.getAccountNumber() << ":\n";

	vector<string> transactions = account.getTransactions();
	for (const string& transaction : transactions) {
		summary << fixed << setprecision(2) << transaction + "\n"; // transaction is a string so setprecision does not work. leaving this here in case this changes
	}
	summary << fixed << setprecision(2) << "Current Balance: $" << account.getBalance() << "\n\n";
	return summary.str();
}
