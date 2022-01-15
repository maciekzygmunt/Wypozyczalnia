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
		/**
		* Konstruktor domyslny klasy menedzer
		* <p>
		* Tworzy nowy obiekt klasy menedzer
		* 
		*/
		Menedzer();

		/**
		* Konstruktor wielkoarugemntowy
		* <p>
		* Przyjmuje login i haslo jako argumenty a nastepnie tworzy obiekt klasy menedzer z podanymi argumentami
		*
		* @param _login login menedzera
		* @param _haslo haslo menedzera
		*/
		Menedzer(string _login, string _haslo);

		/**
		* Getter loginu
		* <p>
		* Wywolany zwraca login Menedzera
		*
		* @return login
		*/
		string get_login();

		/**
		* Getter hasla
		* <p>
		* Wywolany zwraca haslo Menedzera
		*
		* @return haslo
		*/
		string get_haslo();

		/**
		* Funkcja sluzaca do dodania samochodu
		* <p>
		* Funkcja wyswietla formularz dodania samochodu w ktorej uzytkownik podaje dane samochodu, a nastepnie dodaje te dane do baza_samochdow.txt
		*
		* @return void
		*/
		void dodaj_samochod();

		/**
		* Funkcja sluzaca do usuniecia wybranego samochodu
		* <p>
		* Funkcja tworzy tablice samochodow z pliku baza_samochodow.txt, nastepnie usuwa z niej element przekazany jako parametr, oraz czysci plik txt i nadpisuje go nowa wersja
		*
		* @param samochod typu Samochod
		* @return void
		*/
		void usun_samochod(Samochod samochod);

		/**
		* Funkcja sluzaca do edycji wybranego samochodu
		* <p>
		* Funkcja wyswietla formularz edycji wybranego samochodu, nastepnie tworzy tablice samochodow z pliku baza_samochodow.txt, nastepnie edytuje w niej element przekazany jako parametr, oraz czysci plik txt i nadpisuje go nowa wersja
		*
		* @param samochod typu Samochod
		* @return void
		*/
		void edytuj_samochod(Samochod samochod);
};

#endif
