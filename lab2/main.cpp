#include "Fraction.h"

int main() {
    // Демонстрация всех конструкторов
    Fraction f1;              // вызовет init()
    Fraction f2(2, 5, 1);      // конструктор со списком инициализации
    Fraction f3 = f2;         // конструктор копирования по умолчанию

    cout << "\nПервое число: ";
    f1.display();
    cout << "Второе число: ";
    f2.display();
    cout << "Третье число (копия второго): ";
    f3.display();


    f3 = f3 * Fraction(2,0,0);
    cout << "\nf3 = f3 * 2 = ";
    f3.display();
    
    // Демонстрация сложения
    Fraction sum = f1 + f2;
    cout << "\nСумма f1 + f2 = ";
    sum.display();

    // Демонстрация умножения
    Fraction mul = f1 * f3;
    cout << "Произведение f1 * f3 = ";
    mul.display();

    return 0;
}
