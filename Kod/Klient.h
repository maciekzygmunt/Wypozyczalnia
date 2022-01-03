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

		void rejestracja();
		void zaplac(Rezerwacja rezerwacja);
	private:
		string imie;
		string nazwisko;
		string numer_prawa_jazdy;
		string adres_email;
		string haslo;
		Rezerwacja** rezerwacje;

};

#endif
