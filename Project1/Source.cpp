#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Функция для вычисления производной y'
double f(double x, double y, double a, double k) {
    return (a - x + pow(y, 2)) / (1 + k * y + pow(x, 2));
}

// Метод Эйлера
void euler(double x0, double y0, double h, int n, double a, double k) {
    cout << "Метод Эйлера при a = " << a << " и k = " << k << endl;
    cout << "x\t\ty" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << fixed << setprecision(6) << x0 << "\t" << y0 << endl;
        y0 = y0 + h * f(x0, y0, a, k);
        x0 = x0 + h;
    }
}

// Метод Гюна (модифицированный метод Эйлера)
void heun(double x0, double y0, double h, int n, double a, double k) {
    cout << "\nМетод Гюна при a = " << a << " и k = " << k << endl;
    cout << "x\t\ty" << endl;
    for (int i = 0; i <= n; ++i) {
        cout << fixed << setprecision(6) << x0 << "\t" << y0 << endl;
        double y_pred = y0 + h * f(x0, y0, a, k); // Предсказание
        y0 = y0 + (h / 2) * (f(x0, y0, a, k) + f(x0 + h, y_pred, a, k)); // Коррекция
        x0 = x0 + h;
    }
}

int HelloWorld() {
    cout << "Hello World\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Начальные условия
    double x0 = 0;    // начальное значение x
    double y0 = 0;    // начальное значение y
    double h = 0.1;   // шаг
    int n = 10;       // количество шагов
    float a = 0.5;    // параметр a
    float k_start = 1.0; // начальное значение k

    // Решение методом Эйлера
    while (a <= 1.5) {
        double k = k_start; // Сбросить k для каждого значения a
        while (k <= 2) {
            euler(x0, y0, h, n, a, k);
            k += 0.25;
        }
        a += 0.25;
    }

    // Сбросить a для метода Гюна
    a = 0.5; // Сбросить a к начальному значению

    // Решение методом Гюна
    while (a <= 1.5) {
        double k = k_start; // Сбросить k для каждого значения a
        while (k <= 2) {
            heun(x0, y0, h, n, a, k);
            k += 0.25;
        }
        a += 0.25;
    }

    return 0;
}