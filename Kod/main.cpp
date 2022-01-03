﻿#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

#include "Klient.h"
#include "Samochod.h"

void menu_start();

void przegladarka_samochodow() {
	
	system("CLS");
	int wybor;
	cout << "0. Powrot." << endl;
	cout << "Lista dostepnych samochodow:" << endl;

	Samochod tablica[50];

	string marka;
	string model;
	int ilosc_drzwi;
	string rodzaj_nadwozia;
	string numer_rejestracji;
	int cena_za_dobe;

	fstream odczyt;
	odczyt.open("baza_samochodow.txt");

	int i = 0;
	while (!EOF) {
		odczyt >> marka >> model >> ilosc_drzwi >> rodzaj_nadwozia >> numer_rejestracji >> cena_za_dobe;
		tablica[i].set_samochod(marka,model,ilosc_drzwi,rodzaj_nadwozia,numer_rejestracji,cena_za_dobe);
		i++;
	}
	odczyt.close();

	//filtrowanie!!

	cout << "Aby zarezerwowac samochod wpisz jego numer" << endl;
	
	cout << "Wybor: ";
	cin >> wybor;
	if (wybor == 0) {
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
		przegladarka_samochodow();
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
		//jakiś kod
		break;

	case 6:
		//jakiś kod
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
	
	menu_start();

}

