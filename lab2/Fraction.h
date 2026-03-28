#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

// ===== КЛАСС АТРИБУТОВ =====
class FractionData {
private:
    long integerPart;           // целая часть
    unsigned short fracPart;    // дробная часть

public:
    FractionData(long i = 0, unsigned short f = 0);

    long getInt() const;
    unsigned short getFrac() const;

    void set(long i, unsigned short f);

    // дружественные ввод/вывод
    friend istream& operator>>(istream& in, FractionData& d);
    friend ostream& operator<<(ostream& out, const FractionData& d);
};

// ===== БАЗОВЫЙ КЛАСС =====
class Fraction {
private:
    FractionData data; // агрегация

public:
    // конструкторы
    Fraction();
    Fraction(long i, unsigned short f);

    // инициализация
    void init(long i, unsigned short f);
    void init(); // с клавиатуры

    // вывод
    void print();

    // операции
    Fraction operator+(const Fraction& other);
    Fraction operator*(const Fraction& other);
};

#endif
