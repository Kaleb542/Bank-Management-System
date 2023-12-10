#pragma once
#ifndef READWRITE_H
#define READWRITE_H

#include <iostream>
#include <string>
using namespace std;

class ReadWrite {
public:
	ReadWrite(const string& filename);
	~ReadWrite();

	int findLineNumber(const string& filename, const string& target) const;
	bool read(const string& filename, const string& targetString) const;
	string getStringFromLine(const string& filename, int lineNumber) const;
};

#endif // !READWRITE_H