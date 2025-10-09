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
    for (int k = 0; k < 100; ++k) {
        float x_new = x * (2.0f - logf(x));    
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new)))
            return x_new;
        x = x_new;
    }
    return x;
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

float sq_sum(float eps){
    float sq = 0.0f; 
    int k = 2;
    float t;
    do {
        t = powf(2, powf(2, -k));
        sq *= t;
        k++;
    } while (fabsf(t) > eps && k < 10000000);
    return sq;
}

float y_sum(float eps){
    float y = 0.0f; 
    int k = 2;
    float t;
    do {
        t = (1 / pow(sqrtf(k), 2) - 1 / k );
        sq += t;
        k++;
    } while (fabsf(t) > eps && k < 10000000);
    return y - 3.1415927f / 6 ;
}


float pi_yr(float eps) {
    float x = 3.0f;
    for (int k = 0; k < 100; ++k) {
        float x_new = x - ((cos(x) + 1.0f) / -sin(x));    
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new)))
            return x_new;
        x = x_new;
    }
    return x;
}

float ln_yr(float eps) {
    float x = 2.0f;
    for (int k = 0; k < 100; ++k) {
        float x_new = x - (expf(x) - 2)/expf(x);    
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new)))
            return x_new;
        x = x_new;
    }
    return x;
}

float sq_yr(float eps) {
    float x = 1.0f;
    for (int k = 0; k < 100; ++k) {
        float x_new = x - (pow(x, 2) - 2.0f)/2.0f * x;    
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new)))
            return x_new;
        x = x_new;
    }
    return x;
}

float y_yr(float eps) {
    float x = 1.0f;
    for (int k = 0; k < 100; ++k) {
        float x_new = x - (pow(x, 2) - 2)/2 * x;    
        if (fabsf(x_new - x) <= eps * fmaxf(1.0f, fabsf(x_new)))
            return x_new;
        x = x_new;
    }
    return x;
}