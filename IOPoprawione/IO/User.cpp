#include "User.h"

int User::numOfUsers = 0;

User::User(string username, string password, string name, string surname, string email, bool isManager,string salt) {
	this->username = username;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->isLogged = true;
	this->isManager = isManager;
	this->salt = salt;
	numOfUsers++;
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
}

string User::getSalt()
{
	return string();
}


bool User::isLoggedIn() {
	return this->isLogged;
}
void User::registerUser(string username, string password, string name, string surname, string email, bool isManager, vector<User> &userzy, vector <size_t> &hashedpasswords)
{
	try
	{
		for (size_t i = 0; i < userzy.size(); ++i)
		{

			if (userzy[i].email == email) {
				throw "Email already taken";
			}
			if (userzy[i].username == username) {
				throw "Username already taken";
			}
		}
	}

	catch (const char* msg) {
		cerr << msg << endl;
	}

	string salt = gen_random_salt(32);
	std::hash<std::string> HashForPassword;
	size_t specificHash = HashForPassword(password + salt);
	hashedpasswords.push_back(specificHash);

	userzy.push_back(*new User(username, password, name, surname, email, isManager, salt));
	cout << "Dodano usera\n";
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



void User::authenticateUser(string username, string password, vector<User> userzy, vector <size_t> hashedpasswords) {
	for (size_t i = 0; i < userzy.size(); ++i)
	{
		if (userzy[i].email == email || userzy[i].username == username)
		{
			string salt= gen_random_salt(32);

			vector <size_t> hashedpasswords2;

			std::hash<std::string> HashForPassword2;
			size_t specificHash2 = HashForPassword2(password + userzy[i].salt);
			if (specificHash2 == hashedpasswords[i])
			{
				isLogged = true;
				cout << "Zalogowano";
			}
			else
				cout << "Nieprawidlowe haslo";

		}
		else
			cout << "Nieprawidlowy login lub e-mail";

	}
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
	};
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