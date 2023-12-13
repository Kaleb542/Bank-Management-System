#include "Manager.h"
#include "ReadWrite.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Manager::Manager(string username, string password) {
	cout << "Manager constructor." << endl;
}

Manager::~Manager() {
	cout << "Manager destructor" << endl;
}

/*
* deleteAccount() will delete the 6 lines of strings that is related to their account info
* If the username exists, execute
* Else through an error
* Uses two files to remove lines from the users.txt file
* users file gets deleted, temporary file is renamed to users.txt
* very janky but it works i guess
*/
void Manager::deleteAccount(const string& filename, string username) const {
	ReadWrite rw("users.txt");

	if (rw.read("users.txt", username)) {
		ifstream inFile("users.txt");
		ofstream tempFile("temp.txt");

		if (!inFile || !tempFile) {
			cerr << "Error opening files!" << endl;
			return;
		}

		string line;
		int linesToDelete = rw.findLineNumber("users.txt", username) + 5;
		int currentLine = 0;

		while (getline(inFile, line)) {
			currentLine++;

			if (currentLine < rw.findLineNumber("users.txt", username) || currentLine > linesToDelete) {
				tempFile << line << endl;
			}
		}

		inFile.close();
		tempFile.close();

		if (remove("users.txt") != 0) {
			cerr << "Error deleting the original file." << endl;
			return;
		}

		if (rename("temp.txt", "users.txt") != 0) {
			cerr << "Error renaming temp file." << endl;
			return;
		}
	} else {
		cerr << "Error, could not find user with that username." << endl;
		return;
	}

	return;
}