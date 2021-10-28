#include <iostream>
using namespace std;

string backgroundColor, foregroundColor, color;
short choise;
char symbol;

void menu()
{

    cout << "===========================================================\n\n";
    cout << "Привет, я - программа, исполняющая функции, используй меня\n";
    cout << "Вот, что я могу тебе предоставить: \n\n";
    cout << "[1] Очистка консоли\n";
    cout << "[2] Изменение цвета фона консоли\n";
    cout << "[3] Вывод размера типа данных INT\n";
    cout << "[4] Вывод размера типа данных CHAR\n";
    cout << "[5] Вывод размера типа данных DOUBLE\n";
    cout << "[6] Вывод размера типа данных FLOAT\n";
    cout << "[7] Вывод размера типа данных BOOL\n";
    cout << "[8] Вывод сообщения\n";
    cout << "[9] Вывод квадрата 5х5\n\n";
    cout << "[777] Выход из программы\n\n";
    cout << "===========================================================\n\n";

    cout << "Выбери что-то одно: ";
    cin >> choise;
    cout << "\n\n";
}

void clearConsole()
{
    system("cls");
}

void changeColor()
{
    cout << "Доступные цвета: \n\n";
    cout << "[0] - Чёрный\n";
    cout << "[1] - Синий\n";
    cout << "[2] - Зелёный\n";
    cout << "[3] - Голубой\n";
    cout << "[4] - Красный\n";
    cout << "[5] - Лиловый\n";
    cout << "[6] - Жёлтый\n";
    cout << "[7] - Белый\n";
    cout << "[8] - Серый\n";
    cout << "[9] - Светло-синий\n";
    cout << "[A] - Светло-зелёный\n";
    cout << "[B] - Светло-голубой\n";
    cout << "[C] - Светло-красный\n";
    cout << "[D] - Светло-лиловый\n";
    cout << "[E] - Светло-жёлтый\n";
    cout << "[F] - Ярко-белый\n\n";

    cout << "Выберите цвет фона: ";
    cin >> backgroundColor;
    cout << "\nВыберите цвет текста: ";
    cin >> foregroundColor;

    color = "color " + backgroundColor + foregroundColor;
    const char* userColor = color.c_str();
    system(userColor);
}


void getSizeInt()
{
    cout << "Размер типа данных INT = " << sizeof(int) << endl;
}

void getSizeChar()
{
    cout << "Размер типа данных CHAR = " << sizeof(char) << endl;
}

void getSizeDouble()
{
    cout << "Размер типа данных DOUBLE = " << sizeof(double) << endl;
}

void getSizeFloat()
{
    cout << "Размер типа данных FLOAT = " << sizeof(float) << endl;
}

void getSizeBool()
{
    cout << "Размер типа данных BOOL = " << sizeof(bool) << endl;
}

void getMessage()
{
    cout << "Привет, я - функция :3\n";
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



    if (choise != 777)
    {
        switch (choise)
        {
        case 1:
            clearConsole();
            system("pause");
            menu();
        case 2:
            changeColor();
            system("pause");
            clearConsole();
            menu();
        case 3:
            getSizeInt();
            system("pause");
            clearConsole();
            menu();
        case 4:
            getSizeChar();
            system("pause");
            clearConsole();
            menu();
        case 5:
            getSizeDouble();
            system("pause");
            clearConsole();
            menu();
        case 6:
            getSizeFloat();
            system("pause");
            clearConsole();
            menu();
        case 7:
            getSizeBool();
            system("pause");
            clearConsole();
            menu();
        case 8:
            getMessage();
            system("pause");
            clearConsole();
            menu();
        case 9:
            cout << "Какой символ вы предпочитаете использовать? - ";
            cin >> symbol;
            printSquare(symbol);
            system("pause");
            clearConsole();
            menu();
        default:
            cout << "Такой функционал пока ещё не реализован :с\n";
            system("pause");
            clearConsole();
            menu();
        }

    }
    else {
        clearConsole();
        exit(777);
    }
    return 777;
}
