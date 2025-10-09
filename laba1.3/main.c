#include "fucnk.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: not enough arguments\n");
        return 1;
    }

    char *flag = argv[1];

    if (flag[0] != '-' && flag[0] != '/') {
        printf("Error: flag should start with '-' or '/'\n");
        return 1;
    }

    switch (flag[1]) {
        case 'q': {
            if (argc != 6) {
                printf("ERROR\n");
                return 1;
            }

            if (strlen(argv[2]) > 10 || strlen(argv[3]) > 10 || strlen(argv[4]) > 10 ||strlen(argv[5]) > 10) {
                printf("To much to float\n");
                return 1;
            }

            float eps = strtof(argv[2], NULL);
            float a   = strtof(argv[3], NULL);
            float b   = strtof(argv[4], NULL);
            float c   = strtof(argv[5], NULL);

            sraw(eps, a, b, c);
            break;
        }

        case 'm': {
            if (argc != 4) {
                printf("ERROR\n");
                return 1;
            }
            if (strlen(argv[2]) > 10 || strlen(argv[3]) > 10) {
                printf("To much to float\n");
                return 1;
            }
            int x = atoi(argv[2]);
            int y = atoi(argv[3]);

            krat(x, y);
            break;
        }

        case 't': {
            if (argc != 6) {
                printf("ERROR\n");
                return 1;
            }

            if (strlen(argv[2]) > 10 || strlen(argv[3]) > 10 || strlen(argv[4]) > 10 ||strlen(argv[5]) > 10) {
                printf("To much to float\n");
                return 1;
            }

            float eps = strtof(argv[2], NULL);
            float w   = strtof(argv[3], NULL);
            float v   = strtof(argv[4], NULL);
            float z   = strtof(argv[5], NULL);

            tri(eps, w, v, z);
            break;
        }

        default:
            printf("Error: unknown flag '%c'\n", flag[1]);
            return 1;
    }

    return 0;
}
