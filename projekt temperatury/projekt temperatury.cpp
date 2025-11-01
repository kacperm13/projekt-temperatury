#include <iostream>
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

int main()
{
	int opcja;
	menu();
	cout << "Wybierz opcje: ";
	cin >> opcja;
	switch (opcja) {
	case 1: {
		float fahr = pobierzF(0);
		cout << fahr << "F = " << FtoC(fahr) << "C";
		break;
	}
	case 2: {
		float fahr = pobierzF(0);
		cout << fahr << "F = " << FtoK(fahr) << "K";
		break;
	}
	case 3: {
		float cel = pobierzC(0);
		cout << cel << "C = " << CtoF(cel) << "F";
		break;
	}
	case 4: {
		float cel = pobierzC(0);
		cout << cel << "C = " << CtoK(cel) << "K";
		break;
	}
	case 5: {
		float kel = pobierzK(0);
		cout << kel << "K = " << KtoF(kel) << "F";
		break;
	}
	case 6: {
		float kel = pobierzK(0);
		cout << kel << "K = " << KtoC(kel) << "C";
		break;
	}
	case 7:
		return 0;
	default:
		return 0;
	}
}
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
void menu() {
	cout << "1 - przelicz Fahr -> Celsius\n";
	cout << "2 - przelicz Fahr -> Kelwin\n";
	cout << "3 - przelicz Celsius -> Fahr\n";
	cout << "4 - przelicz Celsius -> Kelwin\n";
	cout << "5 - przelicz Kelwin -> Fahr\n";
	cout << "6 - przelicz Kelwin -> Celsius\n";
	cout << "7 - zakoncz dzialanie programu\n";
}
float pobierzF(float fahr) {
	cout << "Podaj temperature do przeliczenia (Fahr): ";
	cin >> fahr;
	check(fahr);
	return fahr;
}
float pobierzC(float cel) {
	cout << "Podaj temperature do przeliczenia (Celsius): ";
	cin >> cel;
	check(cel);
	return cel;
}
float pobierzK(float kel) {
	cout << "Podaj temperature do przeliczenia (Kelwin): ";
	cin >> kel;
	check(kel);
	return kel;
}
int check(float temp, char stopnie) {
	if (temp < 0 && stopnie = 'K') {

	}
}