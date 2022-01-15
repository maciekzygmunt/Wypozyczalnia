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

/**
* Klasa obsluguje przypadki uzycia Pracownika.
*<p>
* Klasa Pracownik  odpowiada za wydawanie, odbieranie pojazdow oraz zmiane terminow rezerwacji.
* @author Maciej Zygmunt
* @version 1.0
*/
class Pracownik
{
	public:

		/**
		* Konstruktor domyslny klasy Pracownik
		* <p>
		* Tworzy nowy obiekt klasy Pracownik
		*
		*/
		Pracownik();

		/**
		* Konstruktor parametryczny
		* <p>
		* Przyjmuje login i haslo jako argumenty a nastepnie tworzy obiekt klasy Pracownik z podanymi argumentami
		*
		* @param _login login pracownika
		* @param _haslo haslo pracownika
		*/
		Pracownik(string _login, string _haslo);

		/**
		* Getter loginu
		* <p>
		* Wywolany zwraca login pracownika
		*
		* @return login
		*/
		string get_login();

		/**
		* Getter hasla
		* <p>
		* Wywolany zwraca haslo pracownika
		*
		* @return haslo
		*/
		string get_haslo();


		void wydanie_samochodu(Samochod samochod);
		void odbior_samochodu(Samochod samochod);
		void zmiana_terminu_najmu(Rezerwacja rezerwacja);
	protected:
		string login;
		string haslo;

};

#endif
