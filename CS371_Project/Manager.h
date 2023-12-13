#ifndef MANAGER_H
#define MANAGER_H

#include "User.h"
#include <string>
using namespace std;

class Manager : User
{
public:
	Manager(string username, string password);
	~Manager();

	void deleteAccount(const string& filename, string username) const;
};


#endif // !"MANAGER_H"
