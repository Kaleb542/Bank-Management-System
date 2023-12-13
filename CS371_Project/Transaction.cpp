#include "Transaction.h"
#include "BankAccount.h"

#include<iostream>
#include <string>
#include <vector>
using namespace std;

Transaction::Transaction(const BankAccount& account) :account(account) {
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
	string summary;
	summary += "\nTransaction History for Account #" + to_string(account.getAccountNumber()) + ":\n";

	//cout << endl << "Transaction History for Account #" << account.getAccountNumber() << ":" << endl;
	vector<string> transactions = account.getTransactions();
	for (const string& transaction : transactions) {
		//cout << transaction << endl;
		summary += transaction + "\n";
	}
	//cout << "Current Balance: $" << account.getBalance() << endl << endl;
	summary += "Current Balance: $" + std::to_string(account.getBalance()) + "\n\n";
	return summary;
}
