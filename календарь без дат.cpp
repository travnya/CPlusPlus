#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    setlocale(0, "ru");
    int choice;
    cout << "Месяца года" << endl << endl;
    cout << "[1] Январь" << endl;
    cout << "[2] Февраль" << endl;
    cout << "[3] Март" << endl;
    cout << "[4] Апрель" << endl;
    cout << "[5] Май" << endl;
    cout << "[6] Июнь" << endl;
    cout << "[7] Июль" << endl;
    cout << "[8] Август" << endl;
    cout << "[9] Сентябрь" << endl;
    cout << "[10] Октябрь" << endl;
    cout << "[11] Ноябрь" << endl;
    cout << "[12] Декабрь" << endl;
    cout << "Выберите месяц:";

    cin >> choice;
    switch (choice)
    {


    case 1:
        cout << "Был выбран Январь";
        break;
    case 2:
        cout << "Был выбран Февраль";
        break;
    case 3:
        cout << "Был выбран Март";
        break;
    case 4:
        cout << "Был выбран Апрель";
        break;
    case 5:
        cout << "Был выбран Май";
        break;
    case 6:
        cout << "Был выбран Июнь";
        break;
    case 7:
        cout << "Был выбран Июль";
        break;
    case 8:
        cout << "Был выбран Август";
        break;
    case 9:
        cout << "Был выбран Сентябрь";
        break;
    case 10:
        cout << "Был выбран Октябрь";
        break;
    case 11:
        cout << "Был выбран Ноябрь";
        break;
    case 12:
        cout << "Был выбран Декабрь";
        break;
    default:
        cout << "Выбраного месяца не существует";
        int _; cin >> _;
        return 0;

    }
}