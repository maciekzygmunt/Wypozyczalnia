#include <exception>
#include <string>
using namespace std;

#ifndef __Klient_h__
#define __Klient_h__

#include "Rezerwacja.h"

class Rezerwacja;
class Klient;

/**
* Klasa obsluguje rejestracje klientow oraz platnosci za rezerwacje.
*<p>
* Zawiera metody obslugujace rejestracje klientow i oplacanie rezrwacji. Przechowuje imie, nazwisko, 
* numer prawa jazdy, email i haslo klienta.
* @author Michal Wojcik
* @version 1.0
*/
class Klient
{
	public:
		/**
		* Realizuje rejestrowanie klientów - zapis danych do bazy klientow.
		*<p>
		* Metoda wyswietla formularz rejestracji, sprawdza poprawnosc adresu email przy pomocy funkcji czy_email_poprawny.
		* W razie wpisania blednedo adresu wyœwietla odpowiedni komunikat. Zapisuje dane klienta {@link Klient} do pliku baza_klientów.txt,
		* umieszczaj¹c w kolejnych wierszach kolejne informacje. Przed zaladowaniem formularza rejestracji metoda
		* umo¿liwia powrót do menu_start.
		* @return void
		*/
		void rejestracja();

		/**
		* Realizuje platnosc online, oplacajac rezerwacje podana w argumencie.
		* <p>
		* Metoda realizuje tranzakcje online przy pomocy karty platniczej i zewnetrznego operatora. Metoda pyta uzytkownika o dane karty
		* platniczej.
		* @param rezerwacja obiekt typu Rezerwacja {@link Rezerwacja}
		* @return void
		*/
		void zaplac(Rezerwacja rezerwacja);

	private:
		string imie;
		string nazwisko;
		string numer_prawa_jazdy;
		string adres_email;
		string haslo;

};

#endif
