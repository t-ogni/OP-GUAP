#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ===== 1. ФУНКЦИИ =====
double f1(double x) {
    return x * x - 3 * x;
}

double f2(double x) {
    return x;
}

// ===== 2. ПЕРЕГРУЗКА =====

// Пересечение с осью X
double find(double (*f)(double), double a, double b) {
    double step = 0.01;

    for (double x = a; x <= b; x += step) {
        if (fabs(f(x)) < 0.01)
            return x;
    }
    return NAN;
}

// Пересечение двух функций на промежутке
double find(double (*f1)(double), double (*f2)(double), double a, double b) {
    double step = 0.01;

    for (double x = a; x <= b; x += step) {
        if (fabs(f1(x) - f2(x)) < 0.01)
            return x;
    }
    return NAN;
}

// ===== 3. ВСЕ ТОЧКИ ПЕРЕСЕЧЕНИЯ =====
int findAll(double (*f1)(double), double (*f2)(double),
            double a, double b, double roots[]) {  // риск переполнения памяти

    double step = 0.1;
    int count = 0;

    for (double x = a; x <= b; x += step) {
        if (fabs(f1(x) - f2(x)) < 0.05) {

            // чтобы не дублировать точки
            if (count == 0 || fabs(x - roots[count - 1]) > 0.5) {
                roots[count++] = x;
            }
        }
    }

    return count;
}

// ===== 4. ИНТЕГРИРОВАНИЕ =====
double integrate(double (*f)(double), double a, double b) {
    int n = 1000;
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

// ===== 5. MAIN =====
int main() {

    cout << fixed << setprecision(4);

    double roots[10];
    int count = findAll(f1, f2, -10, 10, roots);

    if (count < 2) {
        cout << "Недостаточно точек пересечения!" << endl;
        return 0;
    }

    double totalS = 0;

    for (int i = 0; i < count - 1; i++) {
        double a = roots[i];
        double b = roots[i + 1];

        double mid = (a + b) / 2;

        // определяем кто сверху
        if (f1(mid) > f2(mid)) {

            // локальная функция
            auto diff = [](double x) {
                return f1(x) - f2(x);
            };

            totalS += integrate(diff, a, b);

        } else {

            auto diff = [](double x) {
                return f2(x) - f1(x);
            };

            totalS += integrate(diff, a, b);
        }
    }

    // вывод точек
    cout << "Точки пересечения: ";
    for (int i = 0; i < count; i++) {
        if (fabs(roots[i]) < 0.001) roots[i] = 0;
        cout << roots[i] << " ";
    }
    cout << endl;

    cout << "Площадь (численно): " << totalS << endl;

    return 0;
}
