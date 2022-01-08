#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

#include "Data.h"


Data::Data() {
	dzien = 0;
	miesiac = 0;
	rok = 0;
}

Data::Data(int _dzien, int _miesiac, int _rok) {
	dzien = _dzien;
	miesiac = _miesiac;
	rok = _rok;
}

void Data::wyswietl_date(Data data) {
	throw "Not yet implemented";
}

void Data::zapisz() {
	fstream zapis;
	zapis.open("baza_rezerwacji.txt", ios::out | ios::app);

	zapis << dzien << endl << miesiac << endl << rok << endl;

	zapis.close();
}
