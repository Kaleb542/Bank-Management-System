#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
			//cout << "Found string: " << searchString << endl;
			return true;
			break;
		}
	}

	inputFile.close();

	return false;
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

void ReadWrite::append(const string& filename, string newString) const {
	// open a file in append mode
	ofstream outFile(filename, ios::app);

	// check if file is open already
	if (!outFile.is_open()) {
		cerr << "Error opening the file." << endl;
		return;
	}

	// append string to the end of the file
	outFile << newString << endl;

	outFile.close();
	return;
}

void ReadWrite::write(const string& filename, int lineNum, const string& newString) const {
	ifstream inFile(filename);

	if (!inFile.is_open()) {
		cerr << "Error opening the file." << endl;
		return;
	}

	vector<string> lines;
	string line;
	while (getline(inFile, line)) {
		lines.push_back(line);
	}

	inFile.close();

	// check if line number is valid
	if (lineNum < 1 || lineNum > lines.size()) {
		cerr << "Invalid line number" << endl;
		return;
	}

	lines[lineNum - 1] = newString;

	// write the modified string back to the file
	ofstream outFile(filename);

	if (!outFile.is_open()) {
		cerr << "Error opening the file for writing." << endl;
		return;
	}

	for (const string& updatedLine : lines) {
		outFile << updatedLine << endl;
	}

	outFile.close();
}