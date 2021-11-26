#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(0, "");

	cout << "Калькулятор\n\n";

	cout << "[1] Cложение\n";
	cout << "[2] Вычитание\n";
	cout << "[3] Умножение\n";
	cout << "[4] Деление\n";
	cout << "[5] Возведение первого числа в степень второго\n";
	cout << "[6] Нахождение квадратного корня числа\n";
	cout << "[7] Нахождение кубического корня числа\n\n";
	cout << "[+] Введите операцию: ";

	char operation;
	cin >> operation;

	cout << "[!] Введите первое число: ";
	float number1;
	cin >> number1;


	cout << "[!] Введите второе число: ";
	float number2;
	cin >> number2;

	if (operation == '+')
	{
		cout << "[1] Результат : " << number1 << " + " << number2 << " = " << number1 + number2;
	}

	else if (operation == '-')
	{
		cout << "[2] Результат : " << number1 << " - " << number2 << " = " << number1 - number2;
	}

	else if (operation == '*')
	{
		cout << "[3] Результат : " << number1 << " * " << number2 << " = " << number1 * number2;
	}

	else if (operation == '/')
	{
		cout << "[4] Результат : " << number1 << " / " << number2 << " = " << number1 / number2;
	}

	else if (operation == '1')
	{
		cout << "[5] Результат : " << pow(number1, number2);
	}

	else if (operation == '2')
	{
		cout << "[6] Результат для первого числа : " << sqrt(number1) << endl << "Результат для второго числа: " << sqrt(number2);
	}

	else if (operation == '3')
	{
		cout << "[7] Результат для первого числа : " << cbrt(number1) << endl << "Результат для второго числа: " << cbrt(number2);
	}

	else cout << "Ошибка";


	int _; cin >> _;
	return 0;

}