#include <iostream>
using namespace std;
void main() {
    setlocale(LC_ALL, "ru");
    cout << "[~]Переводчик\n\n";
    cout << "[1]Словарь русского языка\n";
    cout << "[2]Словарь английского языка\n\n";
    cout << "[3]Выход\n\n";
    cout << "Выберите словарь:  ";
    int dictionary;
    cin >> dictionary;

    switch (dictionary)
    {
    case 1:
        cout << "Словарь русско - английский\n\n";
        cout << " [1] Дом\n";
        cout << " [2] Тест\n";
        cout << " [3] Яблоко\n";
        cout << " [4] Есть\n";
        cout << " [5] Диск\n";
        cout << " [6] Ручка\n";
        cout << " [7] Рука\n";
        cout << " [8] Нога\n";
        cout << " [9] Друзья\n";
        cout << " [10] Призрак\n";
        cout << " [11] Газета\n";
        cout << " [12] Песок\n";
        cout << " [13] Компьютер\n";
        cout << " [14] Клавиатура\n";
        cout << " [15] Мама\n\n";

        cout << "Выберите номер слова, которое хотите перевести:";
        int rus;
        cin >> rus;
        switch (rus)
        {
        case 1:
            cout << "Перевод:Дом - House";
            break;
        case 2:
            cout << "Перевод:Тест - Test";
            break;
        case 3:
            cout << "Перевод:Яблоко -  Apple";
            break;
        case 4:
            cout << "Перевод:Есть - Eat";
            break;
        case 5:
            cout << "Перевод:Диск - Disk";
            break;
        case 6:
            cout << "Перевод:Ручка - pen";
            break;
        case 7:
            cout << "Перевод:Рука - Arm";
            break;
        case 8:
            cout << "Перевод:Нога - Leg";
            break;
        case 9:
            cout << "Перевод:Друзья -  Friends";
            break;
        case 10:
            cout << "Перевод:Призрак - Ghost";
            break;
        case 11:
            cout << "Перевод:Газета - Newspaper";
            break;
        case 12:
            cout << "Перевод:Песок - Sand";
            break;
        case 13:
            cout << "Перевод:Компьютер - Computer";
            break;
        case 14:
            cout << "Перевод:Клавиатура - Keyboard";
            break;
        case 15:
            cout << "Перевод:Мама - Mother";
            break;
        default:
            cout << " Данное слово отсутствует в переводчике!";
        }
    case 2:
        cout << "Словарь англо-русский\n";
        cout << " [1] House - Дом\n";
        cout << " [2] Test - Вода\n";
        cout << " [3] Apple - Яблоко\n";
        cout << " [4] Есть - Eat\n";
        cout << " [5] Disk - Диск\n";
        cout << " [6] Pen - Ручка\n";
        cout << " [7] Arm - Рука\n";
        cout << " [8] Leg - Нога\n";
        cout << " [9] Friends - Друзья\n";
        cout << " [10] Ghost - Призрак\n";
        cout << " [11] Newspaper - Газета\n";
        cout << " [12] Sand - Песок\n";
        cout << " [13] Computer- Компьютер\n";
        cout << " [14] Keyboard - Клавиатура\n";
        cout << " [15] Mother - Мама\n\n";

        cout << "Выберите номер слова, которое хотите перевести:";
        int eng;
        cin >> eng;

        switch (eng)
        {
        case 1:
            cout << "Перевод:House - Дом";
            break;
        case 2:
            cout << "Перевод:Test - Тест";
            break;
        case 3:
            cout << "Перевод:Apple - Яблоко";
            break;
        case 4:
            cout << "Перевод:Есть - Eat";
            break;
        case 5:
            cout << "Перевод:Disk - Диск";
            break;
        case 6:
            cout << "Перевод:Pen - Ручка";
            break;
        case 7:
            cout << "Перевод:Arm - Рука";
            break;
        case 8:
            cout << "Перевод:Leg - Нога";
            break;
        case 9:
            cout << "Перевод:Friends - Друзья";
            break;
        case 10:
            cout << "Перевод:Ghost - Призрак";
            break;
        case 11:
            cout << "Перевод:Newspaper - Газета";
            break;
        case 12:
            cout << "Перевод:Sand - Песок";
            break;
        case 13:
            cout << "Перевод:Computer- Компьютер";
            break;
        case 14:
            cout << "Перевод:Keyboard - Клавиатура";
            break;
        case 15:
            cout << "Перевод:Mother - Мама";
            break;
        default:
            cout << " Данное слово отсутствует в переводчике!";
            break;
        }
    case 3:
        return 0;
    }

    int _; cin >> _;
}