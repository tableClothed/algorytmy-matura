#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

void Zadanko1() {
	fstream file;
	string linijka = "";
	int licz = 0;

	file.open("dane.txt");

	if (file.good()) {
		while (!file.eof()) {
			file >> linijka;


			if (linijka[0] == linijka[linijka.length() - 1])
				licz++;
		}
	}
	else {
		cout << "Cos poszlo nie tak podczas otiwerania pliku" << endl;
	}

	cout << licz << " - tyle liczb" << endl;
}

string Osemkowy_To_Dec(string linijka) {
	int potega = linijka.length() - 1;
	string dec = "";
	int pierwsza_cyfra = 0;
	for (int i = 0; i < linijka.length() - 1; i++) {
		int cyfra = (int)(linijka[i]);
		int decym = cyfra * pow(8, potega);
		if (i == 0) {
			pierwsza_cyfra = decym;
		}
		dec +=  to_string(decym);
		potega--;
	}

	return dec;
}

void Zadanko2() {
	fstream file;
	string linijka = "";
	int licz = 0;

	file.open("dane.txt");

	if (file.good()) {
		while (!file.eof()) {
			file >> linijka;


			string dec = Osemkowy_To_Dec(linijka);

			if (dec[0] == dec[dec.length() - 1])
				licz++;

			//cout << dec << endl;
		}
	}
	else {
		cout << "Cos poszlo nie tak podczas otiwerania pliku" << endl;
	}

	cout << licz << " - tyle liczb" << endl;
}

bool Loop_Thrugh(string linijka) {
	int a = linijka[0];
	int b = 0;
	for (int i = 0; i < linijka.length() - 1; i++) {
		b = (linijka[i+1]);
		if (a < b) {
			//cout << "a: " << a << ", b:" << b << endl;
			a = b;
		}
		else {
			return false;
		}
	}
	cout << linijka << endl;
	return true;
}

void Zadanko3() {
	fstream file;
	string linijka = "";
	int licz = 0, j=0;

	file.open("dane.txt");

	if (file.good()) {
		//while ( j < 2) {
		while (!file.eof()) {
			file >> linijka;

			if (Loop_Thrugh(linijka))
				licz++;
			j++;
		}
	}
	else {
		cout << "Cos poszlo nie tak podczas otiwerania pliku" << endl;
	}

	cout << licz << " - tyle liczb" << endl;
}

int main() {
	Zadanko3();
	return 0;
}