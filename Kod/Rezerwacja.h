#include <exception>
#include <string>
using namespace std;

#ifndef __Rezerwacja_h__
#define __Rezerwacja_h__

#include "Data.h"
#include "Wypozyczenie.h"

class Data;
class Rezerwacja;

class Rezerwacja
{
	public:

		void wypozycz();
		void zwroc();
		void zmiana_terminu_najmu(Rezerwacja rezerwacja);
		int oblicz_koszt(string cena_za_dobe);
		int get_koszt();
	private:
		Data poczatek_rezerwacji;
		Data koniec_rezerwacji;
		Wypozyczenie* wypozyczenie;
		string protokol;
		int koszt_rezerwacji;

};

#endif
