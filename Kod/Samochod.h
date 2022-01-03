#include <exception>
#include <string>
using namespace std;

#ifndef __Samochod_h__
#define __Samochod_h__

#include "Rezerwacja.h"

class Rezerwacja;
class Samochod;

class Samochod
{
	public:

		Rezerwacja zarezerwuj();
		void wyswietl_pojazd();
		void set_samochod(string marka, string model, int ilosc_drzwi, string rodzaj_nadwozia, string numer_rejestracji, int cena_za_dobe);

	private:
		string marka;
		string model;
		int ilosc_drzwi;
		string rodzaj_nadwozia;
		Rezerwacja rezerwacje[10];
		string numer_rejestracji;
		int cena_za_dobe;

};

#endif
