// Подключение библиотек
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

// Переменные и поле
int firstMove = 1, xColor, oColor, gameRuleChoose, turn, setNum, counter = 0;
short gridSize = 1;
bool gameRun = true;
char gameField[5][5] = { {'-','-','-','-','-'}, {'-','-','-','-','-'}, {'-','-','-','-','-'}, {'-','-','-','-','-'}, {'-','-','-','-','-'} };

// Вызов функции (Защита от багов)
void rules();
void settings();
void clear();
void playerColor();
void startGame();
bool winConditions();
int fieldSize();

// Страница главного меню
void menu()
{
	system("color a");

	cout << "\t\t\t\tИгра \"Крестики-нолики\" от Владоса и Сашки\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "[*] Главное меню\n";
	cout << "[*] Пожалуйста, выберите действие:\n\n";
	cout << "[1] Играть\n";
	cout << "[2] Настройки\n";
	cout << "[3] Правила\n";
	cout << "[4] Выход\n\n";
	cout << "[*] Введите номер действия: ";

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		clear();
		startGame();
		break;
	case 2:
		clear();
		settings();
		break;
	case 3:
		clear();
		rules();
		break;
	case 4:
		exit(1337);
		break;
	default:
		cout << "Выберите, пожалуйста, из доступных вариантов.\n";
		clear();
		menu();
	}

}


// Функция генерации случайных чисел
int randomNumber(int min, int max)
{
	srand(time(NULL));
	int num = min + rand() % (max - min + 1);
	return num;
}

// Страница правил
void rules()
{
	clear();
	cout << "\t\t\t\t\t\t    Правила игры \n\n";
	cout << "Суть игры \"Крестики нолики\" заключается в том,\nчтобы составить ряд из крестиков или ноликов в зависимости от того, за кого вы играете.\nПри это надо это сделать быстрее, чем противник.\n\n";
	cout << "Для возвращения в главное меню нажмите любую кнопку.\n\n";
	system("pause");
	cout << endl;
	clear();
	menu();
}

// Страница настроек
void settings()
{
	cout << "Настройки\n\n";

	cout << "[1] Выбрать цвет\n";
	cout << "[2] Выбрать первый ход\n";
	cout << "[3] Выбрать размер сетки\n";
	cout << "[4] Вернуться обратно в меню\n";
	cout << "[*] Ваш выбор: ";
	int choose; cin >> choose;

	switch (choose)
	{
	case 1:
		clear();
		playerColor();
		clear();
		settings();
		break;
	case 2:
		clear();
		cout << "[*] Кто первый ходит?\n";
		cout << "[1] Крестик\n";
		cout << "[2] Нолик\n";
		cout << "Выберите первый ход: \n";
		cin >> firstMove;
		if (firstMove < 1 || firstMove > 2)
		{
			cout << "Выберите, пожалуйста, из доступных вариантов.\n";
			system("pause");
			clear();
			settings();
		}
		clear();
		settings();
		break;
	case 3:
		clear();
		fieldSize();
		system("pause");
		clear();
		settings();
		break;
	case 4:
		clear();
		menu();
		break;
	default:
		cout << "Выберите, пожалуйста, из доступных вариантов.\n";
		system("pause");
		clear();
		settings();
	}
}

// Функция очистки консоли
void clear()
{
	system("cls");
}

// Функция выбора цвета
void playerColor() {
	cout << "Выберите цвет для X и O\n\n";
	cout << "[1] Красный\n";
	cout << "[2] Зеленый\n";
	cout << "[3] Желтый\n";
	cout << "[4] Синий\n";
	cout << "[5] Пурпурный\n";
	cout << "[6] Гейский\n";
	cout << "[7] Дефолтный\n";
	cout << "Выберите цвет для X: ";
	cin >> xColor;

	while (xColor < 1 || xColor > 7)
	{
		cout << "\n Ошибка! Такого цвета не существует! Введите код заного: ";
		cin >> xColor;
		cout << "\n";
	}
	cout << "Выберите цвет для 0: ";
	cin >> oColor;

	while (oColor < 1 || oColor > 7)
	{
		cout << "\n Ошибка! Такого цвета не существует! Введите код заного: ";
		cin >> oColor;
		cout << "\n";
	}
}

