#include "fucnk.h"
#include <stdio.h>
#include <math.h>

void krat(int a, int b){
    if (a == 0 || b == 0){
        printf("ERROR");
        return;
    }
    if (a % b == 0){
        printf("%d кратно %d ", a, b);
    }
    else{
        printf("%d не кратно  %d ", a, b);
    }
}

void tri(float eps, float a, float b, float c){
    int w;
    if (a <= 0 || b <= 0 || c <= 0){
        printf("ERROR\n");
        return;
    }

    if (fabsf(a * a + b * b - c * c) <= eps ||
        fabsf(a * a + c * c - b * b) <= eps ||
        fabsf(b * b + c * c - a * a) <= eps) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

void sraw(float eps, float a, float b, float c) {
    float arr[3] = { a, b, c };

    int num = 1;  
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int t = 0; t < 3; t++) {
                if (i != j && j != t && i != t) {
                    float A = arr[i], B = arr[j], C = arr[t];

                    if (fabsf(A) <= eps) {             // линейный/вырождённый случай
                        if (fabsf(B) <= eps) {
                            if (fabsf(C) <= eps)
                                printf("Уравнение номер %d: тождество (беск. много решений)\n", num++);
                            else
                                printf("Уравнение номер %d: вырождено (решений нет)\n", num++);
                        } else {
                            float x = -C / B;
                            printf("Уравнение номер %d: линейный корень x = %.10g\n", num++, x);
                        }
                        continue;
                    }

                    float D = B*B - 4.0f*A*C;

                    if (D > eps) {
                        float sqrtD = sqrtf(D);
                        float x1 = (-B + sqrtD) / (2.0f * A);
                        float x2 = (-B - sqrtD) / (2.0f * A);
                        printf("Уравнение номер %d: два корня x1 = %.10g, x2 = %.10g\n", num++, x1, x2);
                    } else if (fabsf(D) <= eps) {
                        float x = -B / (2.0f * A);
                        printf("Уравнение номер %d: кратный корень x = %.10g\n", num++, x);
                    } else {
                        printf("Уравнение номер %d: действительных корней нет\n", num++);
                    }
                }
            }
        }
    }
}

