#include "func.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("ERROR\n");
        return 1;
    }

    char *in = argv[1];
    char *out = argv[2];


    FILE *in = fopen(input, "r");
    if (!in) {
        perror("Ошибка открытия входного файла");
        return 1;
    }

    FILE *out = fopen(input, "w");
    if (!in) {
        perror("Ошибка открытия выходного файла");
        return 1;
    }

    char num[100];
    
    while (fscanf(in, "%99s", num) == 1) {
        int base = max_ss(num);
        long long val = ss_to_dec(num, base);
        fprintf(fout, "%s %d %lld\n", num, base, val);
    }



    fclose(in);
    fclose(out);

    printf("Готово! Результат записан в %s\n", out);
    return 0;
}
