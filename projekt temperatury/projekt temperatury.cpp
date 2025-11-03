#include <iostream>
#include <stdlib.h>
using namespace std;
float FtoC(float fahr);
float FtoK(float fahr);
float CtoF(float cel);
float CtoK(float cel);
float KtoC(float kel);
float KtoF(float kel);
void menu();
float pobierzF(float fahr);
float pobierzC(float cel);
float pobierzK(float kel);
float check(float temp, char stopnie);

int main()
{
	while (1) {
		system("cls");
		int opcja;
		int a;
		menu();
		cout << "Wybierz opcje: ";
		cin >> opcja;
		switch (opcja) {
		case 1: {
			float fahr = pobierzF(0);
			fahr = check(fahr, 'F');
			if (fahr == -999.0) {
				cout << "Nie ma takiej temperatury.";
			}
			else {
				cout << fahr << "F = " << FtoC(fahr) << "C\n";
				cout << "Wpisz 1, aby kontynuowac.";					//tutaj nie wiedzialem jak zrobic to z wcisnieciem enter, wiec jest takie cos
				cin >> a;
				while (a != 1) {
					cout << "Bledna wartosc. Wpisz 1 ponownie.";
					cin >> a;
				}
			}
			break;
		}
		case 2: {
			float fahr = pobierzF(0);
			fahr = check(fahr, 'F');
			if (fahr == -999.0) {
				cout << "Nie ma takiej temperatury.";
			}
			else {
				cout << fahr << "F = " << FtoK(fahr) << "K";
				cout << "Wpisz 1, aby kontynuowac.";
				while (a != 1) {
					cout << "Bledna wartosc. Wpisz 1 ponownie.";
					cin >> a;
				}
			}
			break;
		}
		case 3: {
			float cel = pobierzC(0);
			cel = check(cel, 'C');
			if (cel == -999.0) {
				cout << "Nie ma takiej temperatury.";
			}
			else {
				cout << cel << "C = " << CtoF(cel) << "F";
				cout << "Wpisz 1, aby kontynuowac.";
				while (a != 1) {
					cout << "Bledna wartosc. Wpisz 1 ponownie.";
					cin >> a;
				}
			}
			break;
		}
		case 4: {
			float cel = pobierzC(0);
			cel = check(cel, 'C');
			if (cel == -999.0) {
				cout << "Nie ma takiej temperatury.";
			}
			else {
				cout << cel << "C = " << CtoK(cel) << "K";
				cout << "Wpisz 1, aby kontynuowac.";
				while (a != 1) {
					cout << "Bledna wartosc. Wpisz 1 ponownie.";
					cin >> a;
				}
			}
			break;
		}
		case 5: {
			float kel = pobierzK(0);
			kel = check(kel, 'K');
			if (kel == -999.0) {
				cout << "Nie ma takiej temperatury.";
			}
			else {
				cout << kel << "K = " << KtoF(kel) << "F";
				cout << "Wpisz 1, aby kontynuowac.";
				while (a != 1) {
					cout << "Bledna wartosc. Wpisz 1 ponownie.";
					cin >> a;
				}
			}
			break;
		}
		case 6: {
			float kel = pobierzK(0);
			kel = check(kel, 'K');
			if (kel == -999.0) {
				cout << "Nie ma takiej temperatury.";
			}
			else {
				cout << kel << "K = " << KtoC(kel) << "C";
				cout << "Wpisz 1, aby kontynuowac.";
				while (a != 1) {
					cout << "Bledna wartosc. Wpisz 1 ponownie.";
					cin >> a;
				}
			}
			break;
		}
		case 7:
			return 0;
		default:
			return 0;
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
	cout << "7 - zakoncz dzialanie programu\n";
}
//pobieranie temperatury od uzytkownika
float pobierzF(float fahr) {
	cout << "Podaj temperature do przeliczenia (Fahr): ";
	cin >> fahr;
	return fahr;
}
float pobierzC(float cel) {
	cout << "Podaj temperature do przeliczenia (Celsius): ";
	cin >> cel;
	return cel;
}
float pobierzK(float kel) {
	cout << "Podaj temperature do przeliczenia (Kelwin): ";
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