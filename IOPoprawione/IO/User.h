#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>
#include <random>
#include <locale>
#include <regex>
using namespace std;
class User {
public:
	enum Role {
		roleDeveloper,
		roleManager
	};
private:
	static vector <User> users;
	static vector <size_t> hashedpasswords;
	string username;
	string password;
	string name;
	string surname;
	string email;
	string salt;
	int id;
	bool isLogged;
	Role role;

	User();
	User(string username, string password, string name, string surname, string email, string salt, Role role = Role::roleDeveloper);

	static string gen_random_salt(std::string::size_type length);
	static void validateEmail(string);
	static void validatePassword(string);
	static void validateName(string);
	static void validateUsername(string);
	
public:
	static vector <User> getUsersVector();
	string getUsername();
	string getEmail();
	string getName();
	string getSurname();
	string getSalt();
	Role getRole();
	bool isLoggedIn();
	bool logout();
	bool isAuthorized(User user);
	static bool registerUser(string username, string password, string name, string surname, string email, Role role);
	static bool authenticateUser(string username, string password);
	static bool validateInputs(string, string, string, string, string);
};