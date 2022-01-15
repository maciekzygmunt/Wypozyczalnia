#include <exception>
using namespace std;

#ifndef __Data_h__
#define __Data_h__

class Data;

/**
* Klasa obsluguje daty uzywane w {@link Rezerwacja} i {@link Wypozyczenie}.
*<p>
* Zawiera metody obslugujace zapisywanie daty do pliku oraz gettery do kazdego pola.
* @author Michal Wojcik
* @version 1.0
*/
class Data
{
	public:
		/**
		* Konstruktor domyslny klasy Data
		* <p>
		* Tworzy nowy obiekt klasy Data
		*/
		Data();

		/**
		* Konstruktor parametryczny
		* <p>
		* Przyjmuje dzien, miesiac i rok jako argumenty a nastepnie tworzy obiekt klasy Data z podanymi argumentami.
		* @param _dzien dzien miesiaca
		* @param _miesiac numer miesiaca
		* @param _rok rok
		*/
		Data(int _dzien, int _miesiac, int _rok);

		void wyswietl_date(Data data);

		/**
		* Zapisuje obiekt typu data do pliku baza_rezerwacji.txt
		* <p>
		* Metoda otwiera strumien wyjsciowy na plik baza_rezerwacji.txt. Zapisuje kolejno dzien, miesi¹c i rok w kolejnych wierszach pliku,
		* po czym zamyka strumien. Metoda uzywana do zapisu do pliku obiektów typu {@link Rezerwacja} i {@link Wypo¿yczenie}.
		* @return void
		*/
		void zapisz();

		/**
		* Zwaraca wartoœc pola rok.
		* @return rok liczba typu int
		*/
		int get_rok();

		/**
		* Zwaraca wartoœc pola miesiac.
		* @return miesiac liczba typu int, liczba od 1 do 12, oznacza miesiace od stycznia do grudnia
		*/
		int get_miesiac();

		/**
		* Zwaraca wartoœc pola dzien.
		* @return dzien liczba typu int
		*/
		int get_dzien();

	private:
		int dzien;
		int miesiac;
		int rok;

};

#endif
