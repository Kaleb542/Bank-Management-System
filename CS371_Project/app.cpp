#include "User.h"
#include "BankAccount.h"
#include "ReadWrite.h"

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

	// "UI" for the program, will only close on 4
	bool terminated = false;
	int input;

	string username;
	string password;
	string id;
	string type;
	string balance;

	ReadWrite userRead("users.txt");

	do {
		cout << "1. User Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Manager Login" << endl;
		cout << "4. Exit" << endl;
		cin >> input;

		switch (input) {
			case 1:
				// logic
				cout << "What is your username?: ";
				cin >> username;

				cout << "What is your password?: ";
				cin >> password;

				// prints out the user's information based on their username and password
				if (userRead.read("users.txt", username) && userRead.read("users.txt", password)) {
					id = userRead.getStringFromLine("users.txt", userRead.findLineNumber("users.txt", password) + 1);
					cout << "ID: " << id << endl;
					type = userRead.getStringFromLine("users.txt", userRead.findLineNumber("users.txt", password) + 2);
					cout << "Account type: " << type << endl;
					balance = userRead.getStringFromLine("users.txt", userRead.findLineNumber("users.txt", password) + 3);
					cout << "Account type: " << balance << endl << endl;
				}
				else {
					cout << "Incorrect username or password." << endl;
				}
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