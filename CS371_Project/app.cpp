#include "User.h"
#include "BankAccount.h"

#include<iostream>
using namespace std;

int main() {
	//// Testing User class
	//User user("KalebE", "password");
	//cout << "UserName: " << user.getUsername() << endl;
	//cout << "Password: " << user.getPassword() << endl;

	//// Testing BankAccount class
	//BankAccount acct(100001, "user", 901.47, user);
	//cout << "Account Number: " << acct.getAccountNumber() << endl;
	//cout << "Account Type: " << acct.getAccountType() << endl;
	//cout << "Balance: " << acct.getBalance() << endl;
	//cout << "User: " << acct.getUser() << endl;

	// "UI" for the program, will only close on
	bool terminated = false;
	int input;

	do {
		cout << "1. User Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Manager Login" << endl;
		cout << "4. Exit" << endl;
		cin >> input;

		switch (input) {
			case 1:
				// logic
				break;
			case 2:
				// logic
				break;
			case 3:
				// logic
				break;
			case 4:
				terminated = true;
				break;
			default:
				cout << "Incorrect option, try again." << endl;
		}
	} while (!terminated);
}