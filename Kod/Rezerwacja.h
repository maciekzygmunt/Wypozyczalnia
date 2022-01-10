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

		/**
		* Zwaraca wartoœc pola koszt.
		* @return koszt liczba typu int, oznacza koszt rezerwacji w PLN
		*/
		int get_koszt();

		/**
		* Zapisuje obiekt typu Rezerwacja do pliku baza_rezerwacji.txt
		* <p>
		* Metoda otwiera strumieñ wyjœciowy na plik baza_rezerwacji.txt. Zapisuje kolejno date rozpoczecia i konca najmu, uzywajac metody
		* {@link Data#zapisz()} oraz protokul i koszt rezerwacji, po czym zamyka strumieñ.
		* @return void
		*/
		void zapisz();

	private:
		Data poczatek_rezerwacji;
		Data koniec_rezerwacji;
		Wypozyczenie wypozyczenie;
		string protokol;
		int koszt_rezerwacji;

};

#endif
