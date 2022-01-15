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
		Rezerwacja(Data _poczatek, Data _koniec, Wypozyczenie _wypozyczenie, string _protokol,string _numer_rejestracji, int _koszt_rezerwacji);

		void wypozycz();
		void zwroc();
		void zmiana_terminu_najmu();

		/**
		* Oblicza koszt rezerwacji.
		*<p>
		* Metoda oblicza koszt na podstawie ró¿nocy w dniach pomiedzy dat¹ koñca a data poczatku rezerwacji.
		* @param cena_za_dobe cena za dobe najmu pojazdu, wyrazona w PLN
		* @return int koszt ca³kowity rezerwacji
		*/
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
		string numer_rejestracji;
		int koszt_rezerwacji;

};

#endif
