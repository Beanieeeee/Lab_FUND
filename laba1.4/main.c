#include "func.h" 

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         printf("ERROR");
//         return 1;
//     }
//     double eps = atof(argv[1]);  
//     return 0;
// }





int main(void) {
    float eps;

    printf("Введите точность eps: ");
    scanf("%f", &eps);

    if (eps <= 0.0f || eps >= 1.0f) {
    printf("Не тот эпсилон\n");
    return 1;
    }


    float e1 = e_sum(eps);
    float e2 = e_pred(eps);
    float e3 = e_yr(eps);

    float p1 = pi_sum(eps);
    float p2 = pi_pred(eps);
    float p3 = pi_yr(eps);

    float ln1 = ln_sum(eps);
    float ln2 = ln_pred(eps);
    float ln3 = ln_yr(eps);

    float sq1 = sq_sum(eps);
    float sq2 = sq_pred(eps);
    float sq3 = sq_yr(eps);

    float y1 = y_sum(eps);
    float y2 = y_pred(eps);
    float y3 = y_yr(eps);

    printf("\nРезультаты вычисления числа e:\n");
    printf("Метод ряда:        %.8f\n", e1);
    printf("Метод предела:     %.8f\n", e2);
    printf("Метод уравнения:   %.8f\n", e3);
    printf("Эталон:   %.8f\n", expf(1.0f));

    printf("\nРезультаты вычисления числа π:\n");
    printf("Метод ряда:        %.8f\n", p1);
    printf("Метод предела:     %.8f\n", p2);
    printf("Метод уравнения:   %.8f\n", p3);
    printf("Эталон:   %.8f\n", 3.1415927f);

    printf("\nРезультаты вычисления числа ln(2):\n");
    printf("Метод ряда:        %.8f\n", ln1);
    printf("Метод предела:     %.8f\n", ln2);
    printf("Метод уравнения:   %.8f\n", ln3);
    printf("Эталон:   %.8f\n", logf(2.0f));

    printf("\nРезультаты вычисления числа √2:\n");
    printf("Метод ряда:        %.8f\n", sq1);
    printf("Метод предела:     %.8f\n", sq2);
    printf("Метод уравнения:   %.8f\n", sq3);
    printf("Эталон:   %.8f\n", sqrtf(2.0f));

    printf("\nРезультаты вычисления постоянной γ (Эйлера–Маскерони):\n");
    printf("Метод ряда:        %.8f\n", y1);
    printf("Метод предела:     %.8f\n", y2);
    printf("Метод уравнения:   %.8f\n", y3);
    printf("Эталон (справ.):   %.8f\n", 0.57721566f);

    return 0;
}