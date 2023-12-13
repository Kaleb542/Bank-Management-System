#include "User.h"
#include "BankAccount.h"
#include "ReadWrite.h"
#include "Transaction.h"
#include "Manager.h"

#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main() {
	// instantiation of variables
	bool terminated = false;
	int input;

	string username;
	string password;
	int accNum = 0;
	string type;
	double balance = 0.00;

	string userText = "users.txt";					
	string managerText = "managers.txt";
	string transactionText = "transactions.txt";

	ReadWrite userRead(userText);
	ReadWrite managerRead(managerText);
	ReadWrite transactionRead(transactionText);

	User accountUser(username, password);
	Manager manager(username, password);
	BankAccount account(accNum, type, balance, accountUser);

	Transaction transaction(account);

	// "UI" for the program, will only close on 4
	do {
		cout << "1. User Login" << endl;
		cout << "2. Create Account" << endl;
		cout << "3. Manager Login" << endl;
		cout << "4. Exit" << endl;
		cin >> input;

		switch (input) {
			// TODO: putting line numbers into variables for ease of use
			// User Login
			case 1:
				cout << "What is your username?: ";
				cin >> username;
				accountUser.setUsername(username);

				cout << "What is your password?: ";
				cin >> password;
				accountUser.setPassword(password);

				// prints out the user's information based on their username and password
				if (userRead.read(userText, accountUser.getUsername()) && userRead.read(userText, accountUser.getPassword())) {
					account.setAccountNumber(stoi(userRead.getStringFromLine(userText, userRead.findLineNumber(userText, password) + 1)));
					cout << "Account number: " << account.getAccountNumber() << endl;
					account.setAccountType(userRead.getStringFromLine(userText, userRead.findLineNumber(userText, password) + 2));
					cout << "Account type: " << account.getAccountType() << endl;
					account.setBalance(stod(userRead.getStringFromLine(userText, userRead.findLineNumber(userText, password) + 3)));
					cout << "Account balance: $" << account.getBalance() << endl << endl;

					int input2;
					bool terminated2 = false;
					do {
						cout << "What would you like to do?" << endl;
						cout << "1. Check balance" << endl;
						cout << "2. Deposit" << endl;
						cout << "3. Withdraw" << endl;
						cout << "4. Display Transaction(s)" << endl;
						cout << "5. Quit" << endl;
						cin >> input2;

						switch (input2) {
							double amount;
							case 1:
								cout << fixed << setprecision(2) << "Balance: $" << account.getBalance() << endl << endl;
								break;
							case 2:
								cout << "How much do you want to deposit?: " << endl;
								cin >> amount;
								transaction.deposit(amount);
								cout << fixed << setprecision(2) << "$" << amount << " was deposited to your account." << endl << endl;
								userRead.write(userText, userRead.findLineNumber(userText, password) + 3, to_string(account.getBalance()));
								break;
							case 3:
								cout << "How much do you want to withdraw?: " << endl;
								cin >> amount;
								transaction.withdraw(amount);
								cout << fixed << setprecision(2) << "$" << amount << " was withdrawn from your account." << endl << endl;
								userRead.write(userText, userRead.findLineNumber(userText, password) + 3, to_string(account.getBalance()));
								break;
							case 4:
								cout << transaction.PrintAccountSummary();
								break;
							case 5:
								terminated2 = true;
								break;
							default:
								cout << "Incorrect option, try again." << endl;
						}

					} while (!terminated2);
				} else {
					cout << "Incorrect username or password." << endl;
				}
				// Write transactions to a file, timestamped
				transactionRead.append(transactionText, transaction.PrintAccountSummary());
				break;

			// Create account
			case 2:
				cout << "Enter a username: " << endl;
				cin >> username;
				cout << "Enter a password: " << endl;
				cin >> password;
				cout << "Enter an account number (integer): " << endl;
				cin >> accNum;

				type = "user";
				balance = 0.00;
				accountUser.createAccount(username, password, accNum, type, balance);
				break;

			// Manager
			case 3:
				// logic
				cout << "What is your username?: ";
				cin >> username;

				cout << "What is your password?: ";
				cin >> password;

				if (managerRead.read(managerText, username) && managerRead.read(managerText, password)) {
					// TODO: logic for bringing up all user information (usernames, passwords, account types, ids, balances)
					int inputManager;
					bool terminatedManager = false;
					string tempUsername;

					do {
						cout << "What do you want to do?" << endl;
						cout << "1. Delete an account." << endl;
						cout << "2. See all user information." << endl;
						cout << "3. Quit." << endl;
						cin >> inputManager;

						switch (inputManager) {
							case 1:
								cout << "Enter the username you want to delete: " << endl;
								cin >> tempUsername;

								manager.deleteAccount(userText, tempUsername);
								break;
							case 2:
								cout << "Displaying all user information." << endl;
								userRead.readAll(userText);
								break;
							case 3:
								terminatedManager = true;
								break;
							default:
								cout << "Invalid option, try again." << endl;
						}
					} while (!terminatedManager);
				} else {
					cout << "Incorrect username or password." << endl;
				}
				break;
			// Quit
			case 4:
				terminated = true;
				break;
			default:
				cout << "Incorrect option, try again." << endl;
		}
	} while (!terminated);
}