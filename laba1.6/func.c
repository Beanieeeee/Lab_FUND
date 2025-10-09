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
    double h = (b - a);
    double prev = 0.5 * h * (func(a) + func(b));
    double curr;

    while (1) {
        double sum = 0.0;
        double x = a + h / 2.0;

        for (int i = 0; i < n; i++) {
            sum += func(x);
            x += h;
        }

        curr = 0.5 * prev + 0.5 * h * sum;

        if (fabs(curr - prev) < eps)
            break;

        prev = curr;
        n *= 2;
        h /= 2.0;
    }

    return curr;
}

