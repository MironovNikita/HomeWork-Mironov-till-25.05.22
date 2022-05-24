#include <iostream>
#include <windows.h>
#include "Fraction.cpp"

#define line cout << "--------------------------------------------------------------------------------------------------------" << endl;

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int w1, n1, d1, w2, n2, d2;
    cout << "Если вы хотите посчитать отрицательную дробь, ставьте минус перед целой частью, иначе перед числителем" << endl;
    line;
    cout << "Введите целую часть для 1-ой дроби: ";
    cin >> w1;
    cout << "Введите числитель для 1-ой дроби: ";
    cin >> n1;
    cout << "Введите знаменатель для 1-ой дроби: ";
    cin >> d1;
    cout << "Введите целую часть для 2-ой дроби: ";
    cin >> w2;
    cout << "Введите числитель для 2-ой дроби: ";
    cin >> n2;
    cout << "Введите знаменатель для 2-ой дроби: ";
    cin >> d2;
    Fraction f1(w1, n1, d1);
    Fraction f2(w2, n2, d2);

    system("cls");
    cout << "Введённые Вами дроби: " << endl;
    cout << "Дробь №1: " << w1 << " целых " << n1 << " / " << d1 << endl;
    cout << "Дробь №2: " << w2 << " целых " << n2 << " / " << d2 << endl;
    cout << endl;
    
    f1.plus(f2);
    f1.mult(f2);
    f1.minus(f2);
    f1.div(f2);
   

}


