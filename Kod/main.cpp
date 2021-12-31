#include <iostream>
#include <regex>
#include <string>
#include <locale.h>
#include "Klient.h"

using namespace std;

void menu_start();

void przegladanie_samochodow() {
	system("CLS");
	int a;
	cout << "0. Powrot." << endl;
	cout << "Aby zarezerwowac samochod wpisz jego numer" << endl;
	cout << "Lista dostepnych samochodow:" << endl;

	//tu trzeba zrobic to wczytywanie z pliku
	cout << "1. Fiesta" << endl;
	cout << "2. Opelek" << endl;

	cout << "Wybor: ";
	cin >> a;
	if (a == 0) {
		menu_start();
	}
}

bool czy_email_poprawny(const string& email){
	
	// define a regular expression
	const regex wzor ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return regex_match(email, wzor);
}

void formularz_rejestracji() {
	system("CLS");
	int wybor;
	cout << "0. Powrot" << endl;
	cout << "1. Formularz rejestracji" << endl;
Wybor:
	cout << "Wybor: ";
	cin >> wybor;
	if (wybor == 0) {
		menu_start();
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

			Klient nowy_klient;
			nowy_klient.rejestracja(imie, nazwisko, email, haslo, nr_prawa_jazdy);

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

	menu_start();
}

void dodaj_nowy_samochod() {
	string marka;
	string model;
	int ilosc_drzwi;
	string rodzaj_nadwozia;
	Rezerwacja rezerwacje[10]; // ?
	string numer_rejestracji;
	int cena_za_dobe;

	cout << "Marka samochodu:" << endl;
	cin >> marka;
	cout << endl;
	cout << "Model samochodu:" << endl;
	cin >> model;
	cout << endl;
	cout << "Ilosc drzwi:" << endl;
	cin >> ilosc_drzwi;
	cout << endl;
	cout << "Rodzaj nadwozia:" << endl;
	cin >> rodzaj_nadwozia;
	cout << endl;
	cout << "Numer rejestracji:" << endl;
	cin >> numer_rejestracji;
	cout << endl;
	cout << "Cena za dobe:" << endl;
	cin >> cena_za_dobe;
	cout << endl;

	//tu chyba to samo co z klientem czyli nowy obiekt ->  funkcja dodanie ktorej nie ma
}

void zarzadzaj_baza() {
	system("CLS");
	string haslo = "AGH";
	string wpis;
	cout << "Aby zarzadzac baza musisz sie zalogowac." << endl;
	cout << "Login: Daniel Wółkowicz" << endl;
Haslo:	
	cout << "Hasło: ";
	cin >> wpis;
	while (haslo != wpis) {
		cout << "Bledne haslo sprobuj ponownie." << endl;
		goto Haslo;
	}
Lista:
	system("CLS");
	int a;
	cout << "Aby zarzadzac samochodem wpisz jego numer" << endl;
	cout << "0. Powrot." << endl;
	cout << "1. Dodaj nowy samochod" << endl;
	cout << "Lista samochodow:" << endl;

	//tu trzeba zrobic to wczytywanie z pliku
	cout << "2. Fiesta" << endl;
	cout << "3. Opelek" << endl;

	cout << "Wybor: ";
	cin >> a;
	switch (a) {
	case 0:
		menu_start();
		break;
	case 1:
		dodaj_nowy_samochod();
		break;
	case 2:
		int b;
		cout << "0. Powrot." << endl;
		cout << "1. Usun samochod" << endl;
		cout << "2. Edytuj samochod" << endl;
		cout << "Wybor:";
		cin >> b;					//tu trzeba to z baza polaczyc
		switch (b) {
		case 0:
			goto Lista;
		}
	}

}

void formularz_wydania_samochodu() {
	string imie;
	string nazwisko;
	string nr_prawa_jazdy;
	cout << "Wpisz imie klienta: ";
	cin >> imie;
	cout << endl;
	cout << "Wpisz nazwisko klienta: ";
	cin >> nazwisko;
	cout << endl;
	cout << "Wpisz numer prawa jazdy klienta: ";
	cin >> nr_prawa_jazdy;
	cout << endl;

	//i tu wywolywamy funkcje wypozycz z rezerwacja?
}

void wydaj_samochod() {
	system("CLS");
	string haslo = "AGH";
	string wpis;
	cout << "Aby wypelnic formularz wydania samochodu musisz sie zalogowac." << endl;
	cout << "Login: Wojciech Michjcik" << endl;
Haslo:
	cout << "Hasło: ";
	cin >> wpis;
	while (haslo != wpis) {
		cout << "Bledne haslo sprobuj ponownie." << endl;
		goto Haslo;
	}
	system("CLS");
Wybor:
	int wybor;

	cout << "0. Powrot" << endl;
	cout << "1. Formularz wydania samochodu."<< endl<<"Wybor: ";
	cin >> wybor;
	switch (wybor) {
	case 0:
		menu_start();
		break;
	case 1:
		formularz_wydania_samochodu();
		break;
	default:
		cout << "Wybrano nieprawidlowa opcje." << endl;
		goto Wybor;
	}
}

void menu_start() {
	system("CLS");
	int wybor;
	cout << "Witaj w wypozyczalni Ultra Flota" << endl;
	cout << "Wybierz co chcesz zrobic." << endl;
	cout << "1. Przegladaj samochody." << endl;
	cout << "2. Zarejestruj sie." << endl;
	cout << "3. Zmien termin najmu." << endl;
	cout << "4. Odbierz samochod. (Wymagane konto pracownika)" << endl;
	cout << "5. Wydaj samochod. (Wymagane konto pracownika)" << endl;
	cout << "6. Zarzadzaj baza pojazdow. (Wymagane konto menedzera)" << endl;
	cout << "7. Wyjdz." << endl;
	cout << "Wybierz opcje (podajac jej numer): ";
	cin >> wybor;

	switch (wybor)
	{
	case 1:
		przegladanie_samochodow();
		break;

	case 2:
		formularz_rejestracji();
		break;

	case 3:
		//jakiś kod
		break;

	case 4:
		//jakiś kod
		break;

	case 5:
		wydaj_samochod();
		break;

	case 6:
		zarzadzaj_baza();
		break;
	case 7:
		exit;
		break;
	default:
		cout << "Wybrano nieprawidlowa opcje!" << endl;
		break;
	}
}

int main() {
	setlocale(LC_CTYPE, "Polish"); //wyswietlanie polskich znakow

	menu_start();

}

