#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    cout << "[+] Панель Функций " << endl << endl;
    cout << "[1] Очищение консоли " << endl;
    cout << "[2] Изменение цвета фона консоли " << endl;
    cout << "[3] Изменение цвета текста консоли " << endl;
    cout << "[4] Вывод размера типа данных INT " << endl;
    cout << "[5] Вывод размера типа данных CHAR " << endl;
    cout << "[6] Вывод размера типа данных DOUBLE " << endl;
    cout << "[7] Вывод размера типа данныx FLOAT " << endl;
    cout << "[8] Вывод размера типа данных BOOL" << endl;
    cout << "[9] Вывод сообщения 'Привет я функция'" << endl;
    cout << "[10] Вывод квадрата 5х5" << endl;

    cout << "Выберите функцию: ";
    int choise;
    cin >> choise;
    switch (choise)
    {
    case 1:
        system("cls");
        break;
    case 2:
        system("color F1");
        break;
    case 3:
        system("color 6");
        break;
    case 4:
        cout << "Размер типа данных INT = 4 байтам" << endl;
        break;
    case 5:
        cout << "Размер типа данных CHAR = 1 байту" << endl;
        break;
    case 6:
        cout << "Размер типа данных DOUBLE = 8 байтам" << endl;
        break;
    case 7:
        cout << "Размер типа данных FLOAT = 4 байтам" << endl;
        break;
    case 8:
        cout << "Размер типа данных BOLL = 1 байту" << endl;
        break;
    case 9:
        cout << "Привет я функция!" << endl;
        break;
    case 10:
        cout << "Введите любой символ:";
        int symbol;
        cin >> symbol;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << symbol << " ";
            }
            cout << endl;
        }
        break;
    }
    int _; cin >> _;
}