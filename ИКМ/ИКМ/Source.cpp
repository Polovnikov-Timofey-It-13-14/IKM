#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

/*Функция по поиску пробела в строке*/
bool space(string& s)
{
    for (char x : s)
    {
        if (x == ' ')
        {
            return false;
        }
    }
    return true;
}

/*Функция для проверки на число*/
bool number(string& s)
{
    for (char n : s)
    {
        if (isdigit(n))
        {
            return true;
        }
    }
    return false;
}

/*Сравнение чисел*/
bool compare(string& x, string& y)
{
    if (x.length() != y.length())       /*Если длина разная, то функция возвращает x > y*/
    {
        return x.length() > y.length();
    }
    return x >= y;
}

//Из числа n1 вычитание числа n2 через строки
string sub(string& x, string& y)
{
    int r1 = x.length(), r2 = y.length(), p = 0;
    string r;
    for (int i = 0; i < r1; i++)
    {
        int a = x[r1 - 1 - i] - '0'; //Цифры первого числа справа налево
        int b = 0;
        if (i < r2)
        {
            b = y[r2 - 1 - i] - '0'; //Цифры второго числа справа налево
        }
        int d = a - b - p;
        if (d < 0)
        {
            d = d + 10; //Переносим правый разряд в левый
            p = 1;
        }
        else
        {
            p = 0;
        }
        r.push_back(d + '0');
    }

    while (r.length() > 1 && r.back() == '0')
    {
        r.pop_back();
    }
    reverse(r.begin(), r.end());
    return r;
}

/*Вычитание 2 числа из 1, пока остаток не станет меньше 2 числа*/
string abc(string x, string y)
{
    string t, r;
    for (char ch : x)
    {
        t += ch; //Присваивание элемента x строке t
        if (t[0] == '0' && t.length() > 1)
        {
            t.erase(0);
        }
        while (compare(t, y)) //Пока 1 больше второго вычитаем из 1 второе
        {
            t = sub(t, y);
        }
    }
    r = t;
    return r;
}

/*Алгоритм Евклида*/
string NOD(string a, string b)
{
    while (b != "0")
    {
        string c;
        c = abc(a, b);
        a = b;
        b = c;
    }
    return a;
}
