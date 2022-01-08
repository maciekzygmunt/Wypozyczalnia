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
	koszt_rezerwacji = 0;
}

Rezerwacja::Rezerwacja(Data _poczatek, Data _koniec, Wypozyczenie _wypozyczenie, string _protokol, int _koszt_rezerwacji) {
	poczatek_rezerwacji = _poczatek;
	koniec_rezerwacji = _koniec;
	wypozyczenie = _wypozyczenie;
	protokol = _protokol;
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
	int koszt = 120;
	
	return koszt;
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