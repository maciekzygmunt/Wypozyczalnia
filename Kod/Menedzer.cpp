#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

#include "Menedzer.h"
#include "Samochod.h"
#include "Pracownik.h"

void Menedzer::dodaj_samochod() {
	string marka;
	string model;
	int ilosc_drzwi;
	string rodzaj_nadwozia;
	string numer_rejestracji;
	int cena_za_dobe;

	cout << "Marka samochodu:" << endl;
	cin >> marka;
	cout << endl;
	cout << "Model samochodu:" << endl;
	cin >> model;
	cout << endl;
	cout << "Ilosc drzwi:" << endl;
	cin >> ilosc_drzwi;
	cout << endl;
	cout << "Rodzaj nadwozia:" << endl;
	cin >> rodzaj_nadwozia;
	cout << endl;
	cout << "Numer rejestracji:" << endl;
	cin >> numer_rejestracji;
	cout << endl;
	cout << "Cena za dobe:" << endl;
	cin >> cena_za_dobe;
	cout << endl;

	fstream zapis;
	zapis.open("baza_samochodow.txt", ios::out | ios::app);

	zapis << marka<<endl<<model<<endl<<ilosc_drzwi<<endl<<rodzaj_nadwozia<<endl<<numer_rejestracji<<endl<<cena_za_dobe<<endl;

	zapis.close();
	
}

void Menedzer::usun_samochod(Samochod samochod) {
	throw "Not yet implemented";
}

void Menedzer::edytuj_samochod(Samochod samochod) {
	throw "Not yet implemented";
}

