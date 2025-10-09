#include "func.h"

int num(char c) {
    return (c >= '0' && c <= '9');
}

int latin(char c) {
    return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}

int space(char c) {
    return (c == ' ' || c == '\t');
}

void op_a(FILE *in, FILE *out) {
    int c;
    while ((c = fgetc(in)) != EOF) {     
        if (!num(c))                 
            fputc(c, out);               
    }
}

void op_b(FILE *in, FILE *out) {
    char line[1024];
    while (fgets(line, sizeof(line), in)) {
        int cnt = 0;
        for (int i = 0; line[i]; i++) {
            if (latin(line[i])) cnt++;
        }
        fprintf(out, "%d\n", cnt);
    }
}

void op_c(FILE *in, FILE *out) {
    char line[1024];
    while (fgets(line, sizeof(line), in)) {
        int cnt = 0;
        for (int i = 0; line[i]; i++) {
            char c = line[i];
            if (c == '\n') continue;
            if (!latin(c) && !num(c) && !space(c)) cnt++;
        }
        fprintf(out, "%d\n", cnt);
    }
}

void op_d(FILE *in, FILE *out){
    int c;
    while ((c = fgetc(in)) != EOF){
        if (!num(c)) {
            fprintf(out, "%02X ", c);
        }
    }
    fputc('\n', out);
}
