#include "func.h"
#include <math.h>
#include <float.h>

float e_sum(float eps) {
    float e = 1.0f; 
    float term = 1.0f;   
    int n = 1;
    while (fabsf(term) > eps && n < 10000000) {
        term = term / n; 
        e += term;
        n++;
    }
    return e;
}

float e_pred(float eps) {
    float prev = 0.0f;
    float now  = powf(1.0f + 1.0f, 1.0f);
    float n    = 1.0f;
    for (int it = 0; it < 1000; ++it) {
        prev = now;
        n *= 2.0f;
        float inc = 1.0f / n;
        if (1.0f + inc == 1.0f)
            return prev;
        now = powf(1.0f + inc, n);
        if (fabsf(now - prev) <= eps) return now;
    }
    return now;
}


float e_yr(float eps) {
    float x = 2.0f;
    for (int k = 0; k < 100; ++k) {
        float x_new = x * (2.0f - logf(x));
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new))) return x_new;
        x = x_new;
    }
    return x;
}

float pi_sum(float eps) {
    float s = 0.0f, t;
    int sign = 1, n = 1;
    do {
        t = sign / (2.0f * n - 1.0f);
        s += t;
        sign = -sign;
        n++;
    } while (fabsf(t) > eps && n < 10000000);
    return 4.0f * s;
}

float pi_pred(float eps) {
    float prod = 1.0f, prev = 0.0f, curr = 0.0f;
    for (int n = 1; n < 10000000; ++n) {
        prod *= (4.0f*n*n) / ((2.0f*n-1.0f)*(2.0f*n+1.0f));
        curr  = 2.0f * prod;
        if (fabsf(curr - prev) < eps) return curr;
        prev = curr;
    }
    return curr;
}

float pi_yr(float eps) {
    float x = 3.0f;
    for (int k = 0; k < 100; ++k) {
        float f  = cosf(x) + 1.0f;
        float fp = -sinf(x);
        float x_new = x - f / fp;
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new))) return x_new;
        x = x_new;
    }
    return x;
}

float ln_sum(float eps){
    float s = 0.0f, t;
    int sign = 1, n = 1;
    do {
        t = sign / (float)n;
        s += t;
        sign = -sign;
        n++;
    } while (fabsf(t) > eps && n < 10000000);
    return s;
}

float ln_pred(float eps) {
    int n = 1;
    float prev = n * (powf(2.0f, 1.0f/n) - 1.0f);
    n *= 2;
    float a = n * (powf(2.0f, 1.0f/n) - 1.0f);
    while (fabsf(a - prev) > eps) {
        prev = a;
        n *= 2;
        a = n * (powf(2.0f, 1.0f/n) - 1.0f);
    }
    return a;
}

float ln_yr(float eps) {
    float x = 1.0f;
    for (int k = 0; k < 100; ++k) {
        float ex = expf(x);
        float x_new = x - (ex - 2.0f)/ex;
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new))) return x_new;
        x = x_new;
    }
    return x;
}

float sq_sum(float eps){
    float sq = 1.0f; 
    int k = 2;
    float t;
    do {
        t = powf(2.0f, powf(2.0f, -(float)k));
        sq *= t;
        k++;
    } while (fabsf(t - 1.0f) > eps && k < 10000000);
    return sq;
}

float sq_pred(float eps) {
    float x = 1.0f, prev = 0.0f, t;
    int k = 2;
    do {
        t = powf(2.0f, powf(2.0f, -(float)k));
        x *= t;
        if (fabsf(x - prev) <= eps) return x;
        prev = x;
        k++;
    } while (fabsf(t - 1.0f) > eps && k < 10000000);
    return x;
}


float sq_yr(float eps) {
    float x = 1.0f;
    for (int k = 0; k < 100; ++k) {
        float x_new = x - (x*x - 2.0f) / (2.0f * x);
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new))) return x_new;
        x = x_new;
    }
    return x;
}

float y_sum(float eps){
    float s = 0.0f, term;
    int k = 1;
    do {
        term = 1.0f/k - logf(1.0f + 1.0f/k);
        s += term;
        k++;
    } while (fabsf(term) > eps && k < 100000000);
    return s;
}


float y_pred(float eps) {
    float H = 0.0f, prev = 0.0f, curr = 0.0f;
    for (int n = 1; n < 100000000; ++n) {
        H += 1.0f / n;
        curr = H - logf((float)n);
        if (fabsf(curr - prev) < eps) return curr;
        prev = curr;
    }
    return curr;
}

float y_yr(float eps) {
    float H = 0.0f, prev = 0.0f, curr = 0.0f;
    for (int n = 1; n < 100000000; ++n) {
        H += 1.0f / n;
        curr = H - logf((float)n);
        if (fabsf(curr - prev) < eps) return curr;
        prev = curr;
    }
    return curr;
}
