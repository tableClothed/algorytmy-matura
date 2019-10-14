#include "pch.h"
// #include "matura_2017";
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

void Scal_Tablice(int tablica[], int lewy, int srodek, int prawy) {
	int i = lewy;
	int j = srodek + 1;

	int pomocna_tablica[7];

	for (int i = lewy; i <= prawy; i++) {
		pomocna_tablica[i] = tablica[i];
	}

	for (int k = lewy; k <= prawy; k++) {
		if (i <= srodek) {
			if (j <= prawy) {
				if (pomocna_tablica[j] < pomocna_tablica[i])
					tablica[k] = pomocna_tablica[j++];
				else
					tablica[k] = pomocna_tablica[i++];
			}
			else {
				tablica[k] = pomocna_tablica[i++];
			}
		}
		else {
			tablica[k] = pomocna_tablica[j++];
		}
	}

	Wyswietl_tablice(tablica, 7);
}


void Sortowanie_Skalanie(int tablica[], int lewy, int prawy) {


	//int tablica2[] = { 555, 55, -23, -10, 5, 0, -23 };

	//Wyswietl_tablice(tablica2, a);

	int srodek = (lewy + prawy) / 2;

	Sortowanie_Skalanie(tablica, lewy, srodek);
	Sortowanie_Skalanie(tablica, srodek+1, prawy);

	Scal_Tablice(tablica, lewy, srodek, prawy);
}

void Sort_Scal() {
	int a = 7;

	int tablica1[] = { 1, 44, 23, 100, -5, 0, 9 };

	Wyswietl_tablice(tablica1, a);

	Sortowanie_Skalanie(tablica1, 0, a - 1);
}

void Sortowanie_Szybkie(int tablica[], int lewy, int prawy) {

	int i = lewy - 1;
	int j = prawy + 1;

	int pivot = tablica[(lewy + prawy) / 2];

	while (true) {
		while (pivot > tablica[++i]) {
			while (pivot < tablica[--j])
			{
				if (i <= j)
					swap(tablica[i], tablica[j]);
				else
					break;
			}
		}

		if (j > lewy)
			Sortowanie_Szybkie(tablica, lewy, j);
		else
			Sortowanie_Szybkie(tablica, i, prawy);

	}

}

void Quick_Sort() {
	int a = 7;
	int tablica[] = { 1, 44, 23, 100, -5, 0, 9 };

	Sortowanie_Szybkie(tablica, 0, a - 1);
}

void Liczba_Progow() {
	int tablica[] = { 2, 2, 2, 3, 1, 1, 3, 3, 1, 10, 11, 7, 7, 6, 7, 7, 8, 9, 9, 7 };
	int n = 20;
	int i = 1;
	int liczba_prog = 0;


	while (i < n) {
		if (tablica[i - 1] >= tablica[i])
		{
			if (tablica[i - 1] != tablica[i]) {
				liczba_prog++;
				cout << tablica[i - 1] << " " << tablica[i] << endl;
			}

		}
		i++;
	}

	cout << liczba_prog;

}

void Najwieksza_Liczba_Progow() {
	//int tablica[] = { 2, 2, 2, 3, 1, 1, 3, 3, 1, 10, 11, 7, 7, 6, 7, 7, 8, 9, 9, 7 };
	int tablica[] = { 20, 19, 18, 17, 16, 15, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int n = 20;
	int i = 1;
	int liczba_prog = 0;
	int najw_liczb = 0;


	while (i <= n) {
		if ((tablica[i - 1] >= tablica[i]) && (i != n))
		{
			if (tablica[i - 1] != tablica[i]) {
				liczba_prog++;
				//cout << tablica[i - 1] << " " << tablica[i] << endl;
			}

		} else {
			if (liczba_prog > najw_liczb) {
				najw_liczb = liczba_prog;
			}
			liczba_prog = 0;

		}
		i++;
	}

	cout << najw_liczb;

}

void Skojarzone() {
	int a, suma1 = 0, suma2 = 0, liczba_skojarzona;
	cout << "Podaj x ";
	cin >> a;

	for (int i = 1; i <= a / 2; i++) {
		if (a % i == 0) {
			suma1 += i;
		}
	}

	liczba_skojarzona = suma1 - 1;

	for (int j = 1; j <= liczba_skojarzona / 2; j++) {
		if (liczba_skojarzona % j == 0) {
			suma2 += j;
		}
	}

	if (suma2 - 1 == a) {
		cout << endl << "Liczba jest skojarzona";
	}
	else {
		cout << endl << "NIE";
	}
}




//int main()
//{

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
	//Sort_Scal();
	//Quick_Sort();
	//Liczba_Progow();
	//Najwieksza_Liczba_Progow();
	//Skojarzone();
//}