#include "User.h"
#include <vector>
vector<User> User::users;
vector <size_t> User::hashedpasswords;

User::User(string username, string password, string name, string surname, string email, string salt, Role role) {
	this->username = username;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->isLogged = false;
	this->salt = salt;
	this->role = role;
}

vector<User> User::getUsersVector(){
	return users;
}

string User::getUsername() {
	return this->username;
}

string User::getEmail() {
	return this->email;
}

string User::getName() {
	return this->name;
}

string User::getSurname() {
	return this->surname;
}

string User::getSalt(){
	return this->salt;
}

User::Role User::getRole(){
	return this->role;
}


bool User::isAuthorized(User user) {
	if (user.getRole() == roleManager) {
		return true;
	}
	else {
		return false;
	}
}

bool User::logout() {
	this->isLogged = false;
	return true;
}

bool User::isLoggedIn() {
	return this->isLogged;
}
bool User::registerUser(string username, string password, string name, string surname, string email, Role role = Role::roleDeveloper)
{
	try
	{
		for (size_t i = 0; i < users.size(); ++i)
		{

			if (users[i].email == email) {
				throw "Email zajêty";
			}
			if (users[i].username == username) {
				throw "Username zajêty";
			}
		}
	}

	catch (const char* msg) {
		cerr << msg << endl;
		return false;
	}

	string salt = gen_random_salt(32);
	std::hash<std::string> HashForPassword;
	size_t specificHash = HashForPassword(password + salt);
	hashedpasswords.push_back(specificHash);

	users.push_back(*new User(username, password, name, surname, email, salt));
	cout << "Dodano usera : "<<username<<"\n";
	return true;
}

static string gen_random_salt(std::string::size_type length) {
	static auto& chrs = "0123456789"
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

	std::string s;

	s.reserve(length);

	while (length--)
		s += chrs[pick(rg)];

	return s;

}

bool User::authenticateUser(string username, string password) {
	for (size_t i = 0; i < users.size(); ++i){
		if (users[i].email == username || users[i].username == username){
			std::hash<std::string> hash;
			if (hash(password + users[i].salt) == hashedpasswords[i]){
				users[i].isLogged = true;
				system("cls");
				cout << "Zalogowano, witaj " << users[i].getName() << " " << users[i].getSurname() << "\n\n";
				return true;
			}
			else {
				cout << "Nieprawidlowe haslo\n";
				return false;
			}
		}
	}
	cout << "Nieprawidlowy login lub e-mail\n";
	return false;
}

string User::gen_random_salt(std::string::size_type length)
{
	static auto& chrs = "0123456789"
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
	std::string s;
	s.reserve(length);
	while (length--)
		s += chrs[pick(rg)];
	return s;
}
bool User::validateInputs(string username, string password, string name, string surname, string email) {
	try {
		validateEmail(email);
		validateName(name);
		validateName(surname);
		validateUsername(username);
		validatePassword(password);
	}
	catch (string msg)
	{
		cout << msg;
		return 1;
	}
	return 0;
}

void User::validateEmail(string email) { // @
	string msg = "Nieprawid³owy adres email\n";
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (!regex_match(email, pattern))
		throw msg;
}

void User::validateName(string name) { //same litery
	string msg = "Imie i nazwisko mo¿e zawieraæ tylko litery\n";
	for (int i = 0; i < name.length(); i++) {
		if (isdigit(name[i]))
			throw msg;
	}
}

void User::validateUsername(string username) { //d³u¿sze ni¿ 4 znaki
	string msg = "Nazwa u¿ytkownika musi sk³adaæ siê z przynajmniej 4 znaków\n";
	if (username.length() < 4)
		throw msg;
}

void User::validatePassword(string password) { //min 6 znakow, w tym 2 cyfry STRONK
	string msg = "Has³o musi zawieraæ conajmniej 2 cygry i sk³adaæ siê z minimum 6 znaków\n";
	int digitCounter = 0;
	if (password.length() < 6)
		throw msg;
	for (int i = 0; i < password.length(); i++) {
		if (isdigit(password[i]))
			digitCounter++;
	}
	if (digitCounter < 2)
		throw msg;
}
User::User() {};