#pragma once
#include <string>
using namespace std;

class User
{
private:
	string username;
	string password;
public:
	User();
	User(string username, string password);
	~User();

	string getUsername();
	string getPassword();

	void setUsername(string user);
	void setPassword(string pass);
};

