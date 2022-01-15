#include <exception>
using namespace std;

#ifndef __Data_h__
#define __Data_h__

class Data;

class Data
{
	public:
		Data();
		Data(int _dzien, int _miesiac, int _rok);

		void wyswietl_date(Data data);

		/**
		* Zapisuje obiekt typu data do pliku baza_rezerwacji.txt
		* <p>
		* Metoda otwiera strumieñ wyjœciowy na plik baza_rezerwacji.txt. Zapisuje kolejno dzieñ, miesi¹c i rok w kolejnych wierszach pliku,
		* po czym zamyka strumieñ. Metoda uzywana do zapisu do pliku obiektów typu {@link Rezerwacja} i {@link Wypo¿yczenie}.
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
