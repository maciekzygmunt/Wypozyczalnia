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
		Rezerwacja();
		Rezerwacja(Data _poczatek, Data _koniec, Wypozyczenie _wypozyczenie, string _protokol, int _koszt_rezerwacji);

		void wypozycz();
		void zwroc();
		void zmiana_terminu_najmu();
		int oblicz_koszt(int cena_za_dobe);
		int get_koszt();

		void zapisz();
	private:
		Data poczatek_rezerwacji;
		Data koniec_rezerwacji;
		Wypozyczenie wypozyczenie;
		string protokol;
		int koszt_rezerwacji;

};

#endif
