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


int main()
{

	//Anagramy("asddsa");
	//Dwojkowy(20);
	Osemkowy(8);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
