#include "Fraction.h"

// ===== FractionData =====
FractionData::FractionData(long i, unsigned short f) {
    integerPart = i;
    fracPart = f;
}

long FractionData::getInt() const {
    return integerPart;
}

unsigned short FractionData::getFrac() const {
    return fracPart;
}

void FractionData::set(long i, unsigned short f) {
    integerPart = i;
    fracPart = f;
}

istream& operator>>(istream& in, FractionData& d) {
    cout << "Введите целую часть: ";
    in >> d.integerPart;
    cout << "Введите дробную часть: ";
    in >> d.fracPart;
    return in;
}

ostream& operator<<(ostream& out, const FractionData& d) {
    out << d.integerPart << "." << d.fracPart;
    return out;
}

// ===== Fraction =====
Fraction::Fraction() {
    init();
}

Fraction::Fraction(long i, unsigned short f) : data(i, f) {}

void Fraction::init(long i, unsigned short f) {
    data.set(i, f);
}

void Fraction::init() {
    cin >> data;
}

void Fraction::print() {
    cout << data << endl;
}

// ===== СЛОЖЕНИЕ =====
Fraction Fraction::operator+(const Fraction& other) {

    double a = data.getInt() + data.getFrac() / 100.0;
    double b = other.data.getInt() + other.data.getFrac() / 100.0;

    double res = a + b;

    long i = (long)res;
    unsigned short f = (res - i) * 100;

    return Fraction(i, f);
}

// ===== УМНОЖЕНИЕ =====
Fraction Fraction::operator*(const Fraction& other) {

    double a = data.getInt() + data.getFrac() / 100.0;
    double b = other.data.getInt() + other.data.getFrac() / 100.0;

    double res = a * b;

    long i = (long)res;
    unsigned short f = (res - i) * 100;

    return Fraction(i, f);
}
