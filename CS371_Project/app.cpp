#include "User.h"
#include "BankAccount.h"
#include "ReadWrite.h"
#include "Transaction.h"

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

	// Testing Transactions
	//User user("KalebE", "password");
	//BankAccount acct(100001, "user", 500.44, user);
	//Transaction transaction(acct);
	//transaction.deposit(100.0);
	//transaction.withdraw(50.0);
	//transaction.deposit(1000.0);
	//transaction.PrintAccountSummary();


	// "UI" for the program, will only close on 4
	bool terminated = false;
	int input;

	string username;
	string password;
	int accNum = 0;
	string type;
	double balance = 0.00;

	ReadWrite userRead("users.txt");
	ReadWrite managerRead("managers.txt");

	User accountUser(username, password);
	BankAccount account(accNum, type, balance, accountUser);

	do {
		cout << "1. User Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Manager Login" << endl;
		cout << "4. Exit" << endl;
		cin >> input;

		switch (input) {
			case 1:
				cout << "What is your username?: ";
				cin >> username;
				accountUser.setUsername(username);

				cout << "What is your password?: ";
				cin >> password;
				accountUser.setPassword(password);

				// prints out the user's information based on their username and password
				if (userRead.read("users.txt", accountUser.getUsername()) && userRead.read("users.txt", accountUser.getPassword())) {
					account.setAccountNumber(stoi(userRead.getStringFromLine("users.txt", userRead.findLineNumber("users.txt", password) + 1)));
					cout << "Account number: " << account.getAccountNumber() << endl;
					account.setAccountType(userRead.getStringFromLine("users.txt", userRead.findLineNumber("users.txt", password) + 2));
					cout << "Account type: " << account.getAccountType() << endl;
					account.setBalance(stod(userRead.getStringFromLine("users.txt", userRead.findLineNumber("users.txt", password) + 3)));
					cout << "Account balance: $" << account.getBalance() << endl << endl;

					int input2;
					bool terminated2 = false;
					do {
						cout << "What would you like to do?" << endl;
						cout << "1. Check balance" << endl;
						cout << "2. Deposit" << endl;
						cout << "3. Withdraw" << endl;
						cout << "4. Make a Transaction" << endl;
						cout << "5. Display Transaction(s)" << endl;
						cout << "6. Quit" << endl;
						cin >> input2;

						switch (input2) {
							double amount;
							case 1:
								cout << "Balance: $" << account.getBalance() << endl << endl;
								break;
							case 2:
								cout << "How much do you want to deposit?: " << endl;
								cin >> amount;
								account.deposit(amount);
								cout << "$" << amount << " was deposited to your account." << endl << endl;
								break;
							case 3:
								cout << "How much do you want to withdraw?: " << endl;
								cin >> amount;
								account.withdraw(amount);
								cout << "$" << amount << " was withdrawn from your account." << endl << endl;
								break;
							case 4:
								// logic
								break;
							case 5:
								// logic
								break;
							case 6:
								terminated2 = true;
								break;
							default:
								cout << "Incorrect option, try again." << endl;
						}
					} while (!terminated2);
				} else {
					cout << "Incorrect username or password." << endl;
				}
				break;
			
			case 2:
				// logic
				break;
			case 3:
				// logic
				cout << "What is your username?: ";
				cin >> username;

				cout << "What is your password?: ";
				cin >> password;

				if (managerRead.read("managers.txt", username) && managerRead.read("managers.txt", password)) {
					// TODO: logic for bringing up all user information (usernames, passwords, account types, ids, balances)
				} else {
					cout << "Incorrect username or password." << endl;
				}
				break;
			case 4:
				terminated = true;
				break;
			default:
				cout << "Incorrect option, try again." << endl;
		}
	} while (!terminated);
}