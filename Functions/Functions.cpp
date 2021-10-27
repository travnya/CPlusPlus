#include <iostream>
using namespace std;

short choise;
char symbol;

void menu()
{
    cout << "Привет, я - программа, исполняющая функции, используй меня\n";
    cout << "Вот, что я могу тебе предоставить: \n\n";
    cout << "[1] Очистка консоли\n";
    cout << "[2] Изменение цвета фона консоли\n";
    cout << "[3] Изменение цвета текста консоли\n";
    cout << "[4] Вывод размера типа данных INT\n";
    cout << "[5] Вывод размера типа данных CHAR\n";
    cout << "[6] Вывод размера типа данных DOUBLE\n";
    cout << "[7] Вывод размера типа данных FLOAT\n";
    cout << "[8] Вывод размера типа данных BOOL\n";
    cout << "[9] Вывод сообщения\n";
    cout << "[10] Вывод квадрата 5х5\n\n";

    cout << "Выбери что-то одно: ";
    cin >> choise;
    cout << "\n\n";
}

void clearConsole()
{
    system("cls");
}

void changeBGcolor() 
{
    system("color B5");
}

void changeFontColor()
{
    system("color B");
}

void getSizeInt() 
{
    cout << "Размер типа данных INT = 4 байта\n";
}

void getSizeChar() 
{
    cout << "Размер типа данных CHAR = 1 байт\n";
}

void getSizeDouble() 
{
    cout << "Размер типа данных DOUBLE = 8 байт\n";
}

void getSizeFloat() 
{
    cout << "Размер типа данных FLOAT = 4 байта\n";
}

void getSizeBool() 
{
    cout << "Размер типа данных BOOL = 1 байт\n";
}

void getMessage()
{
    cout << "Привет, я - функция :3";
}

void printSquare(char)
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++)
        {
            cout << symbol << " ";
        }
        cout << endl;
    }
}


int main()
{
    setlocale(0, "");

    menu();

    clearConsole();

    switch (choise) 
    {
    case 1:
        clearConsole();
        break;
    case 2:
        changeBGcolor();
        break;
    case 3:
        changeFontColor();
        break;
    case 4:
        getSizeInt();
        break;
    case 5:
        getSizeChar();
        break;
    case 6:
        getSizeDouble();
        break;
    case 7:
        getSizeFloat();
        break;
    case 8:
        getSizeBool();
        break;
    case 9:
        getMessage();
        break;
    case 10:
        cout << "Какой символ вы предпочитаете использовать?";
        cin >> symbol;
        printSquare(symbol);
        break;
    default:
        cout << "Такой функционал пока ещё не реализован\n\n";
    }

    system("pause");
    return 01001;
}
