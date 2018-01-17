#pragma once

#include <string>
#include <vector>
using namespace std;
class User {
	string username;
	string password;
	string name;
	string surname;
	string email;
	int id;

	bool isLogged;
public:
	User(string username, string password, string name, string surname, string email);

	string getUsername();

	string getEmail();

	string getName();

	string getSurname();

	bool isLoggedIn();

	void registerUser(string username, string password, string name, string surname, string email, vector<User> userzy, vector <size_t> hashedpasswords);

	string authenticateUser(string username, string password);

	User();

};