#include <exception>
#include <string>
using namespace std;

#ifndef __Samochod_h__
#define __Samochod_h__

#include "Rezerwacja.h"

class Rezerwacja;
class Samochod;

/**
* Klasa reprezentuje samochod nalezacy do floty wypozyczalni.
*<p>
* Zawiera metody obslugujace dokonywanie nowej rezerwacji, wyswietlania obiektu klasy Samochod. Posiada komplet getterow i 
* setter wszystkich pol. Posiada metode przeciazajaca operator porownania.
* @author Michal Wojcik
* @author Maciej Zygmunt
* @version 1.0
*/
class Samochod
{
	public:
		/**
		* Realizuje utworzenie nowej rezerwacji i informuje klienta o cenie najmu.
		* <p>
		* Metoda pyta klienta o dane rezerwacji, a nastêpnie wyswietla jej koszt. Mozliwe jest dokonanie rezerwacji jedynie na rok 2022.
		* @return Rezerwacja obiekt klasy {@link Rezerwacja}
		*/
		Rezerwacja zarezerwuj();

		/**
		* Funkcja sluzaca do wyswietlenia samochodu
		* <p>
		* Funkcja tworzy tablice samochodow z pliku baza_samochodow.txt, 
		* nastepnie usuwa z niej element przekazany jako parametr, oraz czysci plik txt i nadpisuje go nowa wersja
		*
		* @param samochod typu Samochod
		* @return void
		*/
		void wyswietl_pojazd();

		/**
		* Setter samochodu
		* <p>
		* Funkcja przyjmuje dane samochodu a nastepnie ustawia argumenty
		*
		* @param marka marka samochodu
		* @param model model samochodu
		* @param ilosc_drzwi ilosc drzwi samochodu
		* @param rodzaj_nadwozia rodzaj nadwozia samochodu
		* @param numer_rejestracji numer rejestracji samochodu
		* @param cena_za_dobe cena za dobe
		* @return void
		*/
		void set_samochod(string marka, string model, int ilosc_drzwi, string rodzaj_nadwozia, string numer_rejestracji, int cena_za_dobe);

		/**
		* Przeciazenie operatora porownania
		* <p>
		* Funkcja porownuje numer rejestracyjny samochodu
		* 
		* @param &samo referencja na obiekt typu Samochod
		* @return bool
		*/
		bool operator ==(Samochod& samo);

		/**
		* Getter marki
		* <p>
		* Wywolany zwraca marke samochodu
		*
		* @return marka
		*/
		string get_marka();

		/**
		* Getter modelu
		* <p>
		* Wywolany zwraca model samochodu
		*
		* @return model
		*/
		string get_model();

		/**
		* Getter ilosci drzwi
		* <p>
		* Wywolany zwraca ilosc drzwi samochodu
		*
		* @return ilosc_drzwi
		*/
		int get_ilosc_drzwi();

		/**
		* Getter rodzaju nadwozia
		* <p>
		* Wywolany zwraca rodzaj nadwozia samochodu
		*
		* @return rodzaj_nadwozia
		*/
		string get_rodzaj_nadwozia();

		/**
		* Getter numeru rejestracji
		* <p>
		* Wywolany zwraca numer rejestracyjny samochodu
		*
		* @return numer_rejestracji
		*/
		string get_numer_rejestracji();

		/**
		* Getter ceny za dobe
		* <p>
		* Wywolany zwraca cene za dobe
		*
		* @return cena_za_dobe
		*/
		int get_cena_za_dobe();

	private:
		string marka;
		string model;
		int ilosc_drzwi;
		string rodzaj_nadwozia;
		string numer_rejestracji;
		int cena_za_dobe;

};

#endif
