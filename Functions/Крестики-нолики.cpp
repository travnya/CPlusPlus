#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

int firstMove, gridSize;

void menu();
void rules();
void settings();
void clear();

int main() 
{
	setlocale(0, "");
	menu();
	system("pause");
}

void menu()
{
	system("color a");
	cout << "\t\t\t\tПрограмма \"Крестики-нолики\" by VlaDICK :з and SaNYA:3 \n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "[*] Вы находитесь в меню\n";
	cout << "[*] Пожалуйста, выберите действие:\n\n";
	cout << "[1] Играть\n";
	cout << "[2] Настройки\n";
	cout << "[3] Правила\n";
	cout << "[4] Выход\n\n";
	cout << "[*]Введите номер действия: ";
	int choose;
	cin >> choose;
	
	switch (choose)
	{
	case 1:
		clear();
		break;
	case 2:
		clear();
		settings();
	case 3:
		clear();
		rules();
	case 4:
		exit(1337);
	default:
		cout << "Такие действия не делай\n\n";
		clear();
		menu();
	}
}

void rules() 
{
	clear();
	cout << "Добро пожаловать в жестокий мир топ-2 самой мужской игры по версии журнала \"Hoerbs\" (топ-1 это камень ножницы бумага)\n";
	cout << "Правила игры максимально брутальны. Как настоящему мужику, тебе нужно занимать клетки на игровом поле так,\nчтобы получился полный ряд от края до края по горизонтали, вертикали или диагонали\n";
	cout << "При этом нужно, используя последние три извилины своего мозга, помешать своему противнику сделать победный ряд.\n";
	cout << "Удачи на полях сражения в топ-2 самой брутальной игре в мире КРЕСТИКИ \"НОЛИКИ\"\n";
	system("pause");
	clear();
	menu();
}

void settings()
{
	clear();
	int choose;
	cout << "[1] Выбрать цвет\n";
	cout << "[2] Выбрать первый ход\n";
	cout << "[3] Выбрать размер сетки\n";
	cout << "[4] Вернуться обратно в меню\n";
	cout << "[*] Ваш выбор: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		clear();
		break;
	case 2:
		clear();
		cout << "[*] Кто первый ходит?\n";
		cout << "[1] Нолик\n";
		cout << "[2] Крестик\n";
		cout << "Кто первый ходит?\n";
		cin >> firstMove;
		clear();
		settings();
		break;
	case 3:
		clear();
		cout << "Выберите размер сетки\n";
		cout << "[1] 3x3\n";
		cout << "[2] 4x4\n";
		cout << "[3] 5x5\n";
		cout << "[*] Ваш выбор: ";
		cin >> gridSize;
		system("pause");
		clear();
		settings();
	case 4:
		clear();
		menu();
	default:
		cout << "Такие действия не делай";
		clear();
		settings();
	}
}

void clear()
{
	system("cls");
}
