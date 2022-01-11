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