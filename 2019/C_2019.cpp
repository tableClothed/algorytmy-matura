#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const int piec = 1;


void Szukaj_70() {
	fstream plik;

	char znak = 'x';
	string znaki = "";
	float licz_powierzchnie_trawa = 0;
	float wynik = 0;

	float powierzchnia_dzialki = 30 * 30;
	int i = 0;
	int ile_dzialek = 0;

	//plik.open("dzialki.txt");
	plik.open("przyklad_dz.txt");

	if (plik.good()) {
		while (!plik.eof()) {
			for (int i = 0; i < 30; i++) {
				plik >> znaki;
				for (int j = 0; j < 30; j++) {
					znak = znaki[j];

					if (znak == '*')
						licz_powierzchnie_trawa++;

				}

			}
			wynik = licz_powierzchnie_trawa / powierzchnia_dzialki;

			cout << licz_powierzchnie_trawa << " " << powierzchnia_dzialki <<  " " << wynik << endl;
			if (wynik >= 0.7) {
				ile_dzialek++;
			}

			licz_powierzchnie_trawa = 0;
		}
	}
	else {
		cout << "Cos poszlo nie tak podczas otwierania" << endl;
	}

	plik.close();

	cout << "Ilosc dzialek, ktore maja 70% trawy: " << ile_dzialek << endl;
}

void Porownaj_tablice(string tab1[], string tab2[]) {
	int licz = 0;
	for (int i = 0; i < piec; i++) {
		for (int j = i + 1; j < piec; j++) {
			if (tab1[i] == tab2[j]) {
				licz++;
				//cout << "tab 1:" << endl << tab1[i] << endl << "tab 2: " << endl << tab2[j] << endl << endl;
				cout << "Numery dzia³ek: " << i + 1 << ", " << j + 1 << endl;
			}
		}
	}

	cout << "Ilosc takich samych: " << licz << endl;
}

void Wyswietl_tablice(string tab[]) {
	for (int i = 0; i < piec; i++) {
		cout << tab[i] << endl;
	}
}

void Sprawdz(string tablica[]) {
	string tab[piec];
	int j = 0;

	for (int j = 0; j < piec; j++) {
		string s = tablica[j];
		for (int i = 0; i < 30 * 30; i++) {
			tab[j] += s[((30 * 30)-1) - i];
		}
	}

	//Wyswietl_tablice(tab);
	//cout << endl << endl << endl;
	//Wyswietl_tablice(tablica);

	Porownaj_tablice(tablica, tab);
	
}

void Takie_same_dzialki() {
	fstream plik;


	char znak = 'x';
	string znaki = "";
	float wynik = 0;

	string tablica[piec];
	int k = 0;

	plik.open("dzialki.txt");
	//plik.open("przyklad_dz.txt");

	if (plik.good()) {
		while (k < piec) {
			for (int i = 0; i < 30; i++) {
				plik >> znaki;
				for (int j = 0; j < 30; j++) {
					znak = znaki[j];

					tablica[k] += znak;
				}

			}
			k++;
		}

		Sprawdz(tablica);
	}
	else {
		cout << "Cos poszlo nie tak podczas otwierania" << endl;
	}

	plik.close();
}

void Sprawdz_pole(string tab[], int & max_pole) {
	char znak = 'v';
	int x = 1;
	bool nie_znak = true;

	//Wyswietl_tablice(tab);

	while ((nie_znak) && (x < 30)) {
		for (int i = 0; i < x; i++) {
			string u = tab[i];
			for (int j = 0; j < x; j++) {
				znak = u[j];
				//cout << znak << endl;
				if (znak == 'X') {
					cout << x << endl;
					//cout << "elo " << endl;
				}
			}
		}
		x++;

	}

	max_pole = x;


}

void Znajdz_max_kwadrat() {
	fstream plik;

	string tab[30];

	int k = 0;
	int max_pole = 0;
	string linijka = "";

	//plik.open("dzialki.txt");
	plik.open("przyklad_dz.txt");

	if (plik.good()) {
		while (!plik.eof()) {
			while (k < 30) {
				for (int i = 0; i < 30; i++) {
					plik >> linijka;
					tab[i] = linijka;
				}
				Sprawdz_pole(tab, max_pole);
				//Wyswietl_tablice(tab);
				k++;
			}
		}
		
	}
	else {
		cout << "Cos poszlo nie tak podczas otwierania" << endl;
	}

	plik.close();

	cout << "Max pole: " << max_pole << endl;
}

//int main() {
	//Szukaj_70();
	//Takie_same_dzialki();
	//Znajdz_max_kwadrat();

	//return 0;
//}