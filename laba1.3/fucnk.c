#include "fucnk.h"

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

// void sraw(float eps, float a, float b, float c){
//     float arr[3] = {a , b, c};
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++ ){
//             for (int t = 0; t < 3; t++ ){
//                 if (arr[i] != arr[t] && arr[j] != arr[t] && arr[i] != arr[j]){
//                     if ((arr[j] * arr[j] - 4 * arr[i] * arr[t]) < eps){
//                         printf("NO");
//                     }
//                     else{
//                         printf("Yes");
//                     }
//                 }
//             }

//         }
//     }

// }


// void sraw(float eps, float a, float b, float c){
//     float arr[3] = {a, b, c};
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             for (int t = 0; t < 3; t++){
//                 if (i != j && j != t && i != t){
//                     float D = arr[j]*arr[j] - 4.0 * arr[i]*arr[t];
//                     if (D < -eps) {
//                         printf("NO\n");
//                     } else if (fabsf(D) <= eps)
//                     {
//                         float x = (-arr[j]) / (2.0 * arr[i]);
//                         printf("%f/n", x);
//                     }
                    
                    
//                     else {
//                         float x1 = (-arr[j] + sqrtf(D) ) / (2.0 * arr[i]);
//                         float x2 = (-arr[j] - sqrtf(D) ) / (2.0 * arr[i]);
//                         printf("%f, %f\n", x1, x2);
//                     }
//                 }
//             }
//         }
//     }
// }
#include <stdio.h>
#include <math.h>


void sraw(float eps, float a, float b, float c){
    float arr[3] = {a, b, c};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int t = 0; t < 3; t++){
                if (i != j && j != t && i != t){
                    float A = arr[i], B = arr[j], C = arr[t];

                    if (fabsf(A) <= eps){
                        if (fabsf(B) <= eps){
                            if (fabsf(C) <= eps) printf("any x\n");
                            else                 printf("no solutions\n");
                        } else {
                            printf("x = %.6g\n", -C/B);
                        }
                        continue;
                    }

                    float D = B*B - 4.0f*A*C;

                    if (D < -eps) {
                        printf("no real roots\n");
                    } else if (fabsf(D) <= eps) {
                        float x = (-B) / (2.0f*A);
                        printf("x = %.6g\n", x);
                    } else {
                        float s = sqrtf(D);
                        float x1 = (-B + s) / (2.0f*A);
                        float x2 = (-B - s) / (2.0f*A);
                        printf("x1 = %.6g, x2 = %.6g\n", x1, x2);
                    }
                }
            }
        }
    }
}
