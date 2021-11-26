#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "ru");
	cout << "[-] Какое время года:" << endl << endl;
	cout << "[1] Лето" << endl;
	cout << "[2] Осень" << endl;
	cout << "[3] Зима" << endl;
	cout << "[4] Весна" << endl;
	cout << "[-] Введите значение:" << endl;
	short season;
		cin >> season;
	if (season == 1) {
		cout << "Сейчас лето, следует одеться в шорты, футболку и взять с собой кепку с солнцезащитными очками";
	}
	else if (season == 2) {
		cout << "Сейчас jctym, следует одеться в кофту, джинсы и взять с собой зонт";
	}
	else if (season == 3) {
		cout << "Сейчас зима, следует одеться в теплую курту, штаны и не забыть про шапку";
	}
	else if (season == 4) {
		cout << "Сейчас весна, следует одеться в легкую одежду, да бы не перегреться";
	}
	else {
		cout << "ОШИБКА";
	}
}