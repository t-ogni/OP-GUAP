#include "Fraction.h"
#include <iostream>
using namespace std;

// степень 10 без pow()
long long Fraction::pow10(int p) const {
    long long res = 1;
    for (int i = 0; i < p; i++) res *= 10;
    return res;
}

// конструкторы
Fraction::Fraction() {
    init();
}

Fraction::Fraction(long int i, unsigned short f, int p) : attr(i, f, p) {}

// ввод
void Fraction::init() {
    input();
}

void Fraction::input() {
    std::string s;
    std::cout << "Введите число (например 12.034): ";
    std::cin >> s;

    size_t pos = s.find('.');

    long int intPart = 0;
    unsigned short fracPart = 0;
    int precision = 0;

    if (pos != std::string::npos) {
        // есть точка
        intPart = std::stol(s.substr(0, pos));

        std::string fracStr = s.substr(pos + 1);
        precision = fracStr.length();

        fracPart = std::stoi(fracStr);
    } else {
        // нет дробной части
        intPart = std::stol(s);
        fracPart = 0;
        precision = 0;
    }

    attr.set(intPart, fracPart, precision);
}
void Fraction::normalize() {
    long long frac = attr.getFraction();
    int p = attr.getPrecision();

    while (p > 0 && frac % 10 == 0) {
        frac /= 10;
        p--;
    }

    attr.set(attr.getInteger(), frac, p);
}

// вывод
void Fraction::display() const {
    std::cout << attr.getInteger();

    int p = attr.getPrecision();
    if (p > 0) {
        std::cout << ".";

        unsigned short frac = attr.getFraction();
        long long scale = pow10(p - 1);

        while (scale > frac && scale > 1) {
            std::cout << "0";
            scale /= 10;
        }

        std::cout << frac;
    }

    std::cout << std::endl;
}

// сложение
Fraction Fraction::operator+(const Fraction& other) const {
    int p1 = attr.getPrecision();
    int p2 = other.attr.getPrecision();

    int maxP = (p1 > p2) ? p1 : p2;

    long long f1, f2; 

    if (attr.getInteger() < 0)
        f1 = attr.getInteger() * pow10(p1) - attr.getFraction();
    else
        f1 = attr.getInteger() * pow10(p1) + attr.getFraction();

    if (other.attr.getInteger() < 0)
        f2 = other.attr.getInteger() * pow10(p2) - other.attr.getFraction();
    else
        f2 = other.attr.getInteger() * pow10(p2) + other.attr.getFraction();

    // выравниваем точность
    f1 *= pow10(maxP - p1);
    f2 *= pow10(maxP - p2);

    long long result = f1 + f2;

    long long scale = pow10(maxP);

    long int intPart = result / scale;
    long long fracPart = llabs(result % scale);
    
    Fraction res(intPart, fracPart, maxP);
    res.normalize();
    return res;
}

// умножение
Fraction Fraction::operator*(const Fraction& other) const {
    int p1 = attr.getPrecision();
    int p2 = other.attr.getPrecision();

    long long f1, f2;

    // правильная сборка числа
    if (attr.getInteger() < 0)
        f1 = attr.getInteger() * pow10(p1) - attr.getFraction();
    else
        f1 = attr.getInteger() * pow10(p1) + attr.getFraction();

    if (other.attr.getInteger() < 0)
        f2 = other.attr.getInteger() * pow10(p2) - other.attr.getFraction();
    else
        f2 = other.attr.getInteger() * pow10(p2) + other.attr.getFraction();

    long long result = f1 * f2;

    int newPrecision = p1 + p2;
    long long scale = pow10(newPrecision);

    long int intPart = result / scale;
    long long fracPart = llabs(result % scale);

    Fraction res(intPart, fracPart, newPrecision);
    res.normalize();
    return res;
}
