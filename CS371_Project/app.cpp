#include "User.h"
#include "BankAccount.h"

#include<iostream>
using namespace std;

int main() {
	// Testing User class
	User user("KalebE", "password");
	cout << "UserName: " << user.getUsername() << endl;
	cout << "Password: " << user.getPassword() << endl;

	// Testing BankAccount class
	BankAccount acct(100001, "user", 901.47, user);
	cout << "Account Number: " << acct.getAccountNumber() << endl;
	cout << "Account Type: " << acct.getAccountType() << endl;
	cout << "Balance: " << acct.getBalance() << endl;
	cout << "User: " << acct.getUser() << endl;
}