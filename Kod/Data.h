#include <exception>
using namespace std;

#ifndef __Data_h__
#define __Data_h__

class Data;

class Data
{
	public:
		Data();
		Data(int _dzien, int _miesiac, int _rok);

		void wyswietl_date(Data data);

		void zapisz();
	private:
		int dzien;
		int miesiac;
		int rok;

};

#endif
