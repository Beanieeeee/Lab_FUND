#include "func.h"

int found_max(int a[], int size){
    int res = a[0];
    for (int i = 1; i < size; i++){
        if (res < a[i]){
            res = a[i];
        }
    }
    return res;
}


int check_prost_or_not(int a[], int n_max) {
    int c = 0;
    int x = 2;

    while (c < n_max) {
        if (is_prime(x)) {
            a[c] = x;
            c++;
        }
        x++;
    }
}

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void print_num(int a[], int b[], int b_max){
    for (int i = 0; i < b_max; i++){
        int b_num = b[i];
        int a_num = a[b_num - 1];
        printf("Номер запроса: %d, номер числа: %d, число: %d\n", i + 1, b_num, a_num);
    }
}