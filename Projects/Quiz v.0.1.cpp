#include <iostream>
using namespace std;

short choise, settingsChoise, difficult = 1, answer, rightAns = 0, lifes;
const string questions[21][5] = {"1-й вопрос", "2-й вопрос", "3-й вопрос", "4-й вопрос", "5-й вопрос", "6-й вопрос", "7-й вопрос", "8-й вопрос", "9-й вопрос", "10-й вопрос", "11-й вопрос", "12-й вопрос", "13-й вопрос", "14-й вопрос", "15-й вопрос", "16-й вопрос" , "17-й вопрос" , "18-й вопрос" , "19-й вопрос" , "20-й вопрос" , "21-й вопрос"};

void settings();
void menu();
void play();
void clear() { system("cls"); }
void pause() { system("pause"); }

void menu()
{
	cout << "Добро пожаловать на викторину! \nВыберите действие.\n\n";
	cout << "[1] Играть\n";
	cout << "[2] Настройки\n";
	cout << "[3] Выйти\n\n";
	cout << "Ваш выбор: ";
	cin >> choise;

	switch (choise)
	{
	case 1:
		clear();
		play();
		break;
	case 2:
		clear();
		settings();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Такой опции не предусмотрено\n\n";
		pause();
		clear();
		menu();
	}
}


void settings()
{
	cout << "Настройки\n\n";
	cout << "[1] Выбрать уровень сложности\n";
	cout << "[2] Выйти в меню\n\n";
	cout << "Ваш выбор: ";
	cin >> settingsChoise;

	switch (settingsChoise)
	{
	case 1:
		clear();
		cout << "Выберите уровень сложности:\n\n";
		cout << "[1] Лёгкая (7 вопросов, 7 жизней)\n";
		cout << "[2] Средняя (14 вопросов, 3 жизни)\n";
		cout << "[3] Хардкор (21 вопросов, 1 жизнь)\n";
		cout << "[4] Назад\n\n";
		cout << "Ваш выбор: ";
		cin >> difficult;
		switch (difficult)
		{
		case 1:
			lifes = 7;
			break;
		case 2:
			lifes = 3;
			break;
		case 3:
			lifes = 1;
			break;
		case 4:
			clear();
			settings();
			break;
		default:
			cout << "Такой опции не предусмотрено\n\n";
			pause();
			clear();
			settings();
		}
		clear();
		settings();
		break;
	case 2:
		clear();
		menu();
	default:
		cout << "Такой опции не предусмотрено\n\n";
		pause();
		settings();
	}
}

void play()
{
	for (int i = 0; i < difficult * 7; i++)
	{
		cout << questions[i] << "\n";
		cout << "[*] Жизней: " + lifes << endl;
		cout << "[1] \n";
		cout << "[2] \n";
		cout << "[3] \n";
		cout << "[4] \n";
		cout << "Ваш ответ: ";
		cin >> answer;
		if (answer < 1 || answer > 4)
		{
			cout << "\nТакого ответа нет, попробуйте ещё раз\n\n";
			pause();
			clear();
			play();
		}
	}
}

int main()
{
	setlocale(0, "");
	system("color F5");
	menu();
	pause();
	return 0;
}