#include "User.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <string>
#include <unordered_map>



User::User(string username, string password, string name, string surname, string email) {
	this->username = username;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->isLogged = true;
}

string User::getUsername() {
	return this->username;
}

string User::getEmail() {
	return this->email;
}

string User::getName() {
	return this->name;
};

string User::getSurname() {
	return this->surname;
};

bool User::isLoggedIn() {
	return this->isLogged;
}

void User::registerUser(string username, string password, string name, string surname, string email, vector<User> userzy, vector <size_t> hashedpasswords)
{

	try
	{
		for(size_t i = 0; i < userzy.size(); ++i)
		{

			if (userzy[i].email == email)
			{
				throw "Email already taken";
			}
			if (userzy[i].username == username)
			{

				throw "Username already taken";
			}
		}
	}

	catch (const char* msg)
	{
		cerr << msg << endl;
	}
	std::hash<std::string> HashForPassword;
	size_t specificHash = HashForPassword(password);
		hashedpasswords.push_back(specificHash);


	userzy.push_back(*new User(username, password, name, surname, email));
	cout << "Dodano usera";
}



string User::authenticateUser(string username, string password) {

	return "";
}

User::User() {};

