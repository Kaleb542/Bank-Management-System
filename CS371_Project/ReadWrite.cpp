#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ReadWrite.h"
using namespace std;

ReadWrite::ReadWrite(const string& filename) {}

ReadWrite::~ReadWrite() {}

/*
* read() returns a true or false value depending on if the targetString is in the file
* Errors out if the file cannot be opened and returns false
* Iterates through the lines, storing them in the line variable
* If it is found in the current line, return true and break from the function
* Otherwise it returns false
*/
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

/*
* findLineNumber() finds the line number based on a string that you give it
* Errors out if the file cannot be opened
* Iterates through the file, recording the current line in the line variable
* If the string is found, return the line number that it is in
* Else return -1, as it was not found
*/
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

/*
* getStringFromLine() returns a string using a line number (can be found with findLineNumber())
* Errors out if you cannot open the file
* Iterates through the lines, saving the current line in currentLine
* If the currentLine is equal to the lineNumber that we are looking for, return line
* Else return an empty string as it was not found
*/
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

/*
* append() writes text to the end of a file by opening a file in append mode from ofstream
* Errors out if you cannot open the file
* Appends the newString to the end of the file
*/
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

/*
* write() will write a string to a text file based on what line number you give it and newString
* Errors out if the file cannot be opened
* Stores the lines in a vector of type string
* Reads in each line and appends into the lines vector
* Checks if the line number is valid
* Modifies content of the specific line with the new string
* Opens the file for output
* Errors out if the file cannot be opened
* Iterates over modified lines and writes them, with the new string to the output file
*/
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

/*
* readAll() iterates through all of the lines within a text file
* It prints them out in order
*/
void ReadWrite::readAll(const string& filename) const {
	ifstream inFile(filename);

	if (!inFile.is_open()) {
		cerr << "Error opening file." << endl;
		return;
	}

	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}

	inFile.close();

	return;
}