#include <exception>
#include <string>
#include <iostream>

using namespace std;

#include "Pracownik.h"
#include "Samochod.h"
#include "Rezerwacja.h"

void Pracownik::wydanie_samochodu(Samochod samochod) {
	
Wybor:
	int wybor;
	string imie;
	string nazwisko;
	string nr_prawa_jazdy;

	cout << "0. Powrot" << endl;
	cout << "1. Formularz wydania samochodu." << endl << "Wybor: ";
	cin >> wybor;
	switch (wybor) {
	case 0:
		return;
		break;
	case 1:
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
		break;

	default:
		cout << "Wybrano nieprawidlowa opcje." << endl;
		goto Wybor;
	}
}

void Pracownik::odbior_samochodu(Samochod samochod) {
	throw "Not yet implemented";
}

void Pracownik::zmiana_terminu_najmu(Rezerwacja rezerwacja) {
	throw "Not yet implemented";
}

