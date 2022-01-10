#include <exception>
#include <string>
#include <iostream>

using namespace std;

#include "Samochod.h"
#include "Rezerwacja.h"

Rezerwacja Samochod::zarezerwuj() {
	int dzien, miesiac, rok;
	system("CLS");
	cout << "Nowa rezerwacja" << endl;

	cout << "Podaj date poczatku rezerwacji (dd mm rrrr): " << endl;
	cin >> dzien >> miesiac >> rok;
	Data poczatek_rezerwacji(dzien, miesiac, rok);

	cout << "Podaj date konca rezerwacji (dd mm rrrr): " << endl;
	cin >> dzien >> miesiac >> rok;
	Data koniec_rezerwacji(dzien, miesiac, rok);

	Wypozyczenie brak;
	Rezerwacja nowa_rezerwacja(poczatek_rezerwacji, koniec_rezerwacji, brak, "Brak protokolu", cena_za_dobe);
	int koszt = nowa_rezerwacja.oblicz_koszt(cena_za_dobe);
	Rezerwacja nowa_rezerwacja_koszt_calkowity(poczatek_rezerwacji, koniec_rezerwacji, brak, "Brak protokolu", koszt);

	cout << "Koszt twojej rezerwacji samochodu " << marka << " " << model << " to: " << koszt << endl; 
	system("pause");
	system("CLS");
	cout << "Poprawnie dokonano rezrwacji" << endl;
	system("pause");

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