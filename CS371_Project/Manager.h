#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include <string>
using namespace std;

class Manager 
{
private:
	string username;
	string password;
public:
	Manager(string username, string password);
	~Manager();

	string getUsername() const;
	string getPassword() const;
};


#endif // !"MANAGER_H"
