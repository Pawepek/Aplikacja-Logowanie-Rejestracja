#include "User.h"
#include <vector>
#include <iostream>
#include <cstdlib>
	using namespace std;


	int main() {
		setlocale(LC_ALL, "");
		/*User *user = new User("Ashu", "1234", "Matesz", "Nogiec", "mojemail",1);
		User *user1 = new User("Ash1", "1234", "Matesz", "Nogiec", "mojemail1",0);
		User *user2 = new User("Ash2", "1234", "Matesz", "Nogiec", "mojemail2",0);*/
		vector <User> userzy;
		/*userzy.push_back(*user);
		userzy.push_back(*user1);
		userzy.push_back(*user2);*/
		vector <size_t> hashedpasswords;

		//user->registerUser("Ashu3", "12343", "Matesz3", "Nogiec", "mojemail3",1, userzy, hashedpasswords);

		int choice;
		User *user1 = new User();
		userzy.push_back(*user1);
		/*cout << "Je�li jeszcze nie masz konta wybierz 1, aby si� zarejestrowa� \nWybierz 2, aby si� zalogowa�\n";
		cin >> choice;
		system("cls");*/
		while(true) {
			cout << "Je�li jeszcze nie masz konta wybierz 1, aby si� zarejestrowa� \nWybierz 2, aby si� zalogowa�\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				string username, password, name, surname, email;
				cout << "Panel rejestracji\nPodaj nazw� u�ytkownika (minimum 4 znaki)\n";
				cin >> username;
				cout << "Podaj has�o. Musi sk�ada� si� z przynajmniej 6 znak�w oraz 2 cyfr\n";
				cin >> password;
				cout << "Imie\n";
				cin >> name;
				cout << "Nazwisko\n";
				cin >> surname;
				cout << "Email\n";
				cin >> email;
				
				if (!User::validateInputs(username, password, name, surname, email)) {
					userzy.back().registerUser(username, password, name, surname, email, 0, userzy, hashedpasswords);
				
				}
				else
					cout << "Nie uda�o si� utworzy� u�ytkownika ze wzgl�du na niepoprawne dane\n";
				break;
			}
			case 2:
			{
				string username, password;
				cout << "Podaj nazw� u�ytkownika\n";
				cin >> username;
				cout << "Podaj has�o\n";
				cin >> password;
				userzy.back().authenticateUser(username, password, userzy, hashedpasswords);
			}

			default:
				break;
			}
		}
		/*string email = "sasa@elo.pl";
		string at = "@";
		string dot = ".";
		int atPosition;
		int dotPosition;
		atPosition = email.find(at);
		dotPosition = email.find(dot);
		cout << atPosition << endl;
		cout << dotPosition;*/


		system("pause");
		return 0;
	}