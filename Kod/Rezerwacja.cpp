#include <exception>
#include <string>
#include <fstream>

using namespace std;

#include "Rezerwacja.h"
#include "Data.h"


Rezerwacja::Rezerwacja() {
	Data d1, d2;
	Wypozyczenie w1;
	poczatek_rezerwacji =  d1;
	koniec_rezerwacji =  d2;
	wypozyczenie = w1;
	protokol = "";
	numer_rejestracji = "";
	koszt_rezerwacji = 0;
}

Rezerwacja::Rezerwacja(Data _poczatek, Data _koniec, Wypozyczenie _wypozyczenie, string _protokol,string _numer_rejestracji, int _koszt_rezerwacji) {
	poczatek_rezerwacji = _poczatek;
	koniec_rezerwacji = _koniec;
	wypozyczenie = _wypozyczenie;
	protokol = _protokol;
	numer_rejestracji = _numer_rejestracji;
	koszt_rezerwacji = _koszt_rezerwacji;
}

void Rezerwacja::wypozycz() {
	throw "Not yet implemented";
}

void Rezerwacja::zwroc() {
	throw "Not yet implemented";
}

void Rezerwacja::zmiana_terminu_najmu() {
	throw "Not yet implemented";
}

int Rezerwacja::oblicz_koszt(int cena_za_dobe) {
	int koszt_calkowity=0;
	int roznica_w_dniach=0;
	//obliczanie kosztu na podstawie roznicy w dniach miedzy dwoma datami
	int miesiace[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (poczatek_rezerwacji.get_rok() == koniec_rezerwacji.get_rok()) {
		if (poczatek_rezerwacji.get_miesiac() == koniec_rezerwacji.get_miesiac()) {
			koszt_calkowity = (koniec_rezerwacji.get_dzien() - poczatek_rezerwacji.get_dzien()) * cena_za_dobe;
		}
		else {
			roznica_w_dniach += miesiace[poczatek_rezerwacji.get_miesiac()] - poczatek_rezerwacji.get_dzien();
			for (int i = poczatek_rezerwacji.get_miesiac()+1; i < koniec_rezerwacji.get_miesiac(); i++) {
				roznica_w_dniach += miesiace[i];
			}
			roznica_w_dniach += koniec_rezerwacji.get_dzien();
			koszt_calkowity = roznica_w_dniach * cena_za_dobe;
		}
	}
	
	return koszt_calkowity;
}

int Rezerwacja::get_koszt() {
	return koszt_rezerwacji;
}

void Rezerwacja::zapisz() {
	
	poczatek_rezerwacji.zapisz();
	koniec_rezerwacji.zapisz();
	
	fstream zapis;
	zapis.open("baza_rezerwacji.txt", ios::out | ios::app);

	zapis << protokol << endl << koszt_rezerwacji << endl;

	zapis.close();
}