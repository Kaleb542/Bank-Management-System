#pragma once
#include <string>
using namespace std;

class User
{
private:
	string username;
	string password;
public:
	User(string username, string password);
	~User();

	string getUsername();
	string getPassword();
};

