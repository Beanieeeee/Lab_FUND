#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int base;
    printf("Введите основание системы счисления (2..36): ");
    scanf("%d", &base);
    if (base < 2 || base > 36){
        printf("Основание сс должно быть в диапазоне 2...36");
        return 1;
    };

    char min = ' ';
    long long max_val = 0, val;
    char num[100], max_str[100];
    printf("Вводите числа (Stop для завершения):\n");
    scanf("%99s", num);
    while (strcmp(num, "Stop") != 0) {

        if (num[0] == '-'){
            min = '-';
            if (strlen(num) > 11){
                printf("Слишком много для инта\n");
                return 1;
            }
        }
        else{
            if (strlen(num) > 11){
                printf("Слишком много для инта\n");
                return 1;
        }}

        val = ss_to_dec(num, base);
        if (llabs(val) > llabs(max_val)) {
            max_val = val;
            strcpy(max_str, num);
        }
        scanf("%99s", num);
    }


    printf("Максимальное по модулю число: %s\n", max_str);
    printf("В 9, 18, 27, 36 системах:\n");
    int b[] = {9, 18, 27, 36};
    for (int i = 0; i < 4; i++) {
        char buf[100];
        dec_to_base(max_val, b[i], buf);
        printf("base %d: %c%s\n", b[i], min, buf);
    }
    printf("В десятичной сс %lld\n", max_val);


    return 0;

}