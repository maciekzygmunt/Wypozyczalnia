#include <exception>
#include <string>
#include <iostream>

using namespace std;

#include "Samochod.h"
#include "Rezerwacja.h"

Rezerwacja Samochod::zarezerwuj() {
	throw "Not yet implemented";
}

void Samochod::wyswietl_pojazd() {

	cout << "Marka: " << marka << endl;
}

void Samochod::set_samochod(string _marka, string _model, int _ilosc_drzwi, string _rodzaj_nadwozia, string _numer_rejestracji, int _cena_za_dobe) {
	marka = _marka;
	model = _model;
	ilosc_drzwi = _ilosc_drzwi;
	rodzaj_nadwozia = _rodzaj_nadwozia;
	numer_rejestracji = _numer_rejestracji;
	cena_za_dobe = _cena_za_dobe;
}