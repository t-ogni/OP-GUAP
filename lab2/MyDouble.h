#ifndef MYDOUBLE_H
#define MYDOUBLE_H

#include <iostream>
using namespace std;

// ===== КЛАСС ДЛЯ ХРАНЕНИЯ ЧИСЛА =====
class MyDouble {
private:
    long integer;            // целая часть
    unsigned short fractional; // дробная часть

public:
    MyDouble(long i = 0, unsigned short f = 0);

    long getInteger() const;
    unsigned short getFractional() const;

    void set(long i, unsigned short f);

    // дружественные функции для ввода/вывода
    friend istream& operator>>(istream& in, MyDouble& d);
    friend ostream& operator<<(ostream& out, const MyDouble& d);
};

// ===== БАЗОВЫЙ КЛАСС =====
class MyFraction {
private:
    MyDouble value; // агрегация

public:
    // конструкторы
    MyFraction();
    MyFraction(long i, unsigned short f);

    // инициализация
    void init(long i, unsigned short f);
    void init(); // ввод с клавиатуры

    // вывод
    void print();

    // операции
    MyFraction operator+(const MyFraction& other);
    MyFraction operator*(const MyFraction& other);
};

#endif
