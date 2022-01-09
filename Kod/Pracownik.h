#include <exception>
#include <string>
using namespace std;

#ifndef __Pracownik_h__
#define __Pracownik_h__

#include "Samochod.h"
#include "Rezerwacja.h"

class Samochod;
class Rezerwacja;
class Pracownik;

class Pracownik
{
	public:
		Pracownik();
		Pracownik(string _login, string _haslo);
		string get_login();
		string get_haslo();
		void wydanie_samochodu(Samochod samochod);
		void odbior_samochodu(Samochod samochod);
		void zmiana_terminu_najmu(Rezerwacja rezerwacja);
	private:
		string login;
		string haslo;

};

#endif
