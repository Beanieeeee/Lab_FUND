#include "func.h"
int char_val(char c){
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

int max_ss(char *num){
    int b = 1;
    for (int i = 0; num[i] != '\0'; i++){
        if (char_val(num[i]) >= b){
            b = char_val(num[i]);
        }
    }
    return b + 1;
}

long long ss_to_dec(char *num, int base){
    long long val = 0;
    if (num[0] == '-' ){
        num++;
    }
    for (int i = 0; num[i] != '\0'; i++){
        if (char_val(num[i]) < 0 || char_val(num[i]) >= base){
            return -1;
        }
        val = val * base + char_val(num[i]);
    }
    return val;

}


void dec_to_base(long long n, int base, char *out) {
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[100];
    int i = 0, neg = 0;

    while (n > 0) {
        buf[i++] = digits[n % base];
        n /= base;
    }
    buf[i] = '\0';

    for (int j = 0; j < i; j++) {
        out[j] = buf[i - j - 1];
    }
    out[i] = '\0';
}