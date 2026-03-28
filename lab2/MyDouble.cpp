#include "MyDouble.h"

// ===== MyDouble =====
MyDouble::MyDouble(long i, unsigned short f) {
    integer = i;
    fractional = f;
}

long MyDouble::getInteger() const {
    return integer;
}

unsigned short MyDouble::getFractional() const {
    return fractional;
}

void MyDouble::set(long i, unsigned short f) {
    integer = i;
    fractional = f;
}

istream& operator>>(istream& in, MyDouble& d) {
    cout << "Enter integer part: ";
    in >> d.integer;
    cout << "Enter fractional part: ";
    in >> d.fractional;
    return in;
}

ostream& operator<<(ostream& out, const MyDouble& d) {
    out << d.integer << "." << d.fractional;
    return out;
}

// ===== MyFraction =====
MyFraction::MyFraction() {
    init();
}

MyFraction::MyFraction(long i, unsigned short f) : value(i, f) {}

void MyFraction::init(long i, unsigned short f) {
    value.set(i, f);
}

void MyFraction::init() {
    cin >> value;
}

void MyFraction::print() {
    cout << value << endl;
}

// ===== СЛОЖЕНИЕ =====
MyFraction MyFraction::operator+(const MyFraction& other) {
    double a = value.getInteger() + value.getFractional() / 100.0;
    double b = other.value.getInteger() + other.value.getFractional() / 100.0;

    double res = a + b;

    long i = (long)res;
    unsigned short f = (res - i) * 100;

    return MyFraction(i, f);
}

// ===== УМНОЖЕНИЕ =====
MyFraction MyFraction::operator*(const MyFraction& other) {
    double a = value.getInteger() + value.getFractional() / 100.0;
    double b = other.value.getInteger() + other.value.getFractional() / 100.0;

    double res = a * b;

    long i = (long)res;
    unsigned short f = (res - i) * 100;

    return MyFraction(i, f);
}
