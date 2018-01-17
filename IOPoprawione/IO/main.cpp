#include "User.h"
#include <vector>
#include <iostream>
#include <cstdlib>
	using namespace std;


	int main() {
		setlocale(LC_ALL, "");

		//sample user
		//User::registerUser("example", "qwerty123", "Jan", "Kowalski", "jan@kowalski.pl");

		int choice;
		while(true) {
			cout << "Jeœli jeszcze nie masz konta wybierz 1, aby siê zarejestrowaæ \nWybierz 2, aby siê zalogowaæ\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
			{
				string username, password, name, surname, email;
				cout << "Panel rejestracji\nPodaj nazwê u¿ytkownika (minimum 4 znaki)\n";
				cin >> username;
				cout << "Podaj has³o. Musi sk³adaæ siê z przynajmniej 6 znaków oraz 2 cyfr\n";
				cin >> password;
				cout << "Imie\n";
				cin >> name;
				cout << "Nazwisko\n";
				cin >> surname;
				cout << "Email\n";
				cin >> email;
				
				if (!User::validateInputs(username, password, name, surname, email)) {
					User::registerUser(username, password, name, surname, email);
				}
				else
					cout << "Nie uda³o siê utworzyæ u¿ytkownika ze wzglêdu na niepoprawne dane\n";
				break;
			}
			case 2:
			{
				string username, password;
				cout << "Podaj nazwê u¿ytkownika\n";
				cin >> username;
				cout << "Podaj has³o\n";
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