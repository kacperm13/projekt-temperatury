#include <iostream>
#include <stdlib.h>
#include "headerFile.h"
using namespace std;
int main()
{
	while (1) {
		system("cls");

		int opcja;
		int a;
		menu();
		cout << "Wybierz opcje: \n";
		cin >> opcja;
		switch (opcja) {
		case 1: {
			float fahr = pobierzF(0);
			fahr = check(fahr, 'F');
			if (fahr == -999.0) {
				cout << "Nie ma takiej temperatury.\n";
			}
			else {
				cout << fahr << "F = " << FtoC(fahr) << "C\n";
				historiaLiczb(fahr, FtoC(fahr), 'F', 'C');
			}
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 2: {
			float fahr = pobierzF(0);
			fahr = check(fahr, 'F');
			if (fahr == -999.0) {
				cout << "Nie ma takiej temperatury.\n";
			}
			else {
				cout << fahr << "F = " << FtoK(fahr) << "K";
				historiaLiczb(fahr, FtoK(fahr), 'F', 'K');
			}
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 3: {
			float cel = pobierzC(0);
			cel = check(cel, 'C');
			if (cel == -999.0) {
				cout << "Nie ma takiej temperatury.\n";
			}
			else {
				cout << cel << "C = " << CtoF(cel) << "F\n";
				historiaLiczb(cel, CtoF(cel), 'C', 'F');
			}
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 4: {
			float cel = pobierzC(0);
			cel = check(cel, 'C');
			if (cel == -999.0) {
				cout << "Nie ma takiej temperatury.\n";
			}
			else {
				cout << cel << "C = " << CtoK(cel) << "K\n";
				historiaLiczb(cel, CtoK(cel), 'C', 'K');
			}
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 5: {
			float kel = pobierzK(0);
			kel = check(kel, 'K');
			if (kel == -999.0) {
				cout << "Nie ma takiej temperatury.\n";
			}
			else {
				cout << kel << "K = " << KtoF(kel) << "F\n";
				historiaLiczb(kel, KtoF(kel), 'K', 'F');
			}
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 6: {
			float kel = pobierzK(0);
			kel = check(kel, 'K');
			if (kel == -999.0) {
				cout << "Nie ma takiej temperatury.\n";
			}
			else {
				cout << kel << "K = " << KtoC(kel) << "C\n";
				historiaLiczb(kel, KtoC(kel), 'K', 'C');
			}
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 7: {
				historiaWyswietl();
				cout << "Wcisnij Enter, aby kontynuowac.\n";
				cin.ignore();
				cin.get();
				break;
		}
		case 8: {
			return 0;
		}
		default: {
			cout << "Bledna wartosc. Wcisnij Enter, aby opuscic kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		}
	}
}
//przeliczanie
float FtoC(float fahr) {
	float wynik = (5.0 / 9.0) * (fahr - 32);
	return wynik;
}
float FtoK(float fahr) {
	float wynik = (5.0 / 9.0) * (fahr + 459.67);
	return wynik;
}
float CtoF(float cel) {
	float wynik = (cel * 9.0 / 5.0) + 32.0;
	return wynik;
}
float CtoK(float cel) {
	float wynik = cel + 273.15;
	return wynik;
}
float KtoC(float kel) {
	float wynik = kel - 273.15;
	return wynik;
}
float KtoF(float kel) {
	float wynik = (kel * 9.0 / 5.0) - 459.67;
	return wynik;
}
//menu
void menu() {
	cout << "1 - przelicz Fahr -> Celsius\n";
	cout << "2 - przelicz Fahr -> Kelwin\n";
	cout << "3 - przelicz Celsius -> Fahr\n";
	cout << "4 - przelicz Celsius -> Kelwin\n";
	cout << "5 - przelicz Kelwin -> Fahr\n";
	cout << "6 - przelicz Kelwin -> Celsius\n";
	cout << "7 - pokaz historie\n";
	cout << "8 - zakoncz dzialanie programu\n";
}
//pobieranie temperatury od uzytkownika
float pobierzF(float fahr) {
	cout << "Podaj temperature do przeliczenia (Fahr): \n";
	cin >> fahr;
	return fahr;
}
float pobierzC(float cel) {
	cout << "Podaj temperature do przeliczenia (Celsius): \n";
	cin >> cel;
	return cel;
}
float pobierzK(float kel) {
	cout << "Podaj temperature do przeliczenia (Kelwin): \n";
	cin >> kel;
	return kel;
}
//sprawdzenie czy podana temperatura jest mozliwa
float check(float temp, char stopnie) {		
	if (temp < 0 && stopnie == 'K') {
		return -999.0;
	}
	if (temp < -459.67 && stopnie == 'F') {
		return -999.0;
	}
	if (temp < -273.15 && stopnie == 'C') {
		return -999.0;
	}
	return temp;
}
bool historiaLiczb(float temp1, float temp2, char znak1, char znak2) {
	if (dataCounter + 1 >= 100) {
		cout << "Tablica jest juz pelna.\n";
		return false;
	}
	tablicaLiczb[dataCounter] = temp1;
	tablicaLiczb[dataCounter + 1] = temp2;
	tablicaZnakow[dataCounter] = znak1;
	tablicaZnakow[dataCounter + 1] = znak2;
	dataCounter += 2;
	return true;

}
void historiaWyswietl() {
	if (dataCounter == 0) {
		cout << "Historia jest pusta.\n";
		return;
	}
	cout << "Historia:\n";
	for (int i = 0; i < dataCounter; i+=2) {
		cout << "<" << i/2+1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
	}
}