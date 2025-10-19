#include "func.h"

double f1(double x) {
    if (x == 0.0) return 1.0;
    return log(1 + x) / x;
}

double f2(double x) {
    return exp(- pow(x, 2) / 2.0);
}

double f3(double x) {
    if (x >= 1.0) x = 1.0 - 1e-12;
    return -log(1.0 - x);
}


double f4(double x) {
    if (x == 0.0) return 1.0;
    return pow(x, x);
}


double trapezoid(double (*func)(double), double a, double b, double eps) {
    int n = 1;

    //не доходить до правой особенности
    double be = b - eps;                 // effective right bound
    if (be <= a) be = (a + b) * 0.5;     // страховка на совсем большие eps

    double h = (be - a);
    double prev = 0.5 * h * (func(a) + func(be));
    double curr;

    for (int k = 0; k < 1000; k++) {
        double sum = 0.0;
        double x = a + h / 2.0;

        for (int i = 0; i < n; i++) {
            sum += func(x);
            x += h;
        }

        curr = 0.5 * prev + 0.5 * h * sum;

        if (fabs(curr - prev) < eps) break;

        prev = curr;
        n *= 2;
        h /= 2.0;
    }
    return curr;
}

// правка из инета: 
/*
  Особенность у f3(x) = -ln(1 - x) в правом конце x = 1.
  Метод трапеций берёт значение функции в концах отрезка, поэтому
  выборка в точке, очень близкой к 1, даёт завышенный вклад и
  замедленную/кривую сходимость интеграла.

  Решение: не использовать правый конец отрезка.
  Вместо b интегрируем до (b - delta), где delta ~ eps.
  Хвост интеграла пренебрежимо мал:
      ∫(1-delta→1) -ln(1-x) dx = delta * (1 - ln(delta))
*/
