#include <exception>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

#include "Klient.h"
#include "Rezerwacja.h"

bool czy_email_poprawny(const string& email) {

	// define a regular expression
	const regex wzor("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return regex_match(email, wzor);
}

void Klient::rejestracja() {
	system("CLS");
	int wybor;
	cout << "0. Powrot" << endl;
	cout << "1. Formularz rejestracji" << endl;
Wybor:
	cout << "Wybor: ";
	cin >> wybor;
	if (wybor == 0) {
		return;
	}
	else if (wybor == 1) {
		string imie;
		string nazwisko;
		string email;
		string nr_prawa_jazdy;
		string haslo;

		cout << "Wpisz imie: ";
		cin >> imie;
		cout << endl;
		cout << "Wpisz nazwisko: ";
		cin >> nazwisko;
		cout << endl;
	Email:
		cout << "Wpisz email: ";
		cin >> email;
		cout << endl;

		if (czy_email_poprawny(email)) {
			cout << "Wpisz numer prawa jazdy: ";
			cin >> nr_prawa_jazdy;
			cout << endl;
			cout << "Wprowadz haslo: ";
			cin >> haslo;
			cout << endl;

			fstream zapis;
			zapis.open("baza_klientow.txt", ios::out | ios::app);

			zapis << imie << endl << nazwisko << endl << email << endl << haslo << endl << nr_prawa_jazdy << endl;

			zapis.close();

			system("cls");
			cout << "Poprawnie zarejestrowano uzytkownika " << imie << " " << nazwisko << endl;
			system("pause");
		}
		else {
			cout << "Niepoprawny adres email. Sprobuj ponownie." << endl;
			goto Email;
		}
	}
	else {
		cout << "Wybrano zla wartosc. Sprobuj ponownie." << endl;
		goto Wybor;
	}
	
}

void Klient::zaplac(Rezerwacja rezerwacja) {
	
	int kwota_tranzakcji = rezerwacja.get_koszt();

	cout << "Kwota tranzakcji: " << kwota_tranzakcji << " zl" << endl;
	cout << "Przejdz do strony platnosci" << endl;
	system("pause");
}