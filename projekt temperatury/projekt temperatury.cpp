#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "headerFile.h"
using namespace std;
int main()
{
	while (1) {
		system("cls");

		int opcja;
		srand(time(NULL));
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
				cout << fahr << "F = " << FtoK(fahr) << "K\n";
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
			historiaUsun();
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 9: {
			historiaMod();
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case 10: {
			historiaLos();
			cout << "Wcisnij Enter, aby kontynuowac.\n";
			cin.ignore();
			cin.get();
			break;
		}
		case -1: {
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
	cout << "8 - usun historie\n";
	cout << "9 - modyfikacja wpisu z historii\n";
	cout << "10 - losowe wypelnianie historii\n";
	cout << "-1 - zakoncz dzialanie programu\n";
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
		cout << "Tablica jest juz pelna. Wynik nie zostanie dodany do historii przeliczen.\n";
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
	else {
		historiaMenu();
	}
}
void historiaMenu() {
	system("cls");
	int opcja;
	int licznik = 0;
	cout << "Wybierz opcje: \n";
	cout << "1. Tylko C -> inne\n";
	cout << "2. Tylko F -> inne\n";
	cout << "3. Tylko K -> inne\n";
	cout << "4. Cala historia\n";
	cin >> opcja;
	switch (opcja) {
	case 1:	//Celsjusz
	{
		cout << "Historia:\n";
		for (int i = 0; i < dataCounter; i += 2) {
			if (tablicaZnakow[i] == 'C') {
				cout << "<" << i / 2 + 1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
				licznik++;
			}
		}
		if (licznik == 0) {
			cout << "Historia jest pusta.\n";
		}
		break;
	}
	case 2:	//Fahr
	{
		cout << "Historia:\n";
		for (int i = 0; i < dataCounter; i += 2) {
			if (tablicaZnakow[i] == 'F') {
				cout << "<" << i / 2 + 1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
				licznik++;
			}
		}
		if (licznik == 0) {
			cout << "Historia jest pusta.\n";
		}
		break;
	}
	case 3:	//Kelwin
	{
		cout << "Historia:\n";
		for (int i = 0; i < dataCounter; i += 2) {
			if (tablicaZnakow[i] == 'K') {
				cout << "<" << i / 2 + 1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
				licznik++;
			}
		}
		if (licznik == 0) {
			cout << "Historia jest pusta.\n";
		}
		break;
	}
	case 4: //cala
	{
		cout << "Historia: \n";
		for (int i = 0; i < dataCounter; i += 2) {
			cout << "<" << i / 2 + 1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
		}
		break;
	}
	}

}
void historiaUsun() {
	system("cls");						//pokazanie historii
	if (dataCounter == 0) {
		cout << "Historia jest pusta.\n";
		return;
	}
	else {
		cout << "Historia: \n";
		for (int i = 0; i < dataCounter; i += 2) {
			cout << "<" << i / 2 + 1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
		}
	}

	int entityToRemove;		//wybor pozycji
	cout << "Wybierz pozycje, ktora zostanie usunieta.\n";
	cin >> entityToRemove;

	if (entityToRemove <1 || entityToRemove >dataCounter / 2) {	//warunek ze jak eTR jest mniesze od 1 albo wiekze niz ilosc wpisow ktore mamy to stop
		cout << "Nieprawidlowa pozycja. \n";
		return;
	}
	int start = (entityToRemove - 1) * 2; // indeks tego co bedzie usuwane
	for (int i = start + 2; i < dataCounter; i++) {
		tablicaLiczb[i - 2] = tablicaLiczb[i];
		tablicaZnakow[i - 2] = tablicaZnakow[i];
	}

	dataCounter -= 2;
	cout << "Usunieto wpis.\n";
}

void historiaMod() {
	system("cls");
	if (dataCounter == 0) {		//pokazanie historii
		cout << "Historia jest pusta.\n";
		return;
	}
	else {
		cout << "Historia: \n";
		for (int i = 0; i < dataCounter; i += 2) {
			cout << "<" << i / 2 + 1 << "> " << tablicaLiczb[i] << tablicaZnakow[i] << " = " << tablicaLiczb[i + 1] << tablicaZnakow[i + 1] << endl;
		}
	}

	int entityToModify;		//wybor pozycji
	cout << "Wybierz pozycje, ktora zostanie zmodyfikowana.";
	cin >> entityToModify;

	if (entityToModify <1 || entityToModify >dataCounter / 2) {	//warunek ze jak eTM jest mniesze od 1 albo wiekze niz ilosc wpisow ktore mamy to stop
		cout << "Nieprawidlowa pozycja. \n";
		return;
	}

	int zmiana = (entityToModify - 1) * 2; // indeks tego co bedzie zmienione

	float temp1;
	char skala1;
	char skala2;
	cout << "Podaj nowa temperature do przeliczenia. \n";
	cin >> temp1;
	cout << "Podaj skale, w ktorej jest nowa temperatura. \n";
	cin >> skala1;
	cout << "Podaj nowa skale, na ktora ma byc przeliczona ta temperatura.\n";
	cin >> skala2;
	if (check(temp1, skala1) == -999.0) {
		cout << "Nie ma takiej temperatury.\n";
	}
	else {
	}

	float temp2;
	if (skala1 == 'C' && skala2 == 'F') temp2 = CtoF(temp1);
	else if (skala1 == 'C' && skala2 == 'K') temp2 = CtoK(temp1);
	else if (skala1 == 'K' && skala2 == 'F') temp2 = KtoF(temp1);
	else if (skala1 == 'K' && skala2 == 'C') temp2 = KtoC(temp1);
	else if (skala1 == 'F' && skala2 == 'K') temp2 = FtoK(temp1);
	else if (skala1 == 'F' && skala2 == 'C') temp2 = FtoC(temp1);

	tablicaLiczb[entityToModify] = temp1;
	tablicaZnakow[entityToModify] = skala1;
	tablicaLiczb[entityToModify + 1] = temp2;
	tablicaZnakow[entityToModify + 1] = skala2;

	cout << "Wpis zostal zmodyfikowany.\n";
}

void historiaLos() {
	int iloscLos;
	cout << "Podaj ilosc losowych wartosci do przeliczenia: \n";
	cin >> iloscLos;
	char opcja;
	if (dataCounter + iloscLos * 2 >= 100) {
		cout << "Zbyt malo miejsca w tablicy na wygenerowanie " << iloscLos << " wartosci.\nCzy chcesz przeliczyc tyle wartosci, ile pozostalo miejsca w tabeli?\n(T/N)\n";
		cin >> opcja;
		if (opcja != 't' && opcja != 'T') {
			return;
		}
		iloscLos = (100 - dataCounter) / 2;
	}

		char skala1;
		char skala2;
		float temp1;
		float temp2;
		int los1;	//pierwsza skala
		int los2;	//poczatkowa temperatura
		int los3;	//druga skala
		for (int i = 0; i < iloscLos; i++) {
			los1 = rand() % 3;

			if (los1 == 0) skala1 = 'C';		//losowanie 1 skali
			else if (los1 == 1) skala1 = 'F';
			else if (los1 == 2) skala1 = 'K';

			if (skala1 == 'C') {				//losowanie temperatury
				los2 = rand() % (727 + 273 + 1) - 273;
			}
			else if (skala1 == 'F') {
				los2 = rand() % (541 + 459 + 1) - 459;
			}
			else if (skala1 == 'K') {
				los2 = rand() % 1001;
			}

			temp1 = (double)los2;

			do {
				los3 = rand() % 3;
				if (los3 == 0) skala2 = 'C';		//losowanie 2 skali
				else if (los3 == 1) skala2 = 'F';
				else if (los3 == 2) skala2 = 'K';
			} while (skala1 == skala2);

			if (skala1 == 'C' && skala2 == 'F') temp2 = CtoF(temp1);
			else if (skala1 == 'C' && skala2 == 'K') temp2 = CtoK(temp1);
			else if (skala1 == 'K' && skala2 == 'F') temp2 = KtoF(temp1);
			else if (skala1 == 'K' && skala2 == 'C') temp2 = KtoC(temp1);
			else if (skala1 == 'F' && skala2 == 'K') temp2 = FtoK(temp1);
			else if (skala1 == 'F' && skala2 == 'C') temp2 = FtoC(temp1);

			historiaLiczb(temp1, temp2, skala1, skala2);
		}
		cout << "Losowe wpisy zostaly wygeneroiwane.\n";
}