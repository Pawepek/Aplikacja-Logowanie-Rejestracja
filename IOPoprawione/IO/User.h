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
	static int numOfUsers;
	string username;
	string password;
	string name;
	string surname;
	string email;
	string salt;
	bool isManager;
	int id;
	bool isLogged;
public:
	User(string username, string password, string name, string surname, string email, bool isManager,string salt);

	string getUsername();

	string getEmail();

	string getName();

	string getSurname();
	string getSalt();
	bool isLoggedIn();

	void registerUser(string username, string password, string name, string surname, string email, bool isManager, vector<User> &userzy, vector <size_t> &hashedpasswords);


	static bool validateInputs(string, string, string, string, string);
	static void validateEmail(string);
	static void validatePassword(string);
	static void validateName(string);
	static void validateUsername(string);

	void authenticateUser(string username, string password, vector<User> userzy, vector <size_t> hashedpasswords);
	static string gen_random_salt(std::string::size_type length);
	User();
};