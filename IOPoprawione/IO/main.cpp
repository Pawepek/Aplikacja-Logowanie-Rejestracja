#include "User.h"
#include <vector>
#include <iostream>
#include <cstdlib>
	using namespace std;


	int main() {
		setlocale(LC_ALL, "");

		//sample user
		User::registerUser("admin", "asdf11", "Admin", "Adminowicz", "admin@admin.pl", User::Role::roleManager);
		User::registerUser("example", "qwerty123", "Jan", "Kowalski", "jan@kowalski.pl", User::Role::roleDeveloper);
		User::registerUser("example2", "qwerty123", "Jan2", "Kowalski2", "jan@kowalski2.pl", User::Role::roleDeveloper);
		int choice;
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
					User::registerUser(username, password, name, surname, email,User::roleDeveloper);
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
				User::authenticateUser(username, password);
			}

			default:
				break;
			}
		}
	
		system("pause");
		return 0;
	}