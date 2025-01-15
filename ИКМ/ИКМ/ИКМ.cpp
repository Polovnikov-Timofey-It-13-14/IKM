#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string m, n, p;
    /*Вводится 3 числа*/
    cout << "Введи первое число: " << endl;
    getline(cin, m);
    cout << "Введи второе число: " << endl;
    getline(cin, n);
    cout << "Введи третье число: " << endl;
    getline(cin, p);

    //Проверка на отрицательное число
    if ((m[0] == '-') or (n[0] == '-') or (n[0] == '-'))
    {
        cout << "Все числа должны быть положительны" << endl;
        return 0;
    }

    /*Проверка на пробелы*/
    if (!space(m) or !space(n) or !space(p))
    {
        cout << "В строке не может быть пробелов" << endl;
        return 0;
    }

    /*Проверка на число в строке*/
    if (!number(m) or !number(n) or !number(p))
    {
        cout << "В строке могут быть только цифры" << endl;
        return 0;
    }

    //Проверка на то, что число начинается не с 0
    if ((m[0] == '0') or (n[0] == '0') or (n[0] == '0'))
    {
        cout << "Число начинается с 0, чего не может быть" << endl;
        return 0;
    }
    string r1 = NOD(m, n); /*НОД для 1 и 2 числа*/
    string r = NOD(r1, p); /*НОД для последнего числа и НОД первых двух*/
    cout << "Наибольший общий делитель " << m << " , " << n << " и " << p << " равен " << r << endl;
}
