#include <stdio.h>
#include <stdlib.h>

int main(){
    char *arr = NULL;
    char num;
    int size = 0;

    printf("Введите значения (Stop чтобы закончить):\n");

    while (scanf("%c", &num) == 1) {

        if (num == 'Stop') break;

        char *tmp = realloc(arr, (size + 1) * sizeof(char));
        if (!tmp) {
            free(arr);
            printf("Ошибка выделения памяти\n");
            return 1;
        }
        arr = tmp;
        arr[size++] = num;
    }
    arr = realloc(arr, size + 1);
    arr[size] = '\0';
    int SS = atoi(arr[0]);

    if (SS < 2 || SS > 36){
        printf("no");
        return 1;
    }
    
    long rez[size - 1];
    for (int i = 1; i < size; i ++){
        int e = 0;
        e = per(arr[i]);
        rez[i - 1] = e;
    }


}