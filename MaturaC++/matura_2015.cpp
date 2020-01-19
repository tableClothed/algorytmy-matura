#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool Licz_cyfry(string x) {
	int zera = 0, jedynki = 0;
	
	for (int i = 0; i < x.length(); i++) {
		if (x[i] == '0') zera++;
		else jedynki++;
	}

	if (zera > jedynki) {
		cout << "0: " << zera << ", 1: " << jedynki << endl;
		return true;
	}
	else return false;
}

void Binarne() {
	fstream plik;
	string x = "";
	int i = 0;
	cout << x << endl << endl;

	plik.open("liczby.txt");

	if (plik.good()) {
		while (!plik.eof()) {
			plik >> x;
			if (Licz_cyfry(x)) {
				cout << x << endl;
			}
		}
	}
	else {
		cout << "Cos poszlo nie tak" << endl;
	}

	plik.close();
}

void Dwojki(int & dwojki, int & osemki, string x) {
	if (x[x.length() - 1] == '0') {
		dwojki++;
	}
	else return;


	for (int i = x.length() - 1; i >= 0; i--) {
		int index = (x.length() - 1) - i;

		if (x[i] == '1') {
			if (index > 4) {
				osemki++;
			}
			return;		
		}
	}
}


void Binarnie2() {
	fstream plik;
	string x = "";
	int dwojki = 0, osemki = 0;

	plik.open("liczby.txt");

	if (plik.good()) {
		while (!plik.eof()) {
			plik >> x;
			Dwojki(dwojki, osemki, x);
		}
	}
	else {
		cout << "Cos poszlo nie tak" << endl;
	}

	plik.close();

	cout << "Dwojki: " << dwojki << endl << "Osemki: " << osemki << endl;
}

void Porownaj_min(string x, string & min, int & i_min, int i) {
	for (int i = 0; i < x.length() - 1; i++) {
		if (x[i] != min[i]) {
			if (x[i] == '0') {
				min = x;
				i_min = i;
			}
			return;
		}
	}
}

void Porownaj_max(string x, string & max, int & i_max, int i) {
	for (int i = 0; i < x.length() - 1; i++) {
		if (x[i] != max[i]) {
			if (x[i] == '1') {
				max = x;
				i_max = i;
			}
			return;
		}
	}
}

void Binarnie3() {
	fstream plik;
	string x = "";
	string min = "111", max = "";
	int i_min = 0, i_max = 0;
	int i = 0;

	plik.open("liczby.txt");

	if (plik.good()) {
		while (!plik.eof()) {
			i++;
			plik >> x;
			if (x.length() <= min.length()) {
				if (x.length() == min.length()) {
					Porownaj_min(x, min, i_min, i);
				}
				else {
					min = x;
				}
			}

			if (x.length() >= max.length()) {
				if (x.length() == max.length()) {
					Porownaj_max(x, max, i_max, i);
				}
				else {
					max = x;
				}
			}
		}
	}
	else {
		cout << "Cos poszlo nie tak" << endl;
	}

	plik.close();

	cout << "MAX: " << max << " w wierszu " << i_max << endl << "MIN: " << min << " w wierszu " << i_min << endl;
}


//int main() {
	//Binarne();
	//Binarnie2();
	//Binarnie3();
	//return 0;
//}