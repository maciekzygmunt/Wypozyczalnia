#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <locale.h>

using namespace std;

#include "Klient.h"
#include "Samochod.h"
#include "Pracownik.h"
#include "Menedzer.h"

void menu_start();

void filtruj_samochody() {

}

void przegladarka_samochodow() {
	
	system("CLS");
	int wybor;
	cout << "0. Powrot." << endl;
	cout << "Lista dostepnych samochodow:" << endl;

	Samochod flota_samochodow[100];

	string marka;
	string model;
	int ilosc_drzwi=0;
	string rodzaj_nadwozia;
	string numer_rejestracji;
	int cena_za_dobe=0;

	ifstream odczyt("baza_samochodow.txt");

	int i = 0;
	while (!odczyt.eof()) {
		
		odczyt >> marka >> model >> ilosc_drzwi >> rodzaj_nadwozia >> numer_rejestracji >> cena_za_dobe;

		flota_samochodow[i].set_samochod(marka, model, ilosc_drzwi, rodzaj_nadwozia, numer_rejestracji, cena_za_dobe);
		
		flota_samochodow[i].wyswietl_pojazd();
		
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

void zarzadzaj_baza() {
	system("CLS");
	string haslo = "AGH";
	string wpis;
	cout << "Aby zarzadzac baza musisz sie zalogowac." << endl;
	cout << "Login: Daniel Wółkowicz" << endl;
	
	while (haslo != wpis) {
		cout << "Hasło: ";
		cin >> wpis;
		cout << "Bledne haslo sprobuj ponownie." << endl;
	}
	Menedzer m1;
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
		m1.dodaj_samochod();
		zarzadzaj_baza();
		break;
	case 2:
		int b;
		cout << "0. Powrot." << endl;
		cout << "1. Usun samochod" << endl;
		cout << "2. Edytuj samochod" << endl;
		
		cout << "Wybor:";
		cin >> b;					//tu trzeba to z baza polaczyc - usuwanie i edycja
		
		switch (b) {
		case 0:
			goto Lista;
			break;
		case 1:
			//usuwanie
			break;
		case 2:
			//edycja
			break;
		}
	}

}

void wydawanie_samochodu() {
	system("CLS");

	Pracownik p1("Wojciech Michalik", "AGH");
	string haslo = p1.get_haslo();
	string wpis;

	cout << "Aby wypelnic formularz wydania samochodu musisz sie zalogowac." << endl;
	cout << "Login: " << p1.get_login() << endl;

	while (haslo != wpis) {
		cout << "Hasło: ";
		cin >> wpis;
		cout << "Bledne haslo sprobuj ponownie." << endl;
	}
	system("CLS");
	
	//Pracownik p1;
	//p1.wydanie_samochodu(samochod);
}

void odbieranie_samochodu() {
	system("CLS");

	Pracownik p1("Wojciech Michalik","AGH");
	string haslo = p1.get_haslo();
	string wpis;

	cout << "Aby wypelnic formularz odbioru samochodu musisz sie zalogowac." << endl;
	cout << "Login: " << p1.get_login()<< endl;

	while (haslo != wpis) {
		cout << "Hasło: ";
		cin >> wpis;
		cout << "Bledne haslo sprobuj ponownie." << endl;
	}
	system("CLS");

	//p1.odbior_samochodu(samochod);
}

void menu_start() {
	system("CLS");
	int wybor;
	{
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
	}
	
	Klient nowy;
	Pracownik p1;

	switch (wybor)
	{
	case 1:
		przegladarka_samochodow();
		break;

	case 2:
		nowy.rejestracja();
		menu_start();
		break;

	case 3:
		//jakiś kod
		break;

	case 4:
		odbieranie_samochodu();
		break;

	case 5:
		wydawanie_samochodu();
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