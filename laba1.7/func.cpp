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
    for (int i = 0; num[i] != '\0'; i++){
        if (char_val(num[i]) < 0 || char_val(num[i]) >= base){
            return -1;
        }
        val = val * base + char_val(num[i]);
    }
    return val;

}