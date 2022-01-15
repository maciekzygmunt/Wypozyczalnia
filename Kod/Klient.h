#include <exception>
#include <string>
using namespace std;

#ifndef __Klient_h__
#define __Klient_h__

#include "Rezerwacja.h"

class Rezerwacja;
class Klient;

class Klient
{
	public:
		/**
		* Realizuje rejestrowanie klient�w - zapis danych do bazy klient�w.
		*<p>
		* Metoda wy�wietla formularz rejestracji, sprawdza poprawno�� adresu email przy pomocy funkcji {@link czy_email_poprawny}.
		* W razie wpisania b�ednedo adresu wy�wietla odpowiedni komunikat. Zapisuje dane klienta {@link Klient} do pliku baza_klient�w.txt,
		* umieszczaj�c w kolejnych wierszach kolejne informacje. Przed za�adowaniem formularza rejestracji metoda
		* umo�liwia powr�t do {@menu_start}.
		* @return void
		*/
		void rejestracja();

		/**
		* Realizuje p�atno�� online, op�acaj�c rezerwacje podan� w argumencie.
		* <p>
		* Metoda realizuje tranzakcj� online przy pomocy karty p�atniczej i zewnetrznego operatora. Metoda pyta u�ytkownika o dane karty
		* p�atniczej.
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
