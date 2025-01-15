#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

/*������� ��� ������ ������� � ������*/
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

/*������� ��� �������� �� �����*/
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

/*��������� �����*/
bool compare(string& x, string& y)
{
    if (x.length() != y.length())       /*���� ����� ������, �� ������� ���������� x > y*/
    {
        return x.length() > y.length();
    }
    return x >= y;
}

//�� ����� n1 ��������� ����� n2 ����� ������
string sub(string& x, string& y)
{
    int r1 = x.length(), r2 = y.length(), p = 0;
    string r;
    for (int i = 0; i < r1; i++)
    {
        int a = x[r1 - 1 - i] - '0'; //����� ������� ����� ������ ������
        int b = 0;
        if (i < r2)
        {
            b = y[r2 - 1 - i] - '0'; //����� ������� ����� ������ ������
        }
        int d = a - b - p;
        if (d < 0)
        {
            d = d + 10; //��������� ������ ������ � �����
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

/*��������� 2 ����� �� 1, ���� ������� �� ������ ������ 2 �����*/
string abc(string x, string y)
{
    string t, r;
    for (char ch : x)
    {
        t += ch; //������������ �������� x ������ t
        if (t[0] == '0' && t.length() > 1)
        {
            t.erase(0);
        }
        while (compare(t, y)) //���� 1 ������ ������� �������� �� 1 ������
        {
            t = sub(t, y);
        }
    }
    r = t;
    return r;
}

/*�������� �������*/
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