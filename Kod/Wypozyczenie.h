
#ifndef __Wypozyczenie_h__
#define __Wypozyczenie_h__

#include "Data.h"

class Data;
class Wypozyczenie;

class Wypozyczenie
{
	private:
		Data data_wypozyczenia;
		Data data_zwrotu;
	public:
		Wypozyczenie();
};

#endif
