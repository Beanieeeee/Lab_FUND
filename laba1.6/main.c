#include "func.h" 

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ERROR");
        return 1;
    }
    double eps = atof(argv[1]);
    double a = 0.0, b = 1.0;

    printf("I1 = %.10f\n", trapezoid(f1, 0.0, 1.0, eps));
    printf("I2 = %.10f\n", trapezoid(f2, 0.0, 1.0, eps));
    printf("I3 = %.10f\n", trapezoid(f3, 0.0, 1.0, eps));
    printf("I4 = %.10f\n", trapezoid(f4, 0.0, 1.0, eps));
    
    return 0;
}