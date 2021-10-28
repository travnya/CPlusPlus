#include <iostream>
#include <math.h>
using namespace std;

int Calc(int num1, int num2, char op)
{
	if (op == '/' && num2 == 0)
		cout << "Я не думаю, что это возможно";
	switch (op)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		return num1 / num2;
		break;
	case '^':
		return pow(num1, num2);
		break;
	case '%':
		return num1 % num2;
		break;
	case '^2^':
		return sqrt(num1);
		break;
	case '^3^':
		return cbrt(num1);
		break;
	default:
		cout << "Такого действия пока ещё не добавлено :с";
	}
}

int main()
{
	setlocale(0, "");
	system("color F1");
	int num1, num2;
	char op;
	short count;

	cout << "Самодостаточная программа-калькулятор - посчитает всё, что посчитает нужным\n\n";

	cout << "Сколько чисел вы хотите использовать? - ";
	cin >> count;
	if (count == 1)
	{
		cout << "[*]Введите ваше число: ";
		cin >> num1;

		cout << "\n\n[*]Какое действие с ним необходимо сделать?\n\n";
		cout << "[^2^]Квадратный корень из числа\n";
		cout << "[^3^]Кубический корень из числа\n";
		cout << "[*]Выберите действие: ";
		cin >> op;
		cout << "[*]Результат: " << Calc(num1, 0, op) << "\n\n";
	}
	else if (count == 2)
	{

		cout << "[*]Введите первое число: ";
		cin >> num1;
		cout << "[*]Введите второе число: ";
		cin >> num2;

		cout << "\n\n[*]Какое действие с ними необходимо сделать?\n\n";
		cout << "[+] - сложение\n";
		cout << "[-] - вычитание\n";
		cout << "[*] - умножение\n";
		cout << "[/] - деление\n";
		cout << "[^] - возведение в степень\n";
		cout << "[%] - остаток от деления\n";
		cout << "[*]Выберите действие: ";
		cin >> op;

		cout << "\n[*]Результат: " << Calc(num1, num2, op) << "\n\n";
	}
	system("pause");
	return 777;
}