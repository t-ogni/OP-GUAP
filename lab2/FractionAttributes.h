#pragma once
#include <iostream>
using namespace std;

class FractionAttributes {
private:
    long long integerPart;
    unsigned long long fractionalPart;
    int precision;

public:
    FractionAttributes(long int i = 0, unsigned short f = 0, int p = 0)
        : integerPart(i), fractionalPart(f), precision(p) {}

    long int getInteger() const { return integerPart; }
    unsigned short getFraction() const { return fractionalPart; }
    int getPrecision() const { return precision; }

    void set(long int i, unsigned short f, int p) {
        integerPart = i;
        fractionalPart = f;
        precision = p;
    }
};
