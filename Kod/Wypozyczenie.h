
#ifndef __Wypozyczenie_h__
#define __Wypozyczenie_h__

#include "Data.h"

class Data;
class Wypozyczenie;

/**
* Klasa obsluguje wypozyczenie uzywane w {@link Rezerwacja}.
*<p>
* 
* @author Michal Wojcik
* @version 1.0
*/
class Wypozyczenie
{
	private:
		Data data_wypozyczenia;
		Data data_zwrotu;
	public:
		/**
		* Konstruktor domyslny klasy Wypozyczenie
		* <p>
		* Tworzy nowy obiekt klasy Wypozyczenie
		*/
		Wypozyczenie();
};

#endif
