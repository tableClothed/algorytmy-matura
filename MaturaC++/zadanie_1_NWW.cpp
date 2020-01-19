// nww.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int NWW(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	else if (a == b) {
		return a;
	}

	for (int i = b; i <= a * b; i++) {
		if ((i % a == 0) && (i % b == 0)) {
			return i;
		}
	}
}


bool Sprawdz_dla_w(int j, vector<int> n) {
	for (int i = 0; i < n.size(); i++) {
		if (j % n[i] != 0) {
			return false;
		}
	}
	return true;
}

int NW() {
	vector <int> nw;
	nw.clear();
	int x = -1;

	cout << "Podaj liczby dla ktorych chcesz wyszukac wspolny nww. 0 konczy" << endl;


	while (x != 0) {
		cin >> x;
		if (x == 0) break;
		nw.push_back(x);
	}

	// Szukanie najmniejszej wartosci i iloczyn
	int min = 100, iloczyn = 1;

	for (int i = 0; i < nw.size(); i++) {
		if (nw[i] < min) {
			min = nw[i];
		}
		iloczyn *= nw[i];
	}

	for (int i = 2; i <= iloczyn; i++) {
		if (Sprawdz_dla_w(i, nw)) {
			return i;
		}
	}

}

int NNW(vector<int> nw) {

	// Szukanie najmniejszej wartosci i iloczyn
	int min = 100, iloczyn = 1;

	for (int i = 0; i < nw.size(); i++) {
		if (nw[i] < min) {
			min = nw[i];
		}
		iloczyn *= nw[i];
	}

	for (int i = 2; i <= iloczyn; i++) {
		if (Sprawdz_dla_w(i, nw)) {
			exit;
			return i;
		}
	}

}


void Czytaj_wektor(vector<int> v) {
	if (v.empty()) {
		cout << "NIE" << endl;
		exit;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;
}

void Szukaj(int x) {
	vector <int> v;
	int nww = 0;
	v.clear();

	for (int i = 1; i < x; i++) {
		for (int j = i; j < x; j++) {

			if (v.size() == 0)
				nww = 0;
			else
				nww = NNW(v);


			if (nww < x) {
				v.push_back(j);
			}
			else if (nww > x) {
				v.clear();
				break;
			}
			else if (nww == x) break;
		}
		if (nww == x) break;

	}

	Czytaj_wektor(v);
}



int main()
{
	int zapytania = 0;
	cout << "Ile zapytan pragniesz wykonac? " << endl;
	cin >> zapytania;

	for (int i = 0; i < zapytania; i++) {
		cout << "Dla jakiej liczby szukasz? ";
		int a;
		cin >> a;
		Szukaj(a);
	}

	return 0;
}

