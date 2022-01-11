#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

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
	char pass[32];
	int g = 0;
	char c;
	cout << "Aby zarzadzac baza musisz sie zalogowac." << endl;
	cout << "Login: Daniel Wółkowicz" << endl;
	
	while (haslo != pass) {

		cout << "Hasło: ";
		for (g = 0;;)
		{
			c = _getch();
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			{
				pass[g] = c;
				++g;
				cout << "*";
			}
			if (c == '\b' && g >= 1)//if backspace
			{
				cout << "\b \b";
				--g;
			}
			if (c == '\r') //if enter
			{
				pass[g] = '\0';
				break;
			}
		}
		cout <<endl<< "Bledne haslo sprobuj ponownie." << endl;
	}
	Menedzer m1;
Lista:
	system("CLS");
	int a;
	cout << "Aby zarzadzac samochodem wpisz jego numer" << endl;
	cout << "0. Powrot." << endl;
	cout << "1. Dodaj nowy samochod" << endl;
	cout << "Lista samochodow:" << endl;

	Samochod flota_samochodow[100];
	
	string marka;
	string model;
	int ilosc_drzwi = 0;
	string rodzaj_nadwozia;
	string numer_rejestracji;
	int cena_za_dobe = 0;

	ifstream odczyt("baza_samochodow.txt");

	int i = 0;

	while (!odczyt.eof()) {

		odczyt >> marka >> model >> ilosc_drzwi >> rodzaj_nadwozia >> numer_rejestracji >> cena_za_dobe;

		flota_samochodow[i].set_samochod(marka, model, ilosc_drzwi, rodzaj_nadwozia, numer_rejestracji, cena_za_dobe);
		
		cout << i + 2 << ". ";
		flota_samochodow[i].wyswietl_pojazd();
	
		i++;
	}
	odczyt.close();
Wybor:
	cout << "Wybor: ";
	cin >> a;
	if (a == 0) {
		menu_start();
	}
	else if (a == 1) {
		m1.dodaj_samochod();
		goto Lista;
	}
	else if (a >=2 && a<=i+1) {
		int b;
		cout << "0. Powrot." << endl;
		cout << "1. Usun samochod" << endl;
		cout << "2. Edytuj samochod" << endl;
		
		cout << "Wybor:";
		cin >> b;					
		
		switch (b) {
		case 0:
			goto Lista;
			break;
		case 1:
			//usuwanie
			m1.usun_samochod(flota_samochodow[a - 2]);
			goto Lista;
			break;
		case 2:
			//edycja
			m1.edytuj_samochod(flota_samochodow[a - 2]);
			goto Lista;
			break;
		}
	}
	else {
		cout << "Liczba spoza zakresu!"<<endl;
		goto Wybor;
	}

}

void wydawanie_samochodu() {

	system("CLS");

	Pracownik p1("Wojciech Michalik", "AGH");
	string haslo = p1.get_haslo();
	char pass[32];
	int g = 0;
	char c;

	cout << "Aby wypelnic formularz wydania samochodu musisz sie zalogowac." << endl;
	cout << "Login: " << p1.get_login() << endl;


	while (haslo != pass) {

		cout << "Hasło: ";
		for (g = 0;;)
		{
			c = _getch();
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			{
				pass[g] = c;
				++g;
				cout << "*";
			}
			if (c == '\b' && g >= 1)//if backspace
			{
				cout << "\b \b";
				--g;
			}
			if (c == '\r') //if enter
			{
				pass[g] = '\0';
				break;
			}
		}
		cout << endl << "Bledne haslo sprobuj ponownie." << endl;
	}
	system("CLS");
	
	//Pracownik p1;
	//p1.wydanie_samochodu(samochod);
}

void odbieranie_samochodu() {
	system("CLS");

	Pracownik p1("Wojciech Michalik", "AGH");
	string haslo = p1.get_haslo();
	char pass[32];
	int g = 0;
	char c;

	cout << "Aby wypelnic formularz wydania samochodu musisz sie zalogowac." << endl;
	cout << "Login: " << p1.get_login() << endl;


	while (haslo != pass) {

		cout << "Hasło: ";
		for (g = 0;;)
		{
			c = _getch();
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			{
				pass[g] = c;
				++g;
				cout << "*";
			}
			if (c == '\b' && g >= 1)//if backspace
			{
				cout << "\b \b";
				--g;
			}
			if (c == '\r') //if enter
			{
				pass[g] = '\0';
				break;
			}
		}
		cout << endl << "Bledne haslo sprobuj ponownie." << endl;
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
		//zmiana terminu najmu
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