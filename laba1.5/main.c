#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "func.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("ERROR\n");
        return 1;
    }

    char *flag = argv[1];
    int with_n = (flag[1] == 'n'); 
    char a = flag[1 + with_n];

    char *input = argv[2];
    char output_name[256];
    char *output;

    if (with_n) {
        if (argc < 4) {
            printf("Не указан выходной файл!\n");
            return 1;
        }
        output = argv[3];
    } else {
        snprintf(output_name, sizeof(output_name), "out_%s", input);
        output = output_name;
    }

    FILE *in = fopen(input, "r");
    if (!in) {
        perror("Ошибка открытия входного файла");
        return 1;
    }

    FILE *f = fopen(output, "r");
    if (f) {
        int c; 
        int count = 0;

        while ((c = fgetc(f)) != EOF) {
            count++;
            break;
        }

        fclose(f);

        if (count == 0)
            printf("Файл пуст\n");
        else
            printf("Файл не пуст\n");
    }


    FILE *out = fopen(output, "w");
    if (!out) {
        perror("Ошибка открытия выходного файла");
        fclose(in);
        return 1;
    }

    switch (a) {
        case 'd': op_a(in, out); break;  
        case 'i': op_b(in, out); break;   
        case 's': op_c(in, out); break;   
        case 'a': op_d(in, out); break;   
        default:
            printf("Неизвестный флаг!\n");
            fclose(in);
            fclose(out);
            return 1;
    }

    fclose(in);
    fclose(out);

    printf("Готово! Результат записан в %s\n", output);
    return 0;
}
