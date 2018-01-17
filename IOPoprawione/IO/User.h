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

	User();
	User(string username, string password, string name, string surname, string email, string salt);

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
	bool isLoggedIn();
	static bool registerUser(string username, string password, string name, string surname, string email);
	static bool authenticateUser(string username, string password);
	static bool validateInputs(string, string, string, string, string);
};