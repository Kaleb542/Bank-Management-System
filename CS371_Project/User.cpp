#include "User.h"
#include "ReadWrite.h"

#include<iostream>
#include <string>
using namespace std;

User::User() {}

User::User(string username, string password) :username(username), password(password) {
	cout << "User Constructor. " << endl;
}

User::~User() {
	cout << "User Destructor. " << endl;
}

string User::getUsername() {
	return username;
}

string User::getPassword() {
	return password;
}

void User::setUsername(string user) {
	username = user;
}

void User::setPassword(string pass) {
	password = pass;
}

void User::createAccount(string username, string password, int accountNum, string accType, double balance) const {
	ReadWrite rw("users.txt");

	rw.append("users.txt", "");
	rw.append("users.txt", username);
	rw.append("users.txt", password);
	rw.append("users.txt", to_string(accountNum));
	rw.append("users.txt", accType);
	rw.append("users.txt", to_string(balance));
}