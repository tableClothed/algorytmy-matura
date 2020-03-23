#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

bool Czy_Pierwsza(int liczba) {
	bool czy_bin = true;
	for (int i = 2; i < liczba; i++) {
		if (liczba % i == 0)
			czy_bin = false;
	}
	return czy_bin;
}

void Zad_1() {
	fstream file;
	string linijka = "";
	int suma = 0, policz_pierwsze = 0;

	file.open("NAPIS.TXT");

	if (file.good()) {
		while (!file.eof()) {
			file >> linijka;
			for (int i = 0; i < linijka.length(); i++) {
				suma += (int)linijka[i];
				//cout << suma << " ";
			}
			//cout << endl;
			if (Czy_Pierwsza(suma)) policz_pierwsze++;

			suma = 0;
		}
	}
	else {
		cout << "Cos nie pyk³o" << endl;
	}

	cout << policz_pierwsze << endl;
}

void Zad_2() {
	fstream file;
	string linijka = "";
	bool czy_wieksza = false;
	int policz_wieksze = 0;

	file.open("NAPIS.TXT");

	if (file.good()) {
		while (!file.eof()) {
			file >> linijka;
			for (int i = 1; i < linijka.length(); i++) {
				int a = linijka[i];
				int b = linijka[i - 1];
				if (b < a) {
					czy_wieksza = true;
				}
				else {
					czy_wieksza = false;
				}
			}
			if (czy_wieksza) policz_wieksze++;

		}
	}
	else {
		cout << "Cos nie pyk³o" << endl;
	}

	cout << policz_wieksze << endl;
}

void Sprawdz_czy_istnieje(string tab[], int v) {
	vector <string> powtarzajace_sie;
	for (int i = 0; i < v; i++) {
		for (int j = i + 1; j < v; j++) {
			if ((tab[i] == tab[j]) && (find(powtarzajace_sie.begin(), powtarzajace_sie.end(), tab[i]) == powtarzajace_sie.end())) {
				powtarzajace_sie.push_back(tab[i]);
			}
		}
	}
	
	for (int k = 0; k < powtarzajace_sie.size(); k++) {
		cout << powtarzajace_sie[k] << endl;
	}
}

void Zad_3() {
	fstream file;
	string linijki[1000];
	bool czy_wieksza = false;
	int i = 0;

	file.open("NAPIS.TXT");

	if (file.good()) {
		while (!file.eof()) {
			file >> linijki[i];
			i++;
		}
	}
	else {
		cout << "Cos nie pyk³o" << endl;
	}

	Sprawdz_czy_istnieje(linijki, 1000);
}

//int main() {
	//Zad_1();
	//Zad_2();
	//Zad_3();
	//return 0;
//}