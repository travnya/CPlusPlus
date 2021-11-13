#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

int firstMove = 1, xColor, oColor, gameRuleChoose, oTurn, xTurn, a = 1;
short gridSize = 1;
bool gameRun = true;
char gameField[5][5] = { {'-','-','-','-','-'}, {'-','-','-','-','-'}, {'-','-','-','-','-'}, {'-','-','-','-','-'}, {'-','-','-','-','-'} };
void rules();
void settings();
void clear();
void playerColor();
void startGame();
bool winConditions();
int fieldSize();


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

void clear()
{
	system("cls");
}

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
		cout << "\n Ошибка! Такого цвета не существует! Введите код заново: ";
		cin >> xColor;
		cout << "\n";
	}
	cout << "Выберите цвет для 0: ";
	cin >> oColor;

	while (oColor < 1 || oColor > 7)
	{
		cout << "\n Ошибка! Такого цвета не существует! Введите код заново: ";
		cin >> oColor;
		cout << "\n";
	}
}

void drawGrid(short gridSize)
{
	a = 1;
	for (int i = 0; i < gridSize + 2; i++)
	{
		for (int j = 0; j < gridSize + 2; j++)
		{
			cout << a << " ";
			a += 1;
		}
		cout << endl;
	}
}

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

void play()
{

	while (gameRun == true)
	{

		if (gridSize == 1)
		{
			if (firstMove == 1)
			{
				clear();
				drawMassive(gridSize);
				cout << "Куда вы хотите поставить \"X\"? ";
				cin >> oTurn;

				if (oTurn == 1 && gameField[0][0] == '-')
				{
					gameField[0][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 2 && gameField[0][1] == '-')
				{
					gameField[0][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 3 && gameField[0][2] == '-')
				{
					gameField[0][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 4 && gameField[1][0] == '-')
				{
					gameField[1][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 5 && gameField[1][1] == '-')
				{
					gameField[1][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 6 && gameField[1][2] == '-')
				{
					gameField[1][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 7 && gameField[2][0] == '-')
				{
					gameField[2][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 8 && gameField[2][1] == '-')
				{
					gameField[2][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 9 && gameField[2][2] == '-')
				{
					gameField[2][2] = 'X';
					firstMove = 2;
				}
			}
			else if (firstMove == 2)
			{
				clear();
				drawMassive(gridSize);
				cout << "Куда вы хотите поставить \"O\"? ";
				cin >> oTurn;

				if (oTurn == 1 && gameField[0][0] == '-')
				{
					gameField[0][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 2 && gameField[0][1] == '-')
				{
					gameField[0][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 3 && gameField[0][2] == '-')
				{
					gameField[0][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 4 && gameField[1][0] == '-')
				{
					gameField[1][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 5 && gameField[1][1] == '-')
				{
					gameField[1][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 6 && gameField[1][2] == '-')
				{
					gameField[1][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 7 && gameField[2][0] == '-')
				{
					gameField[2][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 8 && gameField[2][1] == '-')
				{
					gameField[2][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 9 && gameField[2][2] == '-')
				{
					gameField[2][2] = 'O';
					firstMove = 1;
				}
			}
		}
		else if (gridSize == 2)
		{
			if (firstMove == 1)
			{
				clear();
				drawMassive(gridSize);
				cout << "Куда вы хотите поставить \"X\"? ";
				cin >> oTurn;

				if (oTurn == 1 && gameField[0][0] == '-')
				{
					gameField[0][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 2 && gameField[0][1] == '-')
				{
					gameField[0][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 3 && gameField[0][2] == '-')
				{
					gameField[0][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 4 && gameField[0][3] == '-')
				{
					gameField[0][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 5 && gameField[1][0] == '-')
				{
					gameField[1][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 6 && gameField[1][1] == '-')
				{
					gameField[1][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 7 && gameField[1][2] == '-')
				{
					gameField[1][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 8 && gameField[1][3] == '-')
				{
					gameField[1][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 9 && gameField[2][0] == '-')
				{
					gameField[2][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 10 && gameField[2][1] == '-')
				{
					gameField[2][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 11 && gameField[2][2] == '-')
				{
					gameField[2][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 12 && gameField[2][3] == '-')
				{
					gameField[2][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 13 && gameField[3][0] == '-')
				{
					gameField[3][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 14 && gameField[3][1] == '-')
				{
					gameField[3][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 15 && gameField[3][2] == '-')
				{
					gameField[3][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 16 && gameField[3][3] == '-')
				{
					gameField[3][3] = 'X';
					firstMove = 2;
				}
			}
			else if (firstMove == 2)
			{
				clear();
				drawMassive(gridSize);
				cout << "Куда вы хотите поставить \"O\"? ";
				cin >> oTurn;

				if (oTurn == 1 && gameField[0][0] == '-')
				{
					gameField[0][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 2 && gameField[0][1] == '-')
				{
					gameField[0][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 3 && gameField[0][2] == '-')
				{
					gameField[0][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 4 && gameField[0][3] == '-')
				{
					gameField[0][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 5 && gameField[1][0] == '-')
				{
					gameField[1][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 6 && gameField[1][1] == '-')
				{
					gameField[1][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 7 && gameField[1][2] == '-')
				{
					gameField[1][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 8 && gameField[1][3] == '-')
				{
					gameField[1][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 9 && gameField[2][0] == '-')
				{
					gameField[2][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 10 && gameField[2][1] == '-')
				{
					gameField[2][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 11 && gameField[2][2] == '-')
				{
					gameField[2][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 12 && gameField[2][3] == '-')
				{
					gameField[2][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 13 && gameField[3][0] == '-')
				{
					gameField[3][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 14 && gameField[3][1] == '-')
				{
					gameField[3][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 15 && gameField[3][2] == '-')
				{
					gameField[3][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 16 && gameField[3][3] == '-')
				{
					gameField[3][3] = 'O';
					firstMove = 1;
				}
			}
		}
		else if (gridSize == 3) 
		{
			if (firstMove == 1)
			{
				clear();
				drawMassive(gridSize);
				cout << "Куда вы хотите поставить \"X\"? ";
				cin >> oTurn;

				if (oTurn == 1 && gameField[0][0] == '-')
				{
					gameField[0][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 2 && gameField[0][1] == '-')
				{
					gameField[0][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 3 && gameField[0][2] == '-')
				{
					gameField[0][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 4 && gameField[0][3] == '-')
				{
					gameField[0][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 5 && gameField[0][4] == '-')
				{
					gameField[0][4] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 6 && gameField[1][0] == '-')
				{
					gameField[1][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 7 && gameField[1][1] == '-')
				{
					gameField[1][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 8 && gameField[1][2] == '-')
				{
					gameField[1][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 9 && gameField[1][3] == '-')
				{
					gameField[1][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 10 && gameField[1][4] == '-')
				{
					gameField[1][4] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 11 && gameField[2][0] == '-')
				{
					gameField[2][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 12 && gameField[2][1] == '-')
				{
					gameField[2][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 13 && gameField[2][2] == '-')
				{
					gameField[2][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 14 && gameField[2][3] == '-')
				{
					gameField[2][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 15 && gameField[2][4] == '-')
				{
					gameField[2][4] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 16 && gameField[3][0] == '-')
				{
					gameField[3][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 17 && gameField[3][1] == '-')
				{
					gameField[3][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 18 && gameField[3][2] == '-')
				{
					gameField[3][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 19 && gameField[3][3] == '-')
				{
					gameField[3][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 20 && gameField[3][4] == '-')
				{
					gameField[3][4] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 21 && gameField[4][0] == '-')
				{
					gameField[4][0] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 22 && gameField[4][1] == '-')
				{
					gameField[4][1] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 23 && gameField[4][2] == '-')
				{
					gameField[4][2] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 24 && gameField[4][3] == '-')
				{
					gameField[4][3] = 'X';
					firstMove = 2;
				}
				else if (oTurn == 25 && gameField[4][4] == '-')
				{
					gameField[4][4] = 'X';
					firstMove = 2;
				}
			}
			else if (firstMove == 2)
			{
				clear();
				drawMassive(gridSize);
				cout << "Куда вы хотите поставить \"O\"? ";
				cin >> oTurn;

				if (oTurn == 1 && gameField[0][0] == '-')
				{
					gameField[0][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 2 && gameField[0][1] == '-')
				{
					gameField[0][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 3 && gameField[0][2] == '-')
				{
					gameField[0][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 4 && gameField[0][3] == '-')
				{
					gameField[0][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 5 && gameField[0][4] == '-')
				{
					gameField[0][4] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 6 && gameField[1][0] == '-')
				{
					gameField[1][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 7 && gameField[1][1] == '-')
				{
					gameField[1][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 8 && gameField[1][2] == '-')
				{
					gameField[1][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 9 && gameField[1][3] == '-')
				{
					gameField[1][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 10 && gameField[1][4] == '-')
				{
					gameField[1][4] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 11 && gameField[2][0] == '-')
				{
					gameField[2][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 12 && gameField[2][1] == '-')
				{
					gameField[2][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 13 && gameField[2][2] == '-')
				{
					gameField[2][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 14 && gameField[2][3] == '-')
				{
					gameField[2][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 15 && gameField[2][4] == '-')
				{
					gameField[2][4] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 16 && gameField[3][0] == '-')
				{
					gameField[3][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 17 && gameField[3][1] == '-')
				{
					gameField[3][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 18 && gameField[3][2] == '-')
				{
					gameField[3][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 19 && gameField[3][3] == '-')
				{
					gameField[3][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 20 && gameField[3][4] == '-')
				{
					gameField[3][4] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 21 && gameField[4][0] == '-')
				{
					gameField[4][0] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 22 && gameField[4][1] == '-')
				{
					gameField[4][1] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 23 && gameField[4][2] == '-')
				{
					gameField[4][2] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 24 && gameField[4][3] == '-')
				{
					gameField[4][3] = 'O';
					firstMove = 1;
				}
				else if (oTurn == 25 && gameField[4][4] == '-')
				{
					gameField[4][4] = 'O';
					firstMove = 1;
				}

			}
		}

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

		
	}
}

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

int main()
{
	setlocale(0, "");
	menu();

	system("pause");
	return 777;
}
