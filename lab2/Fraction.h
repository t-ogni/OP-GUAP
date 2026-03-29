#pragma once
#include "FractionAttributes.h"

class Fraction {
private:
    FractionAttributes attr;

    long long pow10(int p) const; // вспомогательная функция

public:
    Fraction(); // без аргументов
    Fraction(long int i, unsigned short f, int p);

    void init();
    void input();
    void display() const;
    void normalize();

    Fraction operator+(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
};
