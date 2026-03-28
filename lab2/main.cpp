#include "MyDouble.h"

int main() {

    // разные способы создания объектов
    MyFraction a;               // ввод с клавиатуры
    MyFraction b(2, 50);        // с параметрами
    MyFraction c;
    c.init(1, 25);              // через метод

    // вывод
    a.print();
    b.print();
    c.print();

    // операции
    MyFraction sum = a + b;
    MyFraction product = b * c;

    sum.print();
    product.print();

    return 0;
}
