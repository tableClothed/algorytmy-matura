#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Odkoduj() {
	fstream plik;
	plik.open("../przyklad.txt");

	string komunikat = "", linijka;
	int i = 40;


	if (plik.good()) {
		while (!plik.eof()) {
			for (int i = 0; i < 40; i = i + 40) {
				getline(plik, linijka);
				if (linijka.length() >= 10) {
					komunikat += linijka[linijka.length() - 1];
				}
			}
		}
	}
	else {
		cout << "Cos mordo poszlo nie tak" << endl;
	}


	plik.close();

	cout << komunikat;

}

bool czy_jest_w_tablicy(string tekst, char znak) {
	for (int i = 0; i < tekst.length(); i++) {
		if (tekst[i] == znak) {
			return true;
		}
	}
	return false;
}

int Licz_niepowtarzajace(string tekst) {

	string nowy_tekst = "";


	for (int i = 0; i < tekst.length(); i++) {
		if (!czy_jest_w_tablicy(nowy_tekst, tekst[i])) {
			nowy_tekst += tekst[i];
		}
	}

	return nowy_tekst.length();
}

void Odleglosc_liter() {
	fstream plik;
	string linijka;
	const int char_num = 65;
	int suma = 0;
	string linijka_do_wyswietlenia = "";


	plik.open("../przyklad.txt");

	if (plik.good()) {
		while (!plik.eof()) {
			getline(plik, linijka);
			for (int i = 1; i <= linijka.length(); i++) {
				linijka_do_wyswietlenia += linijka[i - 1];
				int wartosc_cyfry = (int)(linijka[i - 1]) - (int)(linijka[i]);
				if (wartosc_cyfry < 0) wartosc_cyfry *= -1;

				//cout << wartosc_cyfry << " pomiedzy " << linijka[i - 1] << " i " << linijka[i] << endl;

				if (suma + wartosc_cyfry <= 10) {
					suma += wartosc_cyfry;
					//linijka_do_wyswietlenia += linijka[i - 1];
					//linijka_do_wyswietlenia += linijka[i];
				}
				else {
					suma = 0;
					cout << linijka_do_wyswietlenia << endl;
					linijka_do_wyswietlenia = "";
				}
			}
		}

	}
	else {
		cout << "Cos poszlo nie tak z otwieraniem pliku" << endl;
	}

	plik.close();
}

void Odl() {
	string linijka = "ABEZA";
	int suma = 0;
	string linijka_do_wyswietlenia = "";


	for (int i = 1; i <= linijka.length(); i++) {
		linijka_do_wyswietlenia += linijka[i - 1];
		int wartosc_cyfry = (int)(linijka[i - 1]) - (int)(linijka[i]);
		if (wartosc_cyfry < 0) wartosc_cyfry *= -1;

		cout << wartosc_cyfry << " pomiedzy " << linijka[i - 1] << " i " << linijka[i] << endl;

		if (suma + wartosc_cyfry <= 10) {
			suma += wartosc_cyfry;
			//linijka_do_wyswietlenia += linijka[i - 1];
			//linijka_do_wyswietlenia += linijka[i];
		}
		else {
			suma = 0;
			cout << linijka_do_wyswietlenia << endl;
			linijka_do_wyswietlenia = "";
		}
	}

}

void Najdluzsza_linijka() {
	fstream plik;
	plik.open("../przyklad.txt");

	string najdluzsza_linijka, linijka;
	int i = 40, najdluszy_string = 0;


	if (plik.good()) {
		while (!plik.eof()) {
			for (int i = 0; i < 40; i = i + 40) {
				getline(plik, linijka);
				if (Licz_niepowtarzajace(linijka) > najdluszy_string) {

					najdluszy_string = Licz_niepowtarzajace(linijka);
					najdluzsza_linijka = linijka;
				}
			}
		}
	}
	else {
		cout << "Cos mordo poszlo nie tak" << endl;
	}


	plik.close();

	cout << najdluzsza_linijka << " " << najdluszy_string;

}

void Wyswietl_tablice(int tabX[], int tabY[], int n) {
	for (int i = 0; i < n; i++) {
		cout << tabX[i] << " " << tabY[i] << endl;
	}
}

void Szczyty() {
	const int n = 5;
	int X[5] = {-3, 1, 2, 3, -2};
	int Y[5] = {3, 3, 1, 4, 2};

	int x = X[1], y = Y[1];

	for (int i = 0; i < n; i++) {
		if (X[i] / Y[i] <= x / y) {
			x = X[i];
			y = Y[i];
		}
	}

	cout << "Szczyt najbardziej na lewo to ma wspolrzedne " << x << ", " << y << endl;


}

void Posegreguj() {
	const int n = 5;
	int X[5] = { -3, 1, 2, 3, -2 };
	int Y[5] = { 3, 3, 1, 4, 2 };

	for (int i = 0; i < n; i++) {
				int x = X[i], y = Y[i];
		for (int j = i + 1; j < n; j++) {
			int x = X[i], y = Y[i];

			if ((X[j] / Y[j] <= X[i] / Y[i]) && (X[j] < X[i])) {

				X[i] = X[j]; Y[i] = Y[j];

				X[j] = x; Y[j] = y;
			}
		}
	}

	Wyswietl_tablice(X, Y, n);

	
}


//int main()
//{
	//Odkoduj();
	//Najdluzsza_linijka();
	//Odleglosc_liter();
	//Odl();
	//Szczyty();
	//Posegreguj();

	//return 0;
//}
