#include <iostream>
#include <regex>
#include <string>

using namespace std;

void przegladanie_samochodow();
void rejestracja();

bool is_email_valid(const string& email)
{
	// define a regular expression
	const regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return regex_match(email, pattern);
}

void menu_start() {
	system("CLS");
	int wybor;
	cout << "Witaj w wypozyczalni Ultra Flota" << endl;
	cout << "Wybierz co chcesz zrobic." << endl;
	cout << "1. Przegladaj samochody." << endl;
	cout << "2. Zarejestruj sie." << endl;
	cout << "3. Zmien termin najmu." << endl;
	cout << "4. Odbierz samochod. (Wymagane konto pracownika)" << endl;
	cout << "5. Wydaj samochod. (Wymagane konto pracownika)" << endl;
	cout << "6. Zarzadzaj baza pojazdow. (Wymagane konto menedzera)" << endl;
	cout << "Wpisz liczbe: ";
	cin >> wybor;

	if (wybor == 1) {
		przegladanie_samochodow();
	}
	else if (wybor == 2) {
		rejestracja();
	}
}

void przegladanie_samochodow() {
	system("CLS");
	int a;
	cout << "0. Powrot." << endl;
	cout << "Aby zarezerwowac samochod wpisz jego numer" << endl;
	cout << "Lista dostepnych samochodow:" << endl;
	//tu trzeba zrobic to wczytywanie z pliku
	cout << "1. Fiesta" << endl;
	cout << "2. Opelek" << endl;
	cout << "Wybor: ";
	cin >> a;
	if (a == 0) {
		menu_start();
	}
}

void rejestracja() {
	system("CLS");
	int wybor;
	cout << "0. Powrot"<< endl;
	cout << "1. Formularz rejestracji" << endl;
Wybor:
	cout << "Wybor: ";
	cin >> wybor;
	if (wybor == 0) {
		menu_start();
	}
	else if (wybor == 1) {
		string imie;
		string nazwisko;
		string email;
		string nr_prawa_jazdy;
		string haslo;
		cout << "Wpisz imie:" << endl;
		cin >> imie;
		cout << endl;
		cout << "Wpisz nazwisko:" << endl;
		cin >> nazwisko;
		cout << endl;
	Email: //tu cos nie gra bo od razu wywala ze bledny email i potem juz dziala dobrze
		cout << "Wpisz email:" << endl;
		cin >> email;
		if (is_email_valid(email)) {
			cout << "Wpisz numer prawa jazdy:" << endl;
			cin >> nr_prawa_jazdy;
			cout << endl;
			cout << "Wprowadz haslo:"<<endl;
			cin >> haslo;
			//i tu konstruktor klient(tu dane)
		}
		else {
			cout << "Niepoprawny adres email. Sprobuj ponownie." << endl;
			goto Email;
		}
	}
	else {
		cout << "Wybrano zla wartosc. Sprobuj ponownie." << endl;
		goto Wybor;
	}
}

int main() {
	
	menu_start();

}

