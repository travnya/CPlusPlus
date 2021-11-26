#include <iostream>
#include <cmath>
using namespace std;

double Calc(int num1, int num2, char op)
{
    switch (op)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    case '^': return pow(num1, num2);
    case '%': return num1 % num2;
    case 'sin': return cos(num1);
    case 'cos': return cos(num1);
    default: return -1;
    }
}

int main()
{
    setlocale(0, "");
    double num1, num2;
    char op;
    short count;

    cout << "[+]Калькулятор\n";
    cout << "[+]Назовите число операндов для использования(1,2): ";
    cin >> count;
    if (count == 1)
    {
        cout << "[+]Введите число: ";
        cin >> num1;

        cout << "\n\n[+]ВЫберите действие: \n\n";
        cout << "[s]Синус числа\n";
        cout << "[c]Косинус числа\n";
        cin >> op;
        cout << "[*]Результат: " << Calc(num1, 1, op) << "\n\n";
    }
    else if (count == 2)
    {

        cout << "[+]Введите первое число: ";
        cin >> num1;
        cout << "[+]Введите второе число: ";
        cin >> num2;

        cout << "\n\n[*]Выберите действие: \n\n";
        cout << "[+] - сложение\n";
        cout << "[-] - вычитание\n";
        cout << "[*] - умножение\n";
        cout << "[/] - деление\n";
        cout << "[^] - возведение в степень\n";
        cout << "[%] - остаток от деления\n";
        cin >> op;

        cout << "\n[*]Результат: " << Calc(num1, num2, op) << "\n\n";
    }
    system("pause");
    return 0;
}