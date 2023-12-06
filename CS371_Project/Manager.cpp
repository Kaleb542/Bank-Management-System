#include "Manager.h"
#include<iostream>
#include <string>
using namespace std;

Manager::Manager(string username, string password) {
	cout << "Manager constructor." << endl;
}

Manager::~Manager() {
	cout << "Manager destructor" << endl;
}

string Manager::getUsername() const {
	return username;
}

string Manager::getPassword() const {
	return password;
}