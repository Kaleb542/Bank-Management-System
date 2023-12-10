#include <iostream>
#include <fstream>
#include <string>
#include "ReadWrite.h"
using namespace std;

ReadWrite::ReadWrite(const string& filename) {}

ReadWrite::~ReadWrite() {}

bool ReadWrite::read(const string& filename, const string& targetString) const {
	ifstream inputFile(filename);

	// Error out if the file cannot be opened
	if (!inputFile.is_open()) {
		cerr << "Error opening the file." << endl;
		return false;
	}

	string searchString = targetString;
	string line;

	while (getline(inputFile, line)) {
		int found = line.find(searchString);

		if (found != string::npos) {
			cout << "Found string: " << searchString << endl;
			return true;
			break;
		}
	}

	inputFile.close();
}

int ReadWrite::findLineNumber(const string& filename, const string& target) const {
	ifstream inputFile(filename);

	// Error out if the file cannot be opened
	if (!inputFile.is_open()) {
		cerr << "Error opening the file." << endl;
		return -1;
	}

	string line;
	int lineNumber = 0;

	while (getline(inputFile, line)) {
		lineNumber++;

		// check if target is found in the current line
		int found = line.find(target);
		if (found != string::npos) {
			inputFile.close();
			return lineNumber;
		}
	}

	inputFile.close();

	// if the string is not found, return -1
	return -1;
}

string ReadWrite::getStringFromLine(const string& filename, int lineNumber) const {
	ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		cerr << "Error opening the file." << endl;
		return "";
	}

	string line;
	int currentLine = 0;

	while (getline(inputFile, line)) {
		currentLine++;

		if(currentLine == lineNumber) {
			inputFile.close();
			return line;
		}
	}

	inputFile.close();

	return "";
}