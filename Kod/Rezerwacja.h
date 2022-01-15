#include <exception>
#include <string>
using namespace std;

#ifndef __Rezerwacja_h__
#define __Rezerwacja_h__

#include "Data.h"
#include "Wypozyczenie.h"

class Data;
class Rezerwacja;

/**
* Klasa obsluguje operacje wykonywane na konkretnej rezerwacji.
*<p>
* Zawiera metody obslugujace obliczanie kosztu oraz zapisywanie rezerwacji do pliku.
* @author Michal Wojcik
* @version 1.0
*/
class Rezerwacja
{
	public:
		/**
		* Konstruktor domyslny klasy Rezerwacja
		* <p>
		* Tworzy nowy obiekt klasy Rezerwacja
		*/
		Rezerwacja();

		/**
		* Konstruktor parametryczny
		* <p>
		* Przyjmuje poczatek i koniec rezerwacji oraz obiekt wypozyczenie, zmienna protokol, numer rejestracji i koszt 
		* jako argumenty a nastepnie tworzy obiekt klasy Rezerwacja z podanymi argumentami.
		*
		* @param _poczatek
		* @param _koniec
		* @param _wypozyczenie
		* @param _protokol
		* @param _numer_rejestracji
		* @param _koszt_rezerwacji
		*/
		Rezerwacja(Data _poczatek, Data _koniec, Wypozyczenie _wypozyczenie, string _protokol,string _numer_rejestracji, int _koszt_rezerwacji);

		void wypozycz();
		void zwroc();
		void zmiana_terminu_najmu();

		/**
		* Oblicza koszt rezerwacji.
		*<p>
		* Metoda oblicza koszt na podstawie roznicy w dniach pomiedzy dat¹ konca a data poczatku rezerwacji.
		* @param cena_za_dobe cena za dobe najmu pojazdu, wyrazona w PLN
		* @return int koszt calkowity rezerwacji
		*/
		int oblicz_koszt(int cena_za_dobe);

		/**
		* Zwaraca wartosc pola koszt.
		* @return koszt liczba typu int, oznacza koszt rezerwacji w PLN
		*/
		int get_koszt();

		/**
		* Zapisuje obiekt typu Rezerwacja do pliku baza_rezerwacji.txt
		* <p>
		* Metoda otwiera strumieñ wyjsciowy na plik baza_rezerwacji.txt. Zapisuje kolejno date rozpoczecia i konca najmu, uzywajac metody
		* {@link Data#zapisz()} oraz protokul i koszt rezerwacji, po czym zamyka strumien.
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
