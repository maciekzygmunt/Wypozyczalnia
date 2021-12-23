#include <exception>
using namespace std;

#ifndef __Data_h__
#define __Data_h__

class Data;

class Data
{
	public:

		void wyswietl_date(Data data);
	private:
		int dzien;
		int miesiac;
		int rok;

};

#endif
