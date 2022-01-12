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

	zapis << marka<<endl<<model<<endl<<ilosc_drzwi<<endl<<rodzaj_nadwozia<<endl<<numer_rejestracji<<endl<<cena_za_dobe << endl;

	zapis.close();
	
}

void Menedzer::usun_samochod(Samochod samochod) {
	Samochod flota_samochodow[100];

	string marka;
	string model;
	int ilosc_drzwi = 0;
	string rodzaj_nadwozia;
	string numer_rejestracji;
	int cena_za_dobe = 0;

	//tworzenie tablicy z pliku txt
	ifstream odczyt("baza_samochodow.txt");

	int i = 0;
	while (!odczyt.eof()) {

		odczyt >> marka >> model >> ilosc_drzwi >> rodzaj_nadwozia >> numer_rejestracji >> cena_za_dobe;

		flota_samochodow[i].set_samochod(marka, model, ilosc_drzwi, rodzaj_nadwozia, numer_rejestracji, cena_za_dobe);

		i++;
	}
	odczyt.close();

	//usuwanie elementu z tablicy
	for (int i = 0; i < 100; i++) {
		if (flota_samochodow[i] == samochod) {
			for (int j = i; j < (100 - 1); j++)
			{
				flota_samochodow[j] = flota_samochodow[j + 1];
			}
			break;
		}
	}

	//czyszczenie pliku txt
	std::ofstream ofs;
	ofs.open("baza_samochodow.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	//wpisanie nowej tablicy do pliku
	fstream zapis;
	zapis.open("baza_samochodow.txt", ios::out | ios::app);
	for (int i = 0; i < 100; i++) {
		if (flota_samochodow[i].get_marka()!="") {
			if (i == 0) {
			zapis << flota_samochodow[i].get_marka() << endl << flota_samochodow[i].get_model() << endl << flota_samochodow[i].get_ilosc_drzwi() << endl << flota_samochodow[i].get_rodzaj_nadwozia() << endl << flota_samochodow[i].get_numer_rejestracji() << endl << flota_samochodow[i].get_cena_za_dobe();
			}
			else {
				zapis << endl << flota_samochodow[i].get_marka() << endl << flota_samochodow[i].get_model() << endl << flota_samochodow[i].get_ilosc_drzwi() << endl << flota_samochodow[i].get_rodzaj_nadwozia() << endl << flota_samochodow[i].get_numer_rejestracji() << endl << flota_samochodow[i].get_cena_za_dobe();
			}
		}

	}

	zapis.close();
}


void Menedzer::edytuj_samochod(Samochod samochod) {
	Samochod flota_samochodow[100];

	string marka;
	string model;
	int ilosc_drzwi = 0;
	string rodzaj_nadwozia;
	string numer_rejestracji;
	int cena_za_dobe = 0;

	//tworzenie tablicy z pliku txt
	ifstream odczyt("baza_samochodow.txt");

	int i = 0;
	while (!odczyt.eof()) {

		odczyt >> marka >> model >> ilosc_drzwi >> rodzaj_nadwozia >> numer_rejestracji >> cena_za_dobe;

		flota_samochodow[i].set_samochod(marka, model, ilosc_drzwi, rodzaj_nadwozia, numer_rejestracji, cena_za_dobe);

		i++;
	}
	odczyt.close();

	//tworzenie samochodu z nowymi danymi
	cout << "Obecna marka: " << samochod.get_marka() << endl;
	cout << "Nowa marka: ";
	cin >> marka;
	cout << endl;
	cout << "Obecny model: " << samochod.get_model() << endl;
	cout << "Nowy model: ";
	cin >> model;
	cout << endl;
	cout << "Obecna ilosc drzwi: " << samochod.get_ilosc_drzwi() << endl;
	cout << "Nowa ilosc drzwi: ";
	cin >> ilosc_drzwi;
	cout << endl;
	cout << "Obecny rodzaj nadwozia: " << samochod.get_rodzaj_nadwozia() << endl;
	cout << "Nowa rodzaj nadwozia: ";
	cin >> rodzaj_nadwozia;
	cout << endl;
	cout << "Obecny numer rejestracji: " << samochod.get_numer_rejestracji() << endl;
	cout << "Nowy numer rejestracji: ";
	cin >> numer_rejestracji;
	cout << endl;
	cout << "Obecna cena za dobe: " << samochod.get_cena_za_dobe() << endl;
	cout << "Nowa cena za dobe: ";
	cin >> cena_za_dobe;
	cout << endl;
	
	Samochod e;
	e.set_samochod(marka, model, ilosc_drzwi, rodzaj_nadwozia, numer_rejestracji, cena_za_dobe);

	//podmiana elementu nowymi danymi
	for (int i = 0; i < 100; i++) {
		if (flota_samochodow[i] == samochod) {
			flota_samochodow[i] = e;
			break;
		}
	}

	//czyszczenie pliku txt
	std::ofstream ofs;
	ofs.open("baza_samochodow.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	//wpisanie nowej tablicy do pliku
	fstream zapis;
	zapis.open("baza_samochodow.txt", ios::out | ios::app);
	for (int i = 0; i < 100; i++) {
		if (flota_samochodow[i].get_marka() != "") {
			if (i == 0) {
				zapis << flota_samochodow[i].get_marka() << endl << flota_samochodow[i].get_model() << endl << flota_samochodow[i].get_ilosc_drzwi() << endl << flota_samochodow[i].get_rodzaj_nadwozia() << endl << flota_samochodow[i].get_numer_rejestracji() << endl << flota_samochodow[i].get_cena_za_dobe();
			}
			else {
				zapis << endl << flota_samochodow[i].get_marka() << endl << flota_samochodow[i].get_model() << endl << flota_samochodow[i].get_ilosc_drzwi() << endl << flota_samochodow[i].get_rodzaj_nadwozia() << endl << flota_samochodow[i].get_numer_rejestracji() << endl << flota_samochodow[i].get_cena_za_dobe();
			}
		}

	}

	zapis.close();

}


Menedzer::Menedzer() {
	this->login = "brak";
	this->haslo = "brak";
}

Menedzer::Menedzer(string _login, string _haslo) {
	this->login = _login;
	this->haslo = _haslo;
}
string Menedzer::get_haslo() {
	return haslo;
}
string Menedzer::get_login() {
	return login;
}