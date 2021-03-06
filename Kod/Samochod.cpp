#include <exception>
#include <string>
#include <iostream>

using namespace std;

#include "Samochod.h"
#include "Rezerwacja.h"

Rezerwacja Samochod::zarezerwuj() {
	int dzien, miesiac, rok;
	int miesiace[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	system("CLS");
	cout << "Nowa rezerwacja" << endl;

	cout << "Podaj date poczatku rezerwacji (dd mm rrrr): " << endl;
	cin >> dzien >> miesiac >> rok;

	//kontrola poprawnosci daty poczatku
	while (miesiac<1 || miesiac>12) {
		cout << "Niema takiego miesiaca w roku" << endl;

		cout << "Podaj date poczatku rezerwacji (dd mm rrrr): " << endl;
		cin >> dzien >> miesiac >> rok;
	}
	while (dzien<1 || dzien>miesiace[miesiac - 1]) {
		cout << "Ten miesiac nie ma tylu dni" << endl;

		cout << "Podaj date poczatku rezerwacji (dd mm rrrr): " << endl;
		cin >> dzien >> miesiac >> rok;
	}
	while (rok != 2022) {
		cout << "Mozesz dokonac rezerwacji jedynie na rok bierzacy" << endl;

		cout << "Podaj date poczatku rezerwacji (dd mm rrrr): " << endl;
		cin >> dzien >> miesiac >> rok;
	}

	Data poczatek_rezerwacji(dzien, miesiac, rok);

	cout << "Podaj date konca rezerwacji (dd mm rrrr): " << endl;
	cin >> dzien >> miesiac >> rok;

	//kontrola poprawnosci daty konca
	while (miesiac < 1 || miesiac>12) {
		cout << "Niema takiego miesiaca w roku" << endl;

		cout << "Podaj date konca rezerwacji (dd mm rrrr): " << endl;
		cin >> dzien >> miesiac >> rok;
	}
	while (dzien<1 || dzien>miesiace[miesiac - 1]) {
		cout << "Ten miesiac nie ma tylu dni" << endl;

		cout << "Podaj date konca rezerwacji (dd mm rrrr): " << endl;
		cin >> dzien >> miesiac >> rok;
	}
	while (rok != 2022) {
		cout << "Mozesz dokonac rezerwacji jedynie na rok bierzacy" << endl;

		cout << "Podaj date konca rezerwacji (dd mm rrrr): " << endl;
		cin >> dzien >> miesiac >> rok;
	}

	Data koniec_rezerwacji(dzien, miesiac, rok);

	Wypozyczenie brak;
	Rezerwacja nowa_rezerwacja(poczatek_rezerwacji, koniec_rezerwacji, brak, "Brak protokolu",numer_rejestracji, cena_za_dobe);
	int koszt = nowa_rezerwacja.oblicz_koszt(cena_za_dobe);
	Rezerwacja nowa_rezerwacja_koszt_calkowity(poczatek_rezerwacji, koniec_rezerwacji, brak, "Brak protokolu",numer_rejestracji, koszt);

	cout << "Koszt twojej rezerwacji samochodu " << marka << " " << model << " to: " << koszt << endl; 
	system("pause");
	system("CLS");

	return nowa_rezerwacja_koszt_calkowity;
}

void Samochod::wyswietl_pojazd() {

	cout << marka << " " << model;
	cout << " Ilosc drzwi: "<<ilosc_drzwi;
	cout << " Rodzaj nadwozia: " << rodzaj_nadwozia;
	cout << " Cena: " << cena_za_dobe << endl;
}

void Samochod::set_samochod(string _marka, string _model, int _ilosc_drzwi, string _rodzaj_nadwozia, string _numer_rejestracji, int _cena_za_dobe) {
	marka = _marka;
	model = _model;
	ilosc_drzwi = _ilosc_drzwi;
	rodzaj_nadwozia = _rodzaj_nadwozia;
	numer_rejestracji = _numer_rejestracji;
	cena_za_dobe = _cena_za_dobe;
}

bool Samochod::operator==(Samochod& samo)
{
	if (this->numer_rejestracji == samo.numer_rejestracji) {
		return true;
	}
	else {
		return false;
	}
}

string Samochod::get_marka() {
	return marka;
}

string Samochod::get_model() {
	return model;
}

int Samochod::get_ilosc_drzwi() {
	return ilosc_drzwi;
}

string Samochod::get_rodzaj_nadwozia() {
	return rodzaj_nadwozia;
}

string Samochod::get_numer_rejestracji() {
	return numer_rejestracji;
}

int Samochod::get_cena_za_dobe() {
	return cena_za_dobe;
}
