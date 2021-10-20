#include <iostream>
using namespace std;

int main()
{
    int n[10] = {1,2,3,4,5,6,7,8,9,10};
    short s[10] = {10,9,8,7,6,5,4,3,2,1};
    long l[10] = {10,1,9,2,8,3,7,4,6,5};
    char c[10] = {'b', 'i', 'l', 'l', 'y', ' ', 'h', 'e', 'r', 'y'};
    bool b[10] = {1,0,1,0,1,1,0,1,0,0};
    double d[10] = {1.23,2.34,3.45,4.56,5.67,6.78,7.89,8.90,9.11,2.28};
    float f[10] = {1.337,2.28,3.14,4.20,5.55,6.66,7.77,8.800,9.6,2512342.412490};
    string str[10] = {"vovka", "mishka", "martushka", "ya", "jestemgejem", "uzhe", "Matie", "Baal", "Agamen", "Modrizgi"};

    cout << "Integer" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << n[i] << endl;
    }
    cout << endl;
    
    cout << "Short" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << s[i] << endl;
    }
    cout << endl;
    
    cout << "Long" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << l[i] << endl;
    }
    cout << endl;
    
    cout << "Char" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << c[i] << endl;
    }
    cout << endl;
    
    cout << "Boolean" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << b[i] << endl;
    }
    cout << endl;
    
    cout << "Double" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << d[i] << endl;
    }
    cout << endl;
    
    cout << "Float" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << f[i] << endl;
    }
    cout << endl;
    
    cout << "String" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "[" << i + 1 << "] - " << str[i] << endl;
    }
    cout << endl;

    system("pause");
    return 777;
}
