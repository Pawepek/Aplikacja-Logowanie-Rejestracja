#include "User.cpp"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
	User *user = new User("Ashu", "1234", "Matesz", "Nogiec","mojemail");
	User *user1 = new User("Ash1", "1234", "Matesz", "Nogiec", "mojemail1");
	User *user2 = new User("Ash2", "1234", "Matesz", "Nogiec", "mojemail2");
	vector <User> userzy;
	userzy.push_back(*user);
	userzy.push_back(*user1);
	  vector <size_t> hashedpasswords;

user->registerUser("Ash2", "1234", "Matesz", "Nogiec", "mojemail",userzy,hashedpasswords);





	system("pause");
	return 0;
}



