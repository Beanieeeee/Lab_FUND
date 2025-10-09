#include "func.h" 

float e_sum(float eps) {
    float e = 1.0; 
    float term = 1.0;   
    int n = 1;

    while (term > eps) {
        term = term / n; 
        e += term;
        n++;
    }
    return e;
}

float e_pred(float eps) {
    float prev = 0.0;
    float now = powf(1.0 + 1.0, 1.0);
    float n = 1.0;
    while (fabsf(now - prev) > eps) {
        prev = now;
        n = n * 2.0;
        now = powf(1.0 + 1.0/n, n);
    }
    return now;
}

float e_yr(float eps) {
    float x = 2.0f;
    float x_new;
    while (1) {
        float fx  = logf(x) - 1.0f;
        float dfx = 1.0f / x;
        x_new = x - fx / dfx;
        if (fabsf(x_new - x) < eps)
            break;
        x = x_new;
    }
    return x_new;
}


float pi_sum(float eps) {
    float pi = 0.0f; 
    int n = 1;
    float t;

    do {
        t = powf(-1.0f, n - 1) / (2.0f * n - 1.0f);
        pi += t;
        n++;
    } while (fabsf(t) > eps && n < 10000000);
    return pi * 4.0f;
}

float ln_sum(float eps){
    float ln = 0.0f; 
    int n = 1;
    float t;
    do {
        t = powf(-1, n - 1) / n;
        ln += t;
        n++;
    } while (fabsf(t) > eps && n < 10000000);
    return ln;
}