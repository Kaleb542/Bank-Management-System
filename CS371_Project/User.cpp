#include "User.h"

#include<iostream>
#include <string>
using namespace std;

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