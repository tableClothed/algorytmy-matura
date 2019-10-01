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

void Najwiekszy_Najmniejszy() {
	int tablica[] = { 5, 6, 2, 23, 1, 0, -3, -5, 0 };
	int najmniejszy = 99999;
	int najwiekszy = -99999;
	for (int i = 0; i < 9; i++) {
		if (tablica[i] < najmniejszy) najmniejszy = tablica[i];
		if (tablica[i] > najwiekszy) najwiekszy = tablica[i];
	}

	cout << "Najwiekszy " << najwiekszy << ", najmniejszy " << najmniejszy;
}

void Wyswietl_tablice(int tablica[], int wielkosc) {
	for (int i = 0; i < wielkosc; i++) {
		cout << i << " " << tablica[i] << endl;
	}
}

void Sortowanie_Babelkowe() {
	int tablica[] = { 1, 44, 23, 100, 0, -5, 9 };

	Wyswietl_tablice(tablica, 7);

	int a = 7;

	while (a > 0) {
		for (int i = 1; i < 7; i++) {
			if (tablica[i - 1] > tablica[i]) {
				int temp = tablica[i];
				tablica[i] = tablica[i - 1];
				tablica[i - 1] = temp;
			}
		}
		a--;
	}

	Wyswietl_tablice(tablica, 7);

}

void Sortowanie_przez_selekcje() {
	int tablica[] = { 1, 44, 23, 100, 0, -5, 9 };
	int a = 7;

	Wyswietl_tablice(tablica, a);

	int index = 0;
	
	for (int i = 0; i < a; i++) {
		index = i;
		for (int j = i + 1; j < a; j++) {
			if (tablica[j] < tablica[index]) {
				index = j;
			}

		}
		//Wyswietl_tablice(tablica, a);

		swap(tablica[i], tablica[index]);

	}

	Wyswietl_tablice(tablica, a);

}

void Sortowanie_Wstawianie() {
	int tablica[] = { 1, 44, 23, 100, 0, -5, 9 };
	int a = 7;

	Wyswietl_tablice(tablica, a);

	int pozycja_poczatkowa = 1;
	int i = pozycja_poczatkowa;

	int liczba, index;

	for (int i = 0; i < a; i++) {
		liczba = tablica[i];
		index = i - 1;

		while (index >= 0 && tablica[index] > liczba) {
			tablica[index + 1] = tablica[index];
			index--;
		}
		tablica[index + 1] = liczba;
	}

	Wyswietl_tablice(tablica, a);
}

void Min_Max_Optymalne() {
	int tablica[] = { 1, 44, 23, 100, -5, 0, 9 };
	int a = 7;

	Wyswietl_tablice(tablica, a);

	int MIN, MAX;

	MIN = tablica[0] > tablica[1] ? tablica[1] : tablica[0];
	MAX = tablica[0] > tablica[1] ? tablica[0] : tablica[1];

	int x = 2;

	while (x + 2 <= a) {
		if (tablica[x] > tablica[x - 1]) {
			MAX = tablica[x] > MAX ? tablica[x] : MAX;
			MIN = tablica[x-1] < MIN ? tablica[x-1] : MIN;
		}
		else {
			MAX = tablica[x - 1] > MAX ? tablica[x-1] : MAX;
			MIN = tablica[x] < MIN ? tablica[x] : MIN;
		}
		x += 2;
	}

	if (a % 2 != 0) {
		MAX = tablica[a - 1] > MAX ? tablica[a - 1] : MAX;
		MIN = tablica[a - 1] < MIN ? tablica[a - 1] : MIN;
	}

	cout << "MIN " << MIN << " MAX " << MAX;
}

void Sortowanie_Skalanie() {
	int tablica1[] = { 1, 44, 23, 100, -5, 0, 9 };
	int a1 = 7;

	Wyswietl_tablice(tablica1, a1);

	int tablica2[] = { 555, 55, -23, -10, 5, 0, -23 };
	int a2 = 7;

	Wyswietl_tablice(tablica2, a2);
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
	//Najwiekszy_Najmniejszy();
	//Sortowanie_Babelkowe();
	//Sortowanie_przez_selekcje();
	//Sortowanie_Wstawianie();
	//Min_Max_Optymalne();
	Sortowanie_Skalanie();
}