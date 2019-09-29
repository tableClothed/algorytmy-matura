// Matura_zadanka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

void Anagramy(string slowo1) {
	string slowo2 = slowo1;
	bool czy_anagram = true;
	for (int i = 0; i < slowo1.length(); i++) {
		if (slowo1[i] == slowo2[slowo1.length() - i]) {
			czy_anagram = false;
			break;
		}
	}
	cout << "Czy annagram: " << czy_anagram << endl;
}

void Dwojkowy(int liczba) {
	string binarna = "";
	while (liczba > 0) {
		if (liczba % 2 == 0) {
			binarna += "0";
		}
		else {
			binarna += "1";
		}
		liczba = round(liczba/2);
	}


	for (int i = binarna.length() - 1; i >= 0; i--)
	{
		cout << binarna[i];
	}
	cout << endl;

}

void Osemkowy(int liczba) {
	int potegi = -1;
	int kopia1 = liczba;

	while (kopia1 > 0) {
		kopia1 /= 8;
		potegi++;
	}

	cout << "Potegi " << potegi << endl;

	while (liczba > 0) {
		int modulo = pow(8, potegi);

		cout << liczba / modulo;

		liczba = liczba % modulo;
		//cout << "Liczba " << liczba << " modulo " << modulo << endl;
		potegi--;
	}
	cout << endl;

}

void Pierwsza(int liczba) {
	bool pierwsza = true;
	for (int i = 2; i < liczba; i++) {
		if (liczba % i == 0) {
			pierwsza = false;
			break;
		}

	}

	if (pierwsza) {
		cout << "Liczba jest pierwsza.";

	}
	else
	{
		cout << "Liczba nie jest pierwsza";
	}
}

void Doskonala(int liczba) {
	int doskonala = 0;
	for (int i = 1; i < liczba; i++) {
		if (liczba % i == 0) {
			doskonala += i;
		}
	}

	if (doskonala == liczba) {
		cout << "Liczba jest doskonala";
	}
	else {
		cout << "Liczba nie jest doskonala";
	}
}

void Rozklad_czynniki(int liczba) {
	cout << "Liczba " << liczba << endl;
	int i = 2;
	while (liczba > 1) {
		if (liczba % i == 0) {
			cout << i << "*";
			liczba /= i;
			i = 1;
		}
		i++;
	}

}

void Fibonacci(int liczba) {
	int a = 0;
	int b = 1;
	for (int i = 0; i < liczba; i++) {
		cout << b << ", ";
		b += a;
		a = b-a;
	}
	
}

int Rekurencyjna_Fibonacci(int liczba) {
	if (liczba < 3) {
		return 1;
	}
	else {
		return Rekurencyjna_Fibonacci(liczba-1) + Rekurencyjna_Fibonacci(liczba - 2);
	}
}

void Euklides(int a, int b) {
	int wieksza = a < b ? b : a;
	int mniejsza = a < b ? a : b;
	if ((wieksza % mniejsza == 0) || (wieksza == mniejsza)) {
		cout << mniejsza;
	}
	else {
		while (wieksza != mniejsza) {
			if (wieksza > mniejsza) {
				wieksza -= mniejsza;
			}
			else {
				mniejsza -= wieksza;
			}
			
		}
		cout << wieksza;

	}
}

int Euklides_Rekurencja(int a, int b) {
	if (a != b) {
		if (a > b) {
			return Euklides_Rekurencja(a - b, b);
		}
		else {
			return Euklides_Rekurencja(a, b - a);
		}
	}
	
}

void Najwiekszy_Najmniejszy(int tablica[]) {
	int najmniejszy = 99999;
	int najwiekszy = -99999;
	for (int i = 0; i < 9; i++) {
		if (tablica[i] < najmniejszy) najmniejszy = tablica[i];
		if (tablica[i] > najwiekszy) najwiekszy = tablica[i];
	}

	cout << "Najwiekszy " << najwiekszy << ", najmniejszy " << najmniejszy;
}


int main()
{

	//Anagramy("asddsa");
	//Dwojkowy(20);
	//Osemkowy(8);
	//Pierwsza(7);
	//Doskonala(12);
	//Rozklad_czynniki(1234);
	//Fibonacci(13);
	//cout << Rekurencyjna_Fibonacci(13);
	//Euklides(24, 2341);
	//cout << Euklides_Rekurencja(920, 920);
	//int tablica[] = { 5, 6, 2, 23, 1, 0, -3, -5, 0}; Najwiekszy_Najmniejszy(tablica);
	
}