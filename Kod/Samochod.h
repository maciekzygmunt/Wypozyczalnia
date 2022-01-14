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

		/**
		* Wyswietla informacje obiekcie typu Samochod w jednym wierszu konsoli.
		* @return void
		*/
		void wyswietl_pojazd();

		/**
		* Ustawia przyjete w argumentach wartoœci obiektowi typu Samochod.
		* @param _marka marka samochodu
		* @param _model model samochodu
		* @param _ilosc_drzwi liczba drzwi w samochodzie
		* @param _rodzaj_nadwozia typ nadwozia samochodu
		* @param _numer_rejestracji numer rejestracyjny samochodu
		* @param _cena_za_dobe cena za dobe najmu w PLN
		* @return void
		*/
		void set_samochod(string marka, string model, int ilosc_drzwi, string rodzaj_nadwozia, string numer_rejestracji, int cena_za_dobe);

	private:
		string marka;
		string model;
		int ilosc_drzwi;
		string rodzaj_nadwozia;
		string numer_rejestracji;
		int cena_za_dobe;

};

#endif
