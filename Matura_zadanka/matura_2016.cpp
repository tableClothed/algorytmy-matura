#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int a = 200, b = 200, r = 200;


void Brzeg_Okregu() {
	fstream file;
	int x = 0, y = 0;
	int a = 200, b = 200, r = 200;
	int wnetrze = 0;

	file.open("punkty.txt");

	if (file.good()) {
		while (file.eof()) {
			file >> x >> y;
			
			if (pow(x - a, 2) + pow(y - b, 2) == pow(r, 2)) {
				cout << x << " " << y << endl;
			}
			else if (pow(x - a, 2) + pow(y - 200, 2) < pow(r, 2)) {
				wnetrze++;
			}
		}
		
	}
	else {
		cout << "Cos posz³o nie tak podczas otwierania pliku" << endl;
	}

	file.close();

	cout << "Ilosc punktow we wnetrzu " << wnetrze << endl;
}

double Wartosc_PI_Dla(int pkt_ko, int p) {
	int r = 200, pkt_kw = p;
	double p_kw = pow(400, 2), p_ko = 0, PI = 0;

	p_ko = (pkt_ko * p_kw) / pkt_kw;
	PI = p_ko / pow(r, 2);

	return PI;
}

void Punkty_Kola() {
	fstream file("punkty.txt");
	int pkt_ko = 0;

	int x = 0, y = 0;
	int i = 0;
	int s_100, s_1000, s_5000, s_all;


	if (file.good()) {
		while (!file.eof()) {
			i++;
			file >> x >> y;

			if (pow(x - a, 2) + pow(y - b, 2) < pow(r, 2)) {
				pkt_ko++;
			}
			if (i == 100) s_100 = pkt_ko;
			if (i == 1000) s_1000 = pkt_ko;
			if (i == 5000) s_5000 = pkt_ko;
		}	
	}
	else {
		cout << "Cos posz³o nie tak podczas otwierania pliku" << endl;
	}

	s_all = pkt_ko;

	cout << "Dla 100 punktów " << setprecision(4) << Wartosc_PI_Dla(s_100, 100) << endl;
	cout << "Dla 1000 punktów " << setprecision(4) << Wartosc_PI_Dla(s_1000, 1000) << endl;
	cout << "Dla 5000 punktów " << setprecision(4) << Wartosc_PI_Dla(s_5000, 5000) << endl;
	cout << "Dla wszystkich punktów " << setprecision(4)  << Wartosc_PI_Dla(s_all, 10000) << endl;


	file.close();

}

void Zapisz_PI() {
	fstream file("punkty.txt");
	ofstream plik("zad3.txt");

	int pkt_ko = 0;

	int x = 0, y = 0;
	int i = 0;
	double PI = 0;


	if (file.good()) {
		while (i < 1700) {
			i++;
			file >> x >> y;

			if (pow(x - a, 2) + pow(y - b, 2) < pow(r, 2)) {
				pkt_ko++;
			}
			PI = Wartosc_PI_Dla(pkt_ko, i);

			plik << x  << " " << y << " " <<  PI << endl;
		}
	}
	else {
		cout << "Cos posz³o nie tak podczas otwierania pliku" << endl;
	}

	file.close();
	plik.close();
}

string Szyfruj(string linijka, int klucz) {
	string szyfr = "";
	char x = '0';
	int wartosc_x = 0;

	int alfabet_przedzial = ((int)'Z' - (int)'A')+1;
	klucz = klucz % alfabet_przedzial;

	for (int i = 0; i < linijka.length(); i++) {
		x = linijka[i];
		wartosc_x = (int)x;
		wartosc_x += klucz;

		if (wartosc_x > (int)'Z') {
			wartosc_x -= alfabet_przedzial;
		}

		x = (char)wartosc_x;

		szyfr += x;
	}

	return szyfr;
}

void Zad1() {
	fstream plik;
	string linijka = "";

	plik.open("dane_6_1.txt");
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> linijka;
			cout << Szyfruj(linijka, 107) << endl;
		}
	}
	else {
		cout << "Cos poszlo nie tak podcas otwierania pliku" << endl;
	}
}

string Odszyfruj(string szyfr, int klucz) {
	string linijka = "";
	char x = '0';
	int wartosc_x = 0;

	int alfabet_przedzial = ((int)'Z' - (int)'A') + 1;
	klucz = klucz % alfabet_przedzial;

	for (int i = 0; i < szyfr.length(); i++) {
		x = szyfr[i];
		wartosc_x = (int)x;
		wartosc_x -= klucz;

		if (wartosc_x < (int)'A') {
			wartosc_x += alfabet_przedzial;
		}

		x = (char)wartosc_x;

		linijka += x;
	}

	return linijka;
}

void Zad2() {
	fstream plik;
	string linijka = "";
	int klucz;

	int i = 0;

	plik.open("dane_6_2.txt");
	if (plik.good()) {
		//while (i < 1) {
		while (i < 3000) {
		//while (getline(plik, linijka)) {
			plik >> linijka >> klucz;
			if ((linijka == "") || (klucz == NULL)) {
				i++;
				continue;
			}
			cout << Odszyfruj(linijka, klucz) << endl;
			i++;
		}
	}
	else {
		cout << "Cos poszlo nie tak podcas otwierania pliku" << endl;
	}
}

int Szukaj_Klucza(string linijka, string szyfr) {
	int klucz = (int)szyfr[0] - (int)linijka[0];

	int przedzial_alfabet = ((int)'Z' - (int)'A') + 1;

	if (klucz < 0) {
		klucz = przedzial_alfabet + klucz;
	}

	return klucz;

}

void Zad3() {
	fstream plik;
	string linijka = "", szyfr = "";
	int klucz;

	int i = 0;

	plik.open("dane_6_3.txt");
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> linijka >> szyfr;
			klucz = Szukaj_Klucza(linijka, szyfr);

			if (linijka != Odszyfruj(szyfr, klucz)) {
				//cout << Odszyfruj(szyfr, klucz) << endl;
				cout <<linijka << " " << szyfr << " " << klucz << endl;
			}
		}
	}
	else {
		cout << "Cos poszlo nie tak podcas otwierania pliku" << endl;
	}
}


int main() {
	//Brzeg_Okregu();
	//Punkty_Kola();
	//Zapisz_PI();
	//Zad1();
	//Zad2();
	Zad3();

	return 0;
}