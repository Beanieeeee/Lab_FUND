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

    float e1 = e_sum(eps);
    float e2 = e_pred(eps);
    float e3 = e_yr(eps);

    float e1 = ln_sum(eps);
    float e2 = ln_pred(eps);
    float e3 = ln_yr(eps);

    float e1 = sq_sum(eps);
    float e2 = sq_pred(eps);
    float e3 = e_yr(eps);

     float e1 = ln_sum(eps);
    float e2 = e_pred(eps);
    float e3 = e_yr(eps);

    printf("\nРезультаты вычисления числа e:\n");
    printf("Метод ряда:        %.8f\n", e1);
    printf("Метод предела:     %.8f\n", e2);
    printf("Метод уравнения:   %.8f\n", e3);
    printf("Эталон (math.h):   %.8f\n", expf(1.0f));

    return 0;
}