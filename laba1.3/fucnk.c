// int maax(int a, int b){
//     int m;
//     if (a <= b){
//         m = b;
//     }
//     else{
//         m = a;
//     }
//     return m;
// }
#include "funck.h"

void krat(int a, int b){
    if (a == 0 && b == 0){
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

void tri(float eps, int a, int b, int c){
    int w;
    if (a <= 0 && b <= 0 && c <= 0){
        printf("ERROR");
        return;
    }

    if ((a * a + b * b - c * c) > eps || (a * a - b * b + c * c) > eps || (-a * a + b * b + c * c) > eps){
        printf("No");
    }
    else{
        printf("Yes");
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


void sraw(float eps, float a, float b, float c){
    float arr[3] = {a, b, c};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int t = 0; t < 3; t++){
                if (i != j && j != t && i != t){
                    float D = arr[j]*arr[j] - 4.0 * arr[i]*arr[t];
                    if (D < -eps) {
                        printf("NO\n");
                    } else {
                        float x1 = (-arr[j] + sqrtf(D) ) / (2 * arr[i]);
                        float x2 = (-arr[j] - sqrtf(D) ) / (2 * arr[i]);
                        printf("%f, %f\n", x1, x2);
                    }
                }
            }
        }
    }
}
