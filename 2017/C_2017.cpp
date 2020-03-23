#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include "matura_2017.h"
using namespace std;

void Wyznacz_min_max(int x, int & min, int & max) {
	if (x > max) {
		max = x;
	}
	else if (x < min) {
		min = x;
	}
}

void Min_Max()
{
	ifstream file;
	int a;
	int min = 100;
	int max = -100;
	string linijka = "";
	file.open("przyklad.txt");

	if (file.good()) {
		while (!file.eof()) {
			file >> a;
			Wyznacz_min_max(a, min, max);
		}
	}
	else {
		cout << "Nie udało się otworzyć pliku." << endl;
	}

	file.close();

	cout << "Wartosc min " << min << ", wartosc max " << max << endl;
}

void Sprawdz_Symetrie(int tab[], int wielkosc_tab, int & roznice) {
	for (int i = 0; i < wielkosc_tab; i++) {
		if (tab[i] != tab[(wielkosc_tab-1) - i]) {
			roznice++;
			break;
		}
	}

}

void Symetria() {
	ifstream file;
	int a;
	int wielkosc_tab = 320;
	int roznice = 0;
	file.open("przykladq.txt");

	if (file.good()) {
		while (!file.eof()) {
			int tab[320];
			for (int i = 0; i < wielkosc_tab; i++) {
				file >> tab[i];
			}
			Sprawdz_Symetrie(tab, wielkosc_tab, roznice);
		}
	}
	else {
		cout << "Nie udało się otworzyć pliku." << endl;
	}

	file.close();

	cout << "Trzeba usunac " << roznice << " linijki" << endl;

}

bool Czy_sie_powtarzaja(int i, int j, int pow_i[], int pow_j[], int index) {
	bool powt = false;
	for (int a = 0; a < index; a++) {
		if ((pow_i[a] == i && pow_j[a] == j)
			|| (pow_i[a] == j && pow_j[a] == i)) {
			powt = true;
			break;
		}
	}
	return powt;
}

int Licz_sasiednie(int tablica[][200]) {
	int sasiednie = 0;
	int * powtarzajace_i = new int[10];
	int * powtarzajace_j = new int[10];
	int index = 0;


	for (int i = 1; i < 199; i++) {
		for (int j = 1; j < 319; j++) {
			bool sasiednie_x1 = abs(tablica[i][j] - tablica[i][j + 1]) > 128;
			bool sasiednie_x2 = abs(tablica[i][j] - tablica[i][j - 1]) > 128;
			bool sasiednie_y1 = abs(tablica[i][j] - tablica[i + 1][j]) > 128;
			bool sasiednie_y2 = abs(tablica[i][j] - tablica[i - 1][j]) > 128;
			if (sasiednie_x1 || sasiednie_x2 || sasiednie_y1 || sasiednie_y2) {
				if (sasiednie_x1) {
					cout << "A " << tablica[i][j] << " B " << tablica[i][j + 1] << endl;
					cout << "Tablice o indexach " << i << " " << j << " oraz " << i << " " << j + 1 << endl;
				}
				if (sasiednie_x2) {
					cout << "A " << tablica[i][j] << " B " << tablica[i][j - 1] << endl;
					cout << "Tablice o indexach " << i << " " << j << " oraz " << i << " " << j - 1 << endl;

				}
				if (sasiednie_y1) {
					cout << "A " << tablica[i][j] << " B " << tablica[i + 1][j] << endl;
					cout << "Tablice o indexach " << i << " " << j << " oraz " << i + 1 << " " << j << endl;
				}
				if (sasiednie_y2) {
					cout << "A " << tablica[i][j] << " B " << tablica[i - 1][j] << endl;
					cout << "Tablice o indexach " << i << " " << j << " oraz " << i - 1 << " " << j << endl;
				}

				if (Czy_sie_powtarzaja(i, j, powtarzajace_i, powtarzajace_j, index)) break;

				sasiednie++;
				powtarzajace_i[index] = i;
				powtarzajace_j[index] = j;
				index++;
			}
		}
	}
	return sasiednie;
}

void Sasiednie_Piksele() {
	ifstream file;
	int a;
	const int width = 320, height = 200;
	int tablica[width][height];

	file.open("przykladq.txt");

	if (file.good()) {
		while (!file.eof()) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					file >> a;
					tablica[i][j] = a;
				}
			}
		}
	}
	else {
		cout << "Nie udało się otworzyć pliku." << endl;
	}

	file.close();

	cout << "Ilosc sasiednich konstatralala " << Licz_sasiednie(tablica) << endl;;
}

void Czytaj_pionowa(int tab[][200]) {
	int licz = 0;
	int index_pionowo = 0;
	int najdlusza = 0;
	for (int i = 1; i < 200; i++) {
		if (tab[index_pionowo][i] == tab[index_pionowo][i-1]) {
			cout << tab[index_pionowo][i] << " " << tab[index_pionowo][i - 1] << endl;
			cout << "Index1 " << index_pionowo << ", " << i << " ; Index2 " << index_pionowo << ", " << i - 1 << endl;
			licz++;
			if (licz > najdlusza) {
				najdlusza = licz;
			}
		}
		else {
			
			i = 1;
			licz = 0;
			if (index_pionowo > 320) return;
			index_pionowo++;
		}
	}

	cout << "Najdluzsza " << najdlusza << endl;
}

void Najdluzsza() {
	ifstream file;
	int a;
	const int width = 320, height = 200;
	int tablica[width][height];

	file.open("przykladq.txt");

	if (file.good()) {
		while (!file.eof()) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					file >> a;
					tablica[i][j] = a;
				}
			}
		}
	}
	else {
		cout << "Nie udało się otworzyć pliku." << endl;
	}

	file.close();

	Czytaj_pionowa(tablica);
}

void Najwieksze_pole() {
	int A[11] = { 6, 28, 7, 12, 10, 14, 5, 9, 4, 8, 18 };
	int najwieksze_pole = 0, p = 7;

	for (int i = 0; i < 11; i++) {
		for (int j = i + 1; j < 11; j++) {
			if (A[i] * A[j] % p != 0) {
				if (A[i] * A[j] > najwieksze_pole) {
					najwieksze_pole = A[i] * A[j];
				}
			}
		}
	}

	cout << "Najwieksze pole " << najwieksze_pole << endl;
}


//int main()
//{
	//Min_Max();
	//Symetria();
	//Sasiednie_Piksele();
//	Najdluzsza();
	//Najwieksze_pole();
//}

