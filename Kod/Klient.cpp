#include <exception>
#include <string>
#include<fstream>

using namespace std;

#include "Klient.h"
#include "Rezerwacja.h"

void Klient::rejestracja(string imie, string nazwisko, string adres_email, string haslo, string numer_prawa_jazdy) {
	ofstream zapis("baza_klientow.txt");

	zapis << imie << endl << nazwisko << endl << adres_email << endl << haslo << endl << numer_prawa_jazdy << endl;

	zapis.close();
}

void Klient::zaplac(Rezerwacja rezerwacja) {
	throw "Not yet implemented";
}