// Функция отображения поля в настройках
void drawGrid(short gridSize)
{
	setNum = 1;
	for (int i = 0; i < gridSize + 2; i++)
	{
		for (int j = 0; j < gridSize + 2; j++)
		{
			cout << setNum << " ";
			setNum += 1;
		}
		cout << endl;
	}
}

// Функция выбора размера поля
int fieldSize()
{
	cout << "Выберите размер сетки\n";
	cout << "[1] 3x3\n";
	cout << "[2] 4x4\n";
	cout << "[3] 5x5\n";
	cout << "[*] Ваш выбор: ";
	cin >> gridSize;

	switch (gridSize)
	{

	case 1:
		drawGrid(gridSize);
		break;
	case 2:
		drawGrid(gridSize);
		break;
	case 3:
		drawGrid(gridSize);
		break;
	default:
		cout << "Ошибка. Такого размера не существует.\n\n\n";
	}
	return gridSize;
}

// Функция отображения поля
void drawMassive(short gridSize)
{
	cout << "     Начало игры:\n\n";

	for (int i = 0; i < gridSize + 2; i++)
	{
		cout << "\t";
		for (int j = 0; j < gridSize + 2; j++)
		{
			cout << gameField[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Функция игры
void play()
{

	while (gameRun == true)
	{
		if (gameRuleChoose == 1)
		{
			int number;
			// Условия установки знака на поле 3x3
			if (gridSize == 1)
			{
				if (firstMove == 1)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"X\"? ";
					cin >> turn;
				}
			}

		}
		else if (gameRuleChoose == 2)
		{
			// Условия установки знака на поле 3x3
			if (gridSize == 1)
			{
				if (firstMove == 1)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"X\"? ";
					cin >> turn;

					if (turn == 1 && gameField[0][0] == '-')
					{
						gameField[0][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 2 && gameField[0][1] == '-')
					{
						gameField[0][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 3 && gameField[0][2] == '-')
					{
						gameField[0][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 4 && gameField[1][0] == '-')
					{
						gameField[1][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 5 && gameField[1][1] == '-')
					{
						gameField[1][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 6 && gameField[1][2] == '-')
					{
						gameField[1][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 7 && gameField[2][0] == '-')
					{
						gameField[2][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 8 && gameField[2][1] == '-')
					{
						gameField[2][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 9 && gameField[2][2] == '-')
					{
						gameField[2][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
				}
				else if (firstMove == 2)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"O\"? ";
					cin >> turn;

					if (turn == 1 && gameField[0][0] == '-')
					{
						gameField[0][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 2 && gameField[0][1] == '-')
					{
						gameField[0][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 3 && gameField[0][2] == '-')
					{
						gameField[0][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 4 && gameField[1][0] == '-')
					{
						gameField[1][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 5 && gameField[1][1] == '-')
					{
						gameField[1][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 6 && gameField[1][2] == '-')
					{
						gameField[1][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 7 && gameField[2][0] == '-')
					{
						gameField[2][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 8 && gameField[2][1] == '-')
					{
						gameField[2][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 9 && gameField[2][2] == '-')
					{
						gameField[2][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
				}
			}
			// Условия установки знака на поле 4x4
			else if (gridSize == 2)
			{
				if (firstMove == 1)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"X\"? ";
					cin >> turn;

					if (turn == 1 && gameField[0][0] == '-')
					{
						gameField[0][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 2 && gameField[0][1] == '-')
					{
						gameField[0][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 3 && gameField[0][2] == '-')
					{
						gameField[0][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 4 && gameField[0][3] == '-')
					{
						gameField[0][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 5 && gameField[1][0] == '-')
					{
						gameField[1][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 6 && gameField[1][1] == '-')
					{
						gameField[1][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 7 && gameField[1][2] == '-')
					{
						gameField[1][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 8 && gameField[1][3] == '-')
					{
						gameField[1][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 9 && gameField[2][0] == '-')
					{
						gameField[2][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 10 && gameField[2][1] == '-')
					{
						gameField[2][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 11 && gameField[2][2] == '-')
					{
						gameField[2][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 12 && gameField[2][3] == '-')
					{
						gameField[2][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 13 && gameField[3][0] == '-')
					{
						gameField[3][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 14 && gameField[3][1] == '-')
					{
						gameField[3][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 15 && gameField[3][2] == '-')
					{
						gameField[3][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 16 && gameField[3][3] == '-')
					{
						gameField[3][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
				}
				else if (firstMove == 2)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"O\"? ";
					cin >> turn;

					if (turn == 1 && gameField[0][0] == '-')
					{
						gameField[0][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 2 && gameField[0][1] == '-')
					{
						gameField[0][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 3 && gameField[0][2] == '-')
					{
						gameField[0][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 4 && gameField[0][3] == '-')
					{
						gameField[0][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 5 && gameField[1][0] == '-')
					{
						gameField[1][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 6 && gameField[1][1] == '-')
					{
						gameField[1][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 7 && gameField[1][2] == '-')
					{
						gameField[1][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 8 && gameField[1][3] == '-')
					{
						gameField[1][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 9 && gameField[2][0] == '-')
					{
						gameField[2][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 10 && gameField[2][1] == '-')
					{
						gameField[2][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 11 && gameField[2][2] == '-')
					{
						gameField[2][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 12 && gameField[2][3] == '-')
					{
						gameField[2][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 13 && gameField[3][0] == '-')
					{
						gameField[3][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 14 && gameField[3][1] == '-')
					{
						gameField[3][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 15 && gameField[3][2] == '-')
					{
						gameField[3][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 16 && gameField[3][3] == '-')
					{
						gameField[3][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
				}
			}
			// Условия установки знака на поле 5x5
			else if (gridSize == 3)
			{
				if (firstMove == 1)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"X\"? ";
					cin >> turn;

					if (turn == 1 && gameField[0][0] == '-')
					{
						gameField[0][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 2 && gameField[0][1] == '-')
					{
						gameField[0][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 3 && gameField[0][2] == '-')
					{
						gameField[0][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 4 && gameField[0][3] == '-')
					{
						gameField[0][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 5 && gameField[0][4] == '-')
					{
						gameField[0][4] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 6 && gameField[1][0] == '-')
					{
						gameField[1][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 7 && gameField[1][1] == '-')
					{
						gameField[1][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 8 && gameField[1][2] == '-')
					{
						gameField[1][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 9 && gameField[1][3] == '-')
					{
						gameField[1][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 10 && gameField[1][4] == '-')
					{
						gameField[1][4] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 11 && gameField[2][0] == '-')
					{
						gameField[2][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 12 && gameField[2][1] == '-')
					{
						gameField[2][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 13 && gameField[2][2] == '-')
					{
						gameField[2][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 14 && gameField[2][3] == '-')
					{
						gameField[2][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 15 && gameField[2][4] == '-')
					{
						gameField[2][4] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 16 && gameField[3][0] == '-')
					{
						gameField[3][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 17 && gameField[3][1] == '-')
					{
						gameField[3][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 18 && gameField[3][2] == '-')
					{
						gameField[3][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 19 && gameField[3][3] == '-')
					{
						gameField[3][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 20 && gameField[3][4] == '-')
					{
						gameField[3][4] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 21 && gameField[4][0] == '-')
					{
						gameField[4][0] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 22 && gameField[4][1] == '-')
					{
						gameField[4][1] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 23 && gameField[4][2] == '-')
					{
						gameField[4][2] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 24 && gameField[4][3] == '-')
					{
						gameField[4][3] = 'X';
						firstMove = 2;
						counter += 1;
					}
					else if (turn == 25 && gameField[4][4] == '-')
					{
						gameField[4][4] = 'X';
						firstMove = 2;
						counter += 1;
					}
				}
				else if (firstMove == 2)
				{
					clear();
					drawMassive(gridSize);
					cout << "Куда вы хотите поставить \"O\"? ";
					cin >> turn;

					if (turn == 1 && gameField[0][0] == '-')
					{
						gameField[0][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 2 && gameField[0][1] == '-')
					{
						gameField[0][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 3 && gameField[0][2] == '-')
					{
						gameField[0][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 4 && gameField[0][3] == '-')
					{
						gameField[0][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 5 && gameField[0][4] == '-')
					{
						gameField[0][4] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 6 && gameField[1][0] == '-')
					{
						gameField[1][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 7 && gameField[1][1] == '-')
					{
						gameField[1][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 8 && gameField[1][2] == '-')
					{
						gameField[1][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 9 && gameField[1][3] == '-')
					{
						gameField[1][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 10 && gameField[1][4] == '-')
					{
						gameField[1][4] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 11 && gameField[2][0] == '-')
					{
						gameField[2][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 12 && gameField[2][1] == '-')
					{
						gameField[2][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 13 && gameField[2][2] == '-')
					{
						gameField[2][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 14 && gameField[2][3] == '-')
					{
						gameField[2][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 15 && gameField[2][4] == '-')
					{
						gameField[2][4] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 16 && gameField[3][0] == '-')
					{
						gameField[3][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 17 && gameField[3][1] == '-')
					{
						gameField[3][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 18 && gameField[3][2] == '-')
					{
						gameField[3][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 19 && gameField[3][3] == '-')
					{
						gameField[3][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 20 && gameField[3][4] == '-')
					{
						gameField[3][4] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 21 && gameField[4][0] == '-')
					{
						gameField[4][0] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 22 && gameField[4][1] == '-')
					{
						gameField[4][1] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 23 && gameField[4][2] == '-')
					{
						gameField[4][2] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 24 && gameField[4][3] == '-')
					{
						gameField[4][3] = 'O';
						firstMove = 1;
						counter += 1;
					}
					else if (turn == 25 && gameField[4][4] == '-')
					{
						gameField[4][4] = 'O';
						firstMove = 1;
						counter += 1;
					}

				}
			}
		}
		// Условия победы на поле 3х3
		if (gridSize == 1)
		{
			if
				((gameField[0][0] == 'X' && gameField[0][1] == 'X' && gameField[0][2] == 'X') ||
					(gameField[1][0] == 'X' && gameField[1][1] == 'X' && gameField[1][2] == 'X') ||
					(gameField[2][0] == 'X' && gameField[2][1] == 'X' && gameField[2][2] == 'X') ||
					(gameField[0][0] == 'X' && gameField[1][1] == 'X' && gameField[2][2] == 'X') ||
					(gameField[0][2] == 'X' && gameField[1][1] == 'X' && gameField[2][0] == 'X') ||
					(gameField[0][0] == 'X' && gameField[1][0] == 'X' && gameField[2][0] == 'X') ||
					(gameField[0][1] == 'X' && gameField[1][1] == 'X' && gameField[2][1] == 'X') ||
					(gameField[0][2] == 'X' && gameField[1][2] == 'X' && gameField[2][2] == 'X'))
			{
				gameRun = false;
				cout << "Победил крестик! Поздравляю! \n\n";
			}

			else if
				((gameField[0][0] == 'O' && gameField[0][1] == 'O' && gameField[0][2] == 'O') ||
					(gameField[1][0] == 'O' && gameField[1][1] == 'O' && gameField[1][2] == 'O') ||
					(gameField[2][0] == 'O' && gameField[2][1] == 'O' && gameField[2][2] == 'O') ||
					(gameField[0][0] == 'O' && gameField[1][1] == 'O' && gameField[2][2] == 'O') ||
					(gameField[0][2] == 'O' && gameField[1][1] == 'O' && gameField[2][0] == 'O') ||
					(gameField[0][0] == 'O' && gameField[1][0] == 'O' && gameField[2][0] == 'O') ||
					(gameField[0][1] == 'O' && gameField[1][1] == 'O' && gameField[2][1] == 'O') ||
					(gameField[0][2] == 'O' && gameField[1][2] == 'O' && gameField[2][2] == 'O'))
			{
				gameRun = false;
				cout << "Победил нолик! Поздравляю! \n\n";
			}

		}
		// Условия победы на поле 4х4
		else if (gridSize == 2)
		{
			if
				((gameField[0][0] == 'X' && gameField[0][1] == 'X' && gameField[0][2] == 'X' && gameField[0][3] == 'X') ||
					(gameField[1][0] == 'X' && gameField[1][1] == 'X' && gameField[1][2] == 'X' && gameField[1][3] == 'X') ||
					(gameField[2][0] == 'X' && gameField[2][1] == 'X' && gameField[2][2] == 'X' && gameField[2][3] == 'X') ||
					(gameField[3][0] == 'X' && gameField[3][1] == 'X' && gameField[3][2] == 'X' && gameField[3][3] == 'X') ||
					(gameField[0][0] == 'X' && gameField[1][0] == 'X' && gameField[2][0] == 'X' && gameField[3][0] == 'X') ||
					(gameField[0][1] == 'X' && gameField[1][1] == 'X' && gameField[2][1] == 'X' && gameField[3][1] == 'X') ||
					(gameField[0][2] == 'X' && gameField[1][3] == 'X' && gameField[2][3] == 'X' && gameField[3][3] == 'X') ||
					(gameField[0][0] == 'X' && gameField[1][1] == 'X' && gameField[2][2] == 'X' && gameField[3][3] == 'X') ||
					(gameField[0][3] == 'X' && gameField[1][2] == 'X' && gameField[2][1] == 'X' && gameField[3][0] == 'X'))
			{
				gameRun = false;
				cout << "Победил крестик! Поздравляю! \n\n";
			}

			else if ((gameField[0][0] == 'O' && gameField[0][1] == 'O' && gameField[0][2] == 'O' && gameField[0][3] == 'O') ||
				(gameField[1][0] == 'O' && gameField[1][1] == 'O' && gameField[1][2] == 'O' && gameField[1][3] == 'O') ||
				(gameField[2][0] == 'O' && gameField[2][1] == 'O' && gameField[2][2] == 'O' && gameField[2][3] == 'O') ||
				(gameField[3][0] == 'O' && gameField[3][1] == 'O' && gameField[3][2] == 'O' && gameField[3][3] == 'O') ||
				(gameField[0][0] == 'O' && gameField[1][0] == 'O' && gameField[2][0] == 'O' && gameField[3][0] == 'O') ||
				(gameField[0][1] == 'O' && gameField[1][1] == 'O' && gameField[2][1] == 'O' && gameField[3][1] == 'O') ||
				(gameField[0][2] == 'O' && gameField[1][2] == 'O' && gameField[2][2] == 'O' && gameField[3][2] == 'O') ||
				(gameField[0][3] == 'O' && gameField[1][3] == 'O' && gameField[2][3] == 'O' && gameField[3][3] == 'O') ||
				(gameField[0][0] == 'O' && gameField[1][1] == 'O' && gameField[2][2] == 'O' && gameField[3][3] == 'O') ||
				(gameField[0][3] == 'O' && gameField[1][2] == 'O' && gameField[2][1] == 'O' && gameField[3][0] == 'O'))
			{
				gameRun = false;
				cout << "Победил нолик! Поздравляю! \n\n";
			}


		}
		// Условия победы на поле 5х5
		else if (gridSize == 3)
		{
			if
				((gameField[0][0] == 'X' && gameField[0][1] == 'X' && gameField[0][2] == 'X' && gameField[0][3] == 'X' && gameField[0][4] == 'X') ||
					(gameField[1][0] == 'X' && gameField[1][1] == 'X' && gameField[1][2] == 'X' && gameField[1][3] == 'X' && gameField[1][4] == 'X') ||
					(gameField[2][0] == 'X' && gameField[2][1] == 'X' && gameField[2][2] == 'X' && gameField[2][3] == 'X' && gameField[2][4] == 'X') ||
					(gameField[3][0] == 'X' && gameField[3][1] == 'X' && gameField[3][2] == 'X' && gameField[3][3] == 'X' && gameField[3][4] == 'X') ||
					(gameField[4][0] == 'X' && gameField[4][1] == 'X' && gameField[4][2] == 'X' && gameField[4][3] == 'X' && gameField[4][4] == 'X') ||
					(gameField[0][0] == 'X' && gameField[1][0] == 'X' && gameField[2][0] == 'X' && gameField[3][0] == 'X' && gameField[4][0] == 'X') ||
					(gameField[0][1] == 'X' && gameField[1][1] == 'X' && gameField[2][1] == 'X' && gameField[3][1] == 'X' && gameField[4][1] == 'X') ||
					(gameField[0][2] == 'X' && gameField[1][2] == 'X' && gameField[2][2] == 'X' && gameField[3][2] == 'X' && gameField[4][2] == 'X') ||
					(gameField[0][3] == 'X' && gameField[1][3] == 'X' && gameField[2][3] == 'X' && gameField[3][3] == 'X' && gameField[4][3] == 'X') ||
					(gameField[0][4] == 'X' && gameField[1][4] == 'X' && gameField[2][4] == 'X' && gameField[3][4] == 'X' && gameField[4][4] == 'X') ||
					(gameField[0][0] == 'X' && gameField[1][1] == 'X' && gameField[2][2] == 'X' && gameField[3][3] == 'X' && gameField[4][4] == 'X') ||
					(gameField[0][4] == 'X' && gameField[1][3] == 'X' && gameField[2][2] == 'X' && gameField[3][1] == 'X' && gameField[4][0] == 'X'))
			{
				gameRun = false;
				cout << "Победил крестик! Поздравляю! \n\n";
			}

			else if
				((gameField[0][0] == 'O' && gameField[0][1] == 'O' && gameField[0][2] == 'O' && gameField[0][3] == 'O' && gameField[0][4] == 'O') ||
					(gameField[1][0] == 'O' && gameField[1][1] == 'O' && gameField[1][2] == 'O' && gameField[1][3] == 'O' && gameField[1][4] == 'O') ||
					(gameField[2][0] == 'O' && gameField[2][1] == 'O' && gameField[2][2] == 'O' && gameField[2][3] == 'O' && gameField[2][4] == 'O') ||
					(gameField[3][0] == 'O' && gameField[3][1] == 'O' && gameField[3][2] == 'O' && gameField[3][3] == 'O' && gameField[3][4] == 'O') ||
					(gameField[4][0] == 'O' && gameField[4][1] == 'O' && gameField[4][2] == 'O' && gameField[4][3] == 'O' && gameField[4][4] == 'O') ||
					(gameField[0][0] == 'O' && gameField[1][0] == 'O' && gameField[2][0] == 'O' && gameField[3][0] == 'O' && gameField[4][0] == 'O') ||
					(gameField[0][1] == 'O' && gameField[1][1] == 'O' && gameField[2][1] == 'O' && gameField[3][1] == 'O' && gameField[4][1] == 'O') ||
					(gameField[0][2] == 'O' && gameField[1][2] == 'O' && gameField[2][2] == 'O' && gameField[3][2] == 'O' && gameField[4][2] == 'O') ||
					(gameField[0][3] == 'O' && gameField[1][3] == 'O' && gameField[2][3] == 'O' && gameField[3][3] == 'O' && gameField[4][3] == 'O') ||
					(gameField[0][4] == 'O' && gameField[1][4] == 'O' && gameField[2][4] == 'O' && gameField[3][4] == 'O' && gameField[4][4] == 'O') ||
					(gameField[0][0] == 'O' && gameField[1][1] == 'O' && gameField[2][2] == 'O' && gameField[3][3] == 'O' && gameField[4][4] == 'O') ||
					(gameField[0][4] == 'O' && gameField[1][3] == 'O' && gameField[2][2] == 'O' && gameField[3][1] == 'O' && gameField[4][0] == 'O'))
			{
				gameRun = false;
				cout << "Победил нолик! Поздравляю! \n\n";
			}
		}

		//Условия ничьи для поля 3х3
		if ((gridSize == 1 && counter == 9) || (gridSize == 2 && counter == 16) || (gridSize == 3 && counter == 25))
		{
			gameRun = false;
			cout << "Ничья! Победила дружба! <3\n\n";
		}
	}
}

// Функция выбора режима игры
void startGame() {
	cout << "[*] Начало игры: \n\n";
	cout << "[1] Один игрок\n";
	cout << "[2] Два игрока\n";
	cout << "[3] Вернуться обратно в меню\n\n";
	cout << "[*] Выберите режим игры: ";

	cin >> gameRuleChoose;

	switch (gameRuleChoose)
	{
	case 1:
		clear();
		play();
		break;
	case 2:
		clear();
		play();
		break;
	case 3:
		clear();
		menu();
		break;
	default:
		cout << "[*]Такого режима не предусмотрено\n";
		system("pause");
		clear();
		menu();
	}
}

// Главная функция
int main()
{
	setlocale(0, "");
	menu();

	system("pause");
	return 777;
}
