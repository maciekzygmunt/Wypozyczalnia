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
		* Realizuje rejestrowanie klientów - zapis danych do bazy klientów.
		*<p>
		* Metoda wyœwietla formularz rejestracji, sprawdza poprawnoœæ adresu email przy pomocy funkcji {@link czy_email_poprawny}.
		* W razie wpisania b³ednedo adresu wyœwietla odpowiedni komunikat. Zapisuje dane klienta {@link Klient} do pliku baza_klientów.txt,
		* umieszczaj¹c w kolejnych wierszach kolejne informacje. Przed za³adowaniem formularza rejestracji metoda
		* umo¿liwia powrót do {@menu_start}.
		* @return void
		*/
		void rejestracja();

		/**
		* Realizuje p³atnoœæ online, op³acaj¹c rezerwacje podan¹ w argumencie.
		* <p>
		* Metoda realizuje tranzakcjê online przy pomocy karty p³atniczej i zewnetrznego operatora. Metoda pyta u¿ytkownika o dane karty
		* p³atniczej.
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
