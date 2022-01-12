#include <exception>
using namespace std;

#ifndef __Menedzer_h__
#define __Menedzer_h__

#include "Samochod.h"
#include "Pracownik.h"

class Samochod;
class Pracownik;
class Menedzer;

class Menedzer: public Pracownik
{
	public:
		Menedzer();
		Menedzer(string _login, string _haslo);
		string get_login();
		string get_haslo();
		void dodaj_samochod();
		void usun_samochod(Samochod samochod);
		void edytuj_samochod(Samochod samochod);
};

#endif
