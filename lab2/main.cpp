#include "Fraction.h"

int main() {

    // разные способы создания объектов
    Fraction a;                 // ввод с клавиатуры
    Fraction b(2, 50);          // с параметрами
    Fraction c;                 
    c.init(1, 25);              // через метод

    // вывод
    a.print();
    b.print();
    c.print();

    // операции
    Fraction sum = a + b;
    Fraction mult = b * c;

    sum.print();
    mult.print();

    return 0;
}